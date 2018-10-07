/*
 * stoch.h
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef STOCH_H_
#define STOCH_H_

#include "vfun.h"
#include "brw.h"
#include <string>
#include "input.h"
#include "function.h"

namespace vSpace {

class stoch {
public:
//	For a stochastic process with several paths, compute the expected value at time t
	static arma::vec E( stochastic & Xt);

//  Variance of a function (signle path)
//	static double V( vfun& Xt);
//


private :
	stoch();
	virtual ~stoch();
};

} /* namespace vSpace */

#endif /* STOCH_H_ */
