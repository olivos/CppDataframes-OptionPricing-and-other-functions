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

namespace vSpace {

class stocks {
public:
	stocks(std::string filename,std::string filenameV, int nbStocks, int nbLines, int nbLinesVol = 26);
	virtual ~stocks();

	const arma::mat& getPrices() const {
		return Prices;
	}

	const arma::mat& getData() const {
		return data;
	}

private:
	arma::mat Prices;/* one row vec for each stock containing its prices*/
	arma::mat data; /* row 0 sec id, row 1 strike prices, row 2 initial implied vols */
	int days; /* days to maturity */
	int nbStocks;
};

} /* namespace vSpace */

#endif /* STOCKS_H_ */
