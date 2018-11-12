/*
 * stochastic.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: oliv
 */

#include "stochastic.h"

namespace vSpace {

stochastic::stochastic():nb(0) {
	// TODO Auto-generated constructor stub

}

stochastic::~stochastic() {
	// TODO Auto-generated destructor stub
}
vSpace::stochastic::stochastic(vecSpace E) : function(E),nb(1){
}
vSpace::stochastic::stochastic(vecSpace E, int nb) : function(E),nb(nb) {
}
double vSpace::stochastic::operator ()(double x, int ligne) {
	std::cout << "() used for stochastic!!";
	return 1;
}
double stochastic::operator () (double t){
	return stochastic::operator ()(t, 0) ;
}


} /* namespace vSpace */


