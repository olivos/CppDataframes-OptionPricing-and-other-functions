/*
 * bs.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: oliv
 */

#include "bs.h"

namespace vSpace {

bs::bs() {
	// TODO Auto-generated constructor stub

}


bs::bs(realSpace X,  double mu, double sigma, double S0,int nb): brw(X,nb),mu(mu),sigma(sigma),S0(S0) {
}

double bs::operator ()(double t, int ligne) {
	int n = t/deltas(0);
	return S0*exp((mu-sigma*sigma/2)*n*deltas(0) + sigma*Sn(ligne,n));
}

double bs::operator ()(double t) {
	return bs::operator ()(t, 0) ;
}

bs::~bs() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */
