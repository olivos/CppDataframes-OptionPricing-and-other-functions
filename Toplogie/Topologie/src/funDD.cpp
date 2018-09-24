/*
 * funDD.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: oliv
 */

#include "funDD.h"

namespace vSpace {

funDD::funDD(vecSpace E,double (&f) (double x, double y)): function(E),f(f) {
	// TODO Auto-generated constructor stub

}

funDD::~funDD() {
	// TODO Auto-generated destructor stub
}

double funDD::operator ()(double x, double y) {
	return f(x,y);
}

} /* namespace vSpace */
