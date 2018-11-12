/*
 * Ndist.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: oliv
 */

#include "Ndist.h"

namespace vSpace {

Ndist::Ndist(int n ): function(realSpace(-10,10,n)),n(n) {
	// TODO Auto-generated constructor stub

	int nx = X.getNx();
	double hx = X.getHx();

	N = arma::vec(nx+1);

	N(0)= 0;

	for(int i = 1 ; i < nx+1; i++){
		N(i) = (f(X(i))-f(X(i-1)))*hx/2 + f(X(i-1))*hx + N(i-1);
	}
}

Ndist::~Ndist() {
	// TODO Auto-generated destructor stub
}

double Ndist::operator ()(const double& x) {
	if (x < - 10.){
		return 0;
	}
	if (x > 10.){
		return 1;
	}
	else {
	int i = (x - init(0))/deltas(0);
	return N(i);}
}

} /* namespace vSpace */
