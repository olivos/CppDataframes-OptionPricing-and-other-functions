/*
 * ed.h
 *
 *  Created on: Jul 28, 2018
 *      Author: oliv
 */

#ifndef ED_H_
#define ED_H_

#include "fun.h"
#include "vfun.h"
#define ARMA_DONT_USE_WRAPPER

#include <armadillo>

namespace vSpace {

class ed {
public:
	static arma::vec resout( function& a0, function& a1,  function& a2,
			function& f, double uInit , double uFinal);

	static arma::vec resoutDP( function& a0, function& a1,  function& a2,
			 function& f,double ht, double uInit , double uFinal);

	static arma::mat resoutP(function& a0, function& a1,
			function& a2, function& u0,function& uXMin,function& uXMax);

	static arma::mat resoutP(function& a0, function& a1,
			function& a2, function& u0,realSpace& T);
//	to sole on (0,10) with step 1, then the arguments have (1,9) as base space and the result will have(1,9) as well

private:
	ed();
	virtual ~ed();
};

} /* namespace vSpace */

#endif /* ED_H_ */
