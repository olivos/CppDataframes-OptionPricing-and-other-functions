/*
 * vfun.cpp
 *
 *  Created on: Jul 27, 2018
 *      Author: oliv
 */

#include "vfun.h"

namespace vSpace {
vfun::vfun():function(vecSpace()), M(arma::mat()) {
}

vfun::vfun(const vecSpace& E,const arma::mat&  M): function(E),M(M)  {
}

vfun::~vfun() {
	// TODO Auto-generated destructor stub
}

double vSpace::vfun::operator ()(const double& x) const {
		int i = (x-init(0))/deltas(0);
		return M(i);
}

double vSpace::vfun::operator ()(const double& x,const double& y) const{
	int i = (x-init(0))/deltas(0);
	int j = (y-init(1))/deltas(1);
	return M(i,j);
}


//arma::vec vSpace::vfun::diff() {
//	int nx = sizes(0);
//	double hx = deltas(0);
//
//	arma::vec V = arma::vec(nx+1);
//	V(0)= (M(1)-M(0))/hx;
//	for(int i = 1 ; i < nx; i++){
//		V(i) = (M(i+1)-M(i-1))/(2*hx);
//	}
//
//	V(nx)= (M(nx)-M(nx-1))/hx;
//	return V;
//}



} /* namespace vSpace */


