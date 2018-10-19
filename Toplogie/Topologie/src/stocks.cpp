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
stocks::stocks(std::string filename,std::string filenameV, int nbStocks, int nbLines, int nbLinesVol):nbStocks(nbStocks) {
	days = (nbLines)/nbStocks;

	ifstream ip(filename);

	data = mat(3,nbStocks);
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
	}
//	remaining rows : only get the stock price
	for(int d = 1; d < days; d++){
		for(int s  = 0; s < nbStocks ; s++){
			for(int j = 0; j < 2; j++){
				getline(ip,temp,',');
			}
			getline(ip,temp,'\n');
			Prices(d,s) =stod(temp);
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

} /* namespace vSpace */
