/*
 * Euput.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: oliv
 */

#include "Euput.h"
using namespace arma;

namespace vSpace {

//Euput::Euput():Option(),sigma(0) {
//	// TODO Auto-generated constructor stub
//
//}

Euput::Euput(const fonction& S, const double& K, const double& r,
		const double& sigma, const double& q):Option(S,K,r),sigma(sigma),q(q) {

}

Euput::~Euput() {
	// TODO Auto-generated destructor stub
}

double Euput::operator ()(const double& t) const {
	return - exp(-q*(T-t))*S(t)* normcdf(-d1(t)) + exp(-r*(T-t)) * K * normcdf(-d2(t))  ;

}

double Euput::vol(const double& t) const{
	return sigma;
}

double Euput::delta(const double& t) const {
	return -exp(-q*(T-t))*normcdf(-d1(t));
}

} /* namespace vSpace */
