/*
 * stoch.cpp
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#include "stoch.h"

using namespace arma;

namespace vSpace {

stoch::stoch() {
	// TODO Auto-generated constructor stub

}

vec stoch::E(stochastic& Xt) {
	realSpace T = Xt.getX();
	int nt = T.getNx();
	int nb = Xt.getNb();
	vec res = vec(nt+1,fill::zeros);

	for( int j = 0 ; j < nt +1 ; j++){
		for (int i = 0 ; i < nb ; i++){
			res(j) += Xt(T(j),i);
		}
	}
	return res;
}



stoch::~stoch() {
	// TODO Auto-generated destructor stub
}


} /* namespace vSpace */


