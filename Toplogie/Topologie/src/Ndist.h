/*
 * Ndist.h
 *Implements normal distribution
 *  Created on: Aug 4, 2018
 *      Author: oliv
 */

#ifndef NDIST_H_
#define NDIST_H_

#include "function.h"

namespace vSpace {

class Ndist: public function {
public:
	Ndist(int n = 1000);
	virtual ~Ndist();

	virtual double operator() (double x);
private :
	int n;
	arma::vec N;
	double f (double x){
		const double g_Pi = 3.14159265358979323846;
		return 1/sqrt(2*g_Pi)*exp(-pow(x,2)/2);
	}
};

} /* namespace vSpace */

#endif /* NDIST_H_ */
