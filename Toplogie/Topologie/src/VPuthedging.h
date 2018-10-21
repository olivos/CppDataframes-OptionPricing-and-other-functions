/*
 * VPuthedging.h
 *
 *  Created on: Oct 20, 2018
 *      Author: oliv
 */

#ifndef VPUTHEDGING_H_
#define VPUTHEDGING_H_

#include "EuPut.h"

namespace vSpace {

class VPuthedging : public EuPut {
public:
	VPuthedging();
	VPuthedging(EuPut C,arma::mat& Stock, int s, bool display = true);

	virtual ~VPuthedging();

	const arma::vec& getB() const {
		return B;
	}

	const arma::vec& getDelta() const {
		return thetaV;
	}

	const arma::vec& getValue() const {
		return value;
	}

	const realSpace& getHedgingTimes() const {
		return HedgingTimes;
	}


private :
	realSpace HedgingTimes;
	arma::vec B;
	arma::vec thetaV;
	arma::vec value;
};

} /* namespace vSpace */

#endif /* VPUTHEDGING_H_ */
