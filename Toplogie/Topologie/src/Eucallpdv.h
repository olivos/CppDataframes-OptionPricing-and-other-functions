/*
 * Eucallpdv.h
 *
 *  Created on: Nov 15, 2018
 *      Author: oliv
 */

#ifndef EUCALLPDV_H_
#define EUCALLPDV_H_

#include "Option.h"
#include "func.h"

namespace vSpace {

class Eucallpdv final: public Option {
public:
	Eucallpdv(const fonction& S, const double& K, const double& r, const double& sigmaL,const double& sigmaH, const double& q = 0 , const int& memory = 30, const double& initAVG  = -1);
	~Eucallpdv();

	double operator() (const double& t) const;
	double vol(const double& t)const;
	double delta(const double& t) const;
	vfun volfun() const;
	vfun avgfun() const;

private :
	const double& sigmaL;
	const double& sigmaH;
	const double& q;
	const int memory;
	arma::vec sigma;
	arma::vec avg;
	arma::vec primSigma;
	void heuristic1();
//	double d2(const double& t) const{return ( log( exp(-q*(T-t))* S(t)/K) +( r-pow(vol(t),2)/2 )*(T-t) )/ (vol(t) * sqrt(T-t) );}
//	double d1(const double& t) const{return  d2(t) + vol(t)* sqrt(T-t);}
	double sigmaQ (const double & t) const; /* integral of sigma square between T and t */
	double d2(const double& t) const{return ( log( exp(-q*(T-t))* S(t)/K) +r*(T-t)- sigmaQ(t) /2 )/ (sqrt(sigmaQ(t))  );}
	double d1(const double& t) const{return d2(t)+sqrt(sigmaQ(t));}
};

} /* namespace vSpace */

#endif /* EUCALLPDV_H_ */
