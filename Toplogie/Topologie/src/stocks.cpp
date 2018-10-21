/*
 * stocks.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: oliv
 */

#include "stocks.h"

using namespace std;
using namespace arma;

namespace vSpace {

class ConvError
{
public :
	ConvError(string s): line(s){ }
	string getErr() const {
		return line;
	}
private :
	string line;
};

double stodd(string& s){
	try{
		return stod(s);
	}
	catch(const std::invalid_argument& ia){
		throw ConvError(s);
	}
}


// use ticker in ascending order when querrying.
stocks::stocks(std::string filename,std::string filenameV, int nbStocks, int nbLines, int nbLinesVol,
double r):nbStocks(nbStocks),r(r) {

	try{ /* used to spot conversion errors when reading the csv */

	days = (nbLines)/nbStocks;
	double dDays = days;
	T = realSpace(0,dDays/250,days-1);

	ifstream ip(filename);

	data = mat(5,nbStocks);
	Prices = mat(days,nbStocks);

	string temp;

//	discard the row with titles
	for(int j = 0; j < 2; j++){
		getline(ip,temp,',');
	}
	getline(ip,temp,'\n');
//	special treatment for 1st d rows to get the secID
	for(int s  = 0; s < nbStocks ; s++){
		getline(ip,temp,',');

		data(0,s) = stodd(temp);
		getline(ip,temp,',');


		getline(ip,temp,'\n');
		Prices(0,s) =stodd(temp);
		data(3,s) = stodd(temp); /* min val */
		data(4,s) = stodd(temp); /* max val*/
	}
//	remaining rows : only search min/max price
	for(int d = 1; d < days; d++){
		for(int s  = 0; s < nbStocks ; s++){
			for(int j = 0; j < 2; j++){
				getline(ip,temp,',');
			}
			getline(ip,temp,'\n');
			Prices(d,s) =stodd(temp);
//			min
			if(stodd(temp) < data(3,s)){
				data(3,s)  = stodd(temp);
			}
//			max
			if(stodd(temp) > data(4,s)){
				data(4,s)  = stodd(temp);
			}
		}
	}
	ip.close();

//	Importing volatily and strike prices : we look for the strike closest to current price

	ifstream iv(filenameV);

	for(int s = 0; s < nbStocks ; s++){
		data(1,s) = 0;
	}
	double tempV;
	double tempK = 0;

	for(int j = 0 ; j < 6 ; j++){
		getline(iv,temp,',');

	}
	getline(iv,temp,'\n');


	for(int s = 0 ; s < nbStocks; s++){
		for(int i = 0 ; i < nbLinesVol ; i++){
			for(int j = 0 ; j < 3 ; j++){
				getline(iv,temp,',');

			}
			getline(iv,temp,',');
			tempV = stodd(temp);

			getline(iv,temp,',');
			tempK = stodd(temp);

//			find the most at the money strike vol couple
			if(abs(tempK - Prices(0,s)) < abs(data(1,s) - Prices(0,s)) ){
				data(1,s) = tempK;
				data(2,s) = tempV;
			}

			for(int j = 0 ; j < 1 ; j++){
				getline(iv,temp,',');
			}
		}
	}
	iv.close();

	}
	catch(ConvError& c){
		cout << "stod conversion error at line";
		cout << c.getErr();
		throw c.getErr();
	}

}

stocks::~stocks() {
	// TODO Auto-generated destructor stub
}



std::vector<euCall> stocks::gen_calls() {
	vector<euCall> res(nbStocks);
	for(int s = 0 ; s < nbStocks ; s++){
		res[s] = euCall(T,realSpace(data(3,s), data(4,s),nX),data(2,s),r,data(1,s) );
	}
	return res;
}
std::vector<EuPut> stocks::gen_puts() {
	vector<EuPut> res(nbStocks);
	for(int s = 0 ; s < nbStocks ; s++){
		res[s] = EuPut(T,realSpace(data(3,s), data(4,s),nX),data(2,s),r,data(1,s) );
	}
	return res;
}

std::vector<Vhedging> stocks::hedge( bool disp) {
	vector<euCall> calls = gen_calls();
	vector<Vhedging> res(nbStocks);

	for(int s = 0 ; s < nbStocks ; s++){
			cout << "Strike is" << data(1,s) << "IV is" << data(2,s)<< "\n";

		res[s] = Vhedging(calls[s], Prices, s, disp );

	}
	return res;

}

std::vector<VPuthedging> stocks::hedgePut( bool disp) {
	vector<EuPut> puts = gen_puts();
	vector<VPuthedging> res(nbStocks);
	double avgGainLoss = 0;
	for(int s = 0 ; s < nbStocks ; s++){
			cout << "Strike is" << data(1,s) << "IV is" << data(2,s)<< "\n";

		res[s] = VPuthedging(puts[s], Prices, s, disp );
		avgGainLoss = avgGainLoss + abs((res[s].getB())(days-1)/Prices(0,s));
	}
	cout << avgGainLoss/nbStocks << "\n";
	return res;

}

} /* namespace vSpace */
