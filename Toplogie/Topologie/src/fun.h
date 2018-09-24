/*
 * fun.h
 *
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 *
 *  Represents f : realSpace -> realSpace
 *  the fun class inherits from vecSpace, declaration : fun( realspace X , f : double -> double )
 *  Provides a light way to store a function and its base space. For multidimensional base space see vfun
 */

#ifndef FUN_H_
#define FUN_H_

#include "function.h"
#include "vfun.h"

namespace vSpace {

class fun: public function {
public:
	fun(vecSpace E,double (&f) (double));
	virtual ~fun();

	virtual double operator() (double x);
	virtual arma::vec diff();

	vSpace::vfun derive ();

//	override of <<
    friend std::ostream& operator<<(std::ostream& os, const fun& E){

    		os << "[";
    		for(int j = 0 ; j < E.sizes(0) ; j++){
    			os << E.f(E.init(0)+j*E.deltas(0))<< ",";
    		}
			os << E.f(E.final(0))<<  "]";
			return os;
    }


private :
	double (&f) (double);
};

} /* namespace vSpace */

#endif /* FUN_H_ */

