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

// use ticker in ascending order when querrying.
stocks::stocks(std::string filename,std::string filenameV, int nbStocks, int nbLines, int nbLinesVol,
double r):nbStocks(nbStocks),r(r) {
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

		data(0,s) = stod(temp);
		getline(ip,temp,',');


		getline(ip,temp,'\n');
		Prices(0,s) =stod(temp);
		data(3,s) = stod(temp); /* min val */
		data(4,s) = stod(temp); /* max val*/
	}
//	remaining rows : only get the stock price
	for(int d = 1; d < days; d++){
		for(int s  = 0; s < nbStocks ; s++){
			for(int j = 0; j < 2; j++){
				getline(ip,temp,',');
			}
			getline(ip,temp,'\n');
			Prices(d,s) =stod(temp);
//			min
			if(stod(temp) < data(3,s)){
				data(3,s)  = stod(temp);
			}
//			max
			if(stod(temp) > data(4,s)){
				data(4,s)  = stod(temp);
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
			tempV = stod(temp);

			getline(iv,temp,',');
			tempK = stod(temp);

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

std::vector<Vhedging> stocks::hedge( bool disp) {
	vector<euCall> calls = gen_calls();
	vector<Vhedging> res(nbStocks);

	for(int s = 0 ; s < nbStocks ; s++){
		cout << "Strike is" << data(1,s) << "IV is" << data(2,s)<< "\n";
		res[s] = Vhedging(calls[s], Prices, s, disp );

	}
	return res;

}

} /* namespace vSpace */
