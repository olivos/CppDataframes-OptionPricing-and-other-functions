/*
 * realSpace.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */

#include "realSpace.h"

namespace vSpace {

realSpace::realSpace() : xi(0),xf(0),nx(0),hx(0) {
	// TODO Auto-generated constructor stub

}

realSpace::realSpace(const double& xi,const double& xf,const int& nx) : xi(xi),xf(xf),nx(nx){
	hx = (xf-xi)/nx;

}


realSpace::~realSpace() {
	// TODO Auto-generated destructor stub
}

double realSpace::operator ()(int const& n) const {
	return xi + n*hx;
}



} /* namespace vSpace */
