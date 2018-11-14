/*
 * Option.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#include "Option.h"

namespace vSpace {

Option::Option():fonction(),S(fun()),K(0),T(0),r(0) {
	// TODO Auto-generated constructor stub

}

Option::Option(const fonction& S, const double& K,const double& r):fonction(S),S(S),K(K),r(r){
	T = final(0);
}

Option::~Option() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */
