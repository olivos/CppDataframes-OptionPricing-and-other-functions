/*
 * Eucall.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#include "Eucall.h"
using namespace arma;

namespace vSpace {

//Eucall::Eucall():Option(),sigma(0) {
//	// TODO Auto-generated constructor stub
//
//}

Eucall::Eucall(const fonction& S, const double& K, const double& r, const double& sigma, const double& q):Option(S,K,r),sigma(sigma),q(q) {
}

Eucall::~Eucall() {
	// TODO Auto-generated destructor stub
}

double Eucall::operator ()(const double& t) const{
	return exp(-q*(T-t))*S(t)* normcdf(d1(t)) - exp(-r*(T-t)) * K * normcdf(d2(t))  ;
}

double Eucall::vol(const double& t) const {
	return sigma;
}

double Eucall::delta(const double& t) const {
	return exp(-q*(T-t))*normcdf(d1(t));
}

} /* namespace vSpace */
