/*
 * stocks.h
 *
 *  Created on: Oct 18, 2018
 *      Author: oliv
 */

#ifndef STOCKS_H_
#define STOCKS_H_

#include "vfun.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <armadillo>
#include "Hedging.h"
#include "euCall.h"
#include "Vhedging.h"

namespace vSpace {

class stocks {
public:
	stocks(std::string filename,std::string filenameV, int nbStocks, int nbLines, int nbLinesVol = 26, double r = 0.03);
	virtual ~stocks();

	const arma::mat& getPrices() const {
		return Prices;
	}

	const arma::mat& getData() const {
		return data;
	}
	std::vector<euCall> gen_calls(); /* returns a vector containing an atm european call for each stock*/

	std::vector<Vhedging> hedge( bool disp = false);

private:
	arma::mat Prices;/* one row vec for each stock containing its prices*/
	arma::mat data; /* row 0 sec id, row 1 strike prices, row 2 initial implied vols, row 3 minPrice, row 4 max Price */
	int days; /* days to maturity */
	int nbStocks;
	realSpace T;
	int nX = 100; /* Number of points used in the price realSpace*/
	double r; /* risk free interest rate*/

};

} /* namespace vSpace */

#endif /* STOCKS_H_ */
