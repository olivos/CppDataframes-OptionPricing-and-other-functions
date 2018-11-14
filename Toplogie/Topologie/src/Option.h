/*
 * Option.h
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#ifndef OPTION_H_
#define OPTION_H_

#include "vecSpace.h"
#include "fun.h"

namespace vSpace {

class Option: public fonction {
public:
	Option();
//	fonction S represents the price fonction over time, K is the strike price
	Option(const fonction& S, const double& K, const double& r );
	virtual ~Option();
//	value of the option at time t
	virtual double operator() (const double& t) const= 0;
	virtual double vol(const double& t) const = 0;
	virtual double delta(const double& t) const = 0;
	void hedging(arma::vec & B , const bool& display = true);

protected:
	const fonction& S;
	const double K;
	const double r;
	double T;


};

} /* namespace vSpace */

#endif /* OPTION_H_ */
