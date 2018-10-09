/*
 * Hedging.h
 *
 *  Created on: Oct 8, 2018
 *      Author: oliv
 */

#ifndef HEDGING_H_
#define HEDGING_H_

#include "euCall.h"
#include "vecSpace.h"
#include "Ndist.h"
#include "math.h"
#include "vfun.h"

namespace vSpace {

class Hedging: public vSpace::euCall {
public:
	Hedging(euCall C,vfun & BS,realSpace HedgingTimes, bool display = true);
	virtual ~Hedging();

	const arma::vec& getB() const {
		return B;
	}

	const arma::vec& getTheta() const {
		return thetaV;
	}

	const arma::vec& getValue() const {
		return value;
	}

	const realSpace& getHedgingTimes() const {
		return HedgingTimes;
	}

	const vfun& getStock() const {
		return Stock;
	}

private :
	realSpace HedgingTimes;
	int n;
	arma::vec B;
	arma::vec thetaV;
	arma::vec value;
	vfun & Stock;

};

} /* namespace vSpace */

#endif /* HEDGING_H_ */
