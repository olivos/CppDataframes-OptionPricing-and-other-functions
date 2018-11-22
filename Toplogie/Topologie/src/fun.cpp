/*
 * fun.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */
#include "fun.h"

namespace vSpace {


//fun::fun(): fonction(vecSpace()),f(identity) {}

fun::fun(const vecSpace& E, double (&f)(const double&)): fonction(E),f(f)
{
}

fun::~fun() {
	// TODO Auto-generated destructor stub
}

double fun::operator ()(const double& x)const {
	return f(x);
}




} /* namespace vSpace */
