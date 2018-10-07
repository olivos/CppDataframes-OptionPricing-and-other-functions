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

function::function(vecSpace E) : vecSpace(E) {}

double function::operator ()(double x) {
	std::cout << "attention utilise operateur() de la classe function";
	return 1;
}



function::~function() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */

