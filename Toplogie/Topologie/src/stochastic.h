/*
 * stochastic.h
 * CLASS containing stochastic processes, method that can be applied
 * to stochastic processes are in the "stoch" STATIC class
 * (It is used as an abstract class but it is not truly one because in order to be used
 * as a type in static methods : therefore its constructors are protected )
 *
 *  Created on: Aug 1, 2018
 *      Author: oliv
 */

#ifndef STOCHASTIC_H_
#define STOCHASTIC_H_

#include "function.h"

namespace vSpace {

class stochastic: public function {
public:

	virtual double operator() (double x,int ligne);
	virtual double operator() (double t);


	virtual ~stochastic();

	int getNb() const {
		return nb;
	}



protected :
	stochastic();
	stochastic(vecSpace E);
	stochastic(vecSpace E,int nb);

	int nb;
};

} /* namespace vSpace */

#endif /* STOCHASTIC_H_ */
