/*
 * VCallPDVHedging.h
 *
 *  Created on: Oct 23, 2018
 *      Author: oliv
 */

#ifndef VCALLPDVHEDGING_H_
#define VCALLPDVHEDGING_H_

#include "EuCallPDV.h"

namespace vSpace {

class VCallPDVhedging : public EuCallPDV {
public:
	VCallPDVhedging();
	VCallPDVhedging(EuCallPDV P,arma::mat& Stock, int s,bool display = true);
	virtual ~VCallPDVhedging();

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

	const arma::vec& getVol() const {
		return vol;
	}

private :
	realSpace HedgingTimes;
	arma::vec B;
	arma::vec thetaV;
	arma::vec value;
	int pathLength = 13;
	int upPathLength = 10;
	arma::vec vol;
};

} /* namespace vSpace */

#endif /* VCALLPDVHEDGING_H_ */
