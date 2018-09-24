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

realSpace::realSpace(double xi, double xf, int nx) : xi(xi),xf(xf),nx(nx){
	hx = (xf-xi)/nx;

}


realSpace::~realSpace() {
	// TODO Auto-generated destructor stub
}

double realSpace::operator ()(int n) {
	return xi + n*hx;
}



} /* namespace vSpace */
