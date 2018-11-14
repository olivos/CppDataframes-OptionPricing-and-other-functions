/*
 * Eucall.h
 *
 * European Call option priced with the Black Scholes model
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#ifndef EUCALL_H_
#define EUCALL_H_

#include "Option.h"
#include "math.h"
#include <armadillo>
namespace vSpace {

class Eucall: public Option {
public:
	Eucall();
	Eucall(const fonction& S, const double& K, const double& r, const double& sigma, const double& q = 0 );
	virtual ~Eucall();

	virtual double operator() (const double& t) const;
	virtual double vol(const double& t) const;
	virtual double delta(const double& t) const;

private :
	const double sigma;
	double q{0};
	double d2(const double& t) const{return ( log( exp(-q*(T-t))* S(t)/K) +( r-pow(sigma,2)/2 )*(T-t) )/ ( sigma * sqrt(T-t) );}
	double d1(const double& t) const{return  d2(t) + sigma* sqrt(T-t);}
};

} /* namespace vSpace */

#endif /* EUCALL_H_ */
