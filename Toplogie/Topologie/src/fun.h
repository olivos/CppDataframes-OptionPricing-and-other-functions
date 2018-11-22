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

#include "fonction.h"
#include "vfun.h"

namespace vSpace {

class fun: public fonction {
public:
//	fun();
	fun(const vecSpace& E,double (&f) (const double& x));

	virtual ~fun();

	virtual double operator() (const double&  x) const;


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
	double (&f) (const double&);
};

} /* namespace vSpace */

#endif /* FUN_H_ */

