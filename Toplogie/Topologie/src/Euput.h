/*
 * Euput.h
 *
 *  Created on: Nov 13, 2018
 *      Author: oliv
 */

#ifndef EUPUT_H_
#define EUPUT_H_

#include "Option.h"

namespace vSpace {

class Euput: public Option {
public:
//	Euput();
	Euput(const fonction& S, const double& K, const double& r, const double& sigma, const double& q = 0 );
	virtual ~Euput();

	virtual double operator() (const double& t) const;
	virtual double vol(const double& t)const;
	virtual double delta(const double& t) const;
private :
	const double sigma;
	double q{0};
	double d2(const double& t) const{
		return ( log( exp(-q*(T-t))* S(t)/K)+( r-pow(sigma,2)/2 )*(T-t) )/ ( sigma * sqrt(T-t) );}
	double d1(const double& t) const{return  d2(t) + sigma* sqrt(T-t);}
};

} /* namespace vSpace */

#endif /* EUPUT_H_ */
