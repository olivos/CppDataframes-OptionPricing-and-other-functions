/*
 * fun.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */
#include "fun.h"

namespace vSpace {



fun::fun(vecSpace E, double (&f)(double)): function(E),f(f)
{
}

fun::~fun() {
	// TODO Auto-generated destructor stub
}

double fun::operator ()(double x) {
	return f(x);
}

arma::vec fun::diff(){
	int nx = sizes(0);
	double hx = deltas(0);

	arma::vec V = arma::vec(nx+1);
	V(0)= (f(X(1))-f(X(0)))/hx;
	for(int i = 1 ; i < nx; i++){
		V(i) = (f(X(i+1))-f(X(i-1)))/(2*hx);
	}

	V(nx)= (f(X(nx))-f(X(nx-1)))/hx;

	return V;
}


} /* namespace vSpace */
