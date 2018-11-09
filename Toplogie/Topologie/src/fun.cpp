/*
 * fun.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */
#include "fun.h"

namespace vSpace {

double identity (double x){
	return x;
}

fun::fun(): function(vecSpace()),f(identity) {}

fun::fun(const vecSpace& E, double (&f)(double)): function(E),f(f)
{
}

fun::~fun() {
	// TODO Auto-generated destructor stub
}

double fun::operator ()(const double& x) {
	return f(x);
}




} /* namespace vSpace */
