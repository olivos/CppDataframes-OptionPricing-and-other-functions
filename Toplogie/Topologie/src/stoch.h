/*
 * stoch.h
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef STOCH_H_
#define STOCH_H_

#include "vfun.h"
#include "stochastic.h"
#include <string>
#include "input.h"
#include "function.h"
#include "func.h"

namespace vSpace {

class stoch {
public:
//	For a stochastic process with several paths, compute the expected value at time t
	static arma::vec E( stochastic & Xt);

	static double Ide (double x){
		return x;
	}
//  Variance of a function (signle path)
//	static double V( function& Xt , double(&g)(double) = Ide);

//	Cdf of normal density function
//	static double phi(const double& x){
//		return arma::normcdf(1);
//	}


private :
	stoch();
	virtual ~stoch();
};

} /* namespace vSpace */

#endif /* STOCH_H_ */
