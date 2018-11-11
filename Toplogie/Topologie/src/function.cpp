/*
 * function.cpp
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#include "function.h"

namespace vSpace {

function::function() {
	// TODO Auto-generated constructor stub

}

function::function(const vecSpace& E) : vecSpace(E) {}

double function::operator ()(const double& x) {
	std::cerr << "uses abstract class function!!;";
			return -1;
}



function::~function() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */

