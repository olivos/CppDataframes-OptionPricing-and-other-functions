/*
 * Vhedging.h
 *
 *  Created on: Oct 20, 2018
 *      Author: oliv
 */

#ifndef VHEDGING_H_
#define VHEDGING_H_


#include "euCall.h"
#include "vecSpace.h"
#include "Ndist.h"
#include "math.h"
#include "vfun.h"


namespace vSpace {

class Vhedging: public vSpace::euCall {
public:
	Vhedging();
	Vhedging(euCall C,arma::mat& Stock, int s, bool display = true);
	virtual ~Vhedging();

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

#endif /* VHEDGING_H_ */
