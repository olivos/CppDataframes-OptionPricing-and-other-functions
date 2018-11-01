/*
 * VPutPDVhedging.h
 *
 *  Created on: Oct 21, 2018
 *      Author: oliv
 */

#ifndef VPUTPDVHEDGING_H_
#define VPUTPDVHEDGING_H_

#include "EuPutPDV.h"

namespace vSpace {

class VPutPDVhedging : public EuPutPDV {
public:
	VPutPDVhedging();
	VPutPDVhedging(EuPutPDV P,arma::mat& Stock, int s, bool display = true);
	virtual ~VPutPDVhedging();

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
	int pathLength = 22;
};

} /* namespace vSpace */

#endif /* VPUTPDVHEDGING_H_ */
