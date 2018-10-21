/*
 * vfun.h
 *
 *  Created on: Jul 27, 2018
 *      Author: oliv
 *
 *      Represents f : E -> F.
 *      It inheritates from the vecSpace E, F can be obtained with the outputSpace method.
 *      Contrary to fun, the result is represented by an armadillo matrix (matrix is a vec if dim(E)=1 ).
 *
 *
 *      Declaration :  vfun(E,mat& M) : BEWARE if E.nx = n then M should be of size n+1 (indeed n is the number of steps so
 *      there are n+1 points in the space)
 *      (No default constructor because vec ref has to be initialized)
 *
 *      Note : not using a reference for the vecSpace is fine because it a vecSpace very light in terms of memory
 */

#ifndef VFUN_H_
#define VFUN_H_

#include "function.h"

namespace vSpace {

class vfun: public function {
public:
	vfun(vecSpace E,arma::mat M);
	vfun();
	virtual ~vfun();
//	virtual arma::vec diff ();

	virtual double operator() (double x);
	virtual double operator() (double x, double y);


    friend std::ostream& operator<<(std::ostream& os, const vfun& E){
    	switch(E.dim){
    	case 1 : {

    		int nx = E.sizes(0);

    		os << "[";
    		for(int j = 0 ; j < nx ; j++){
    			os << E.M(j)<< ",";
    		}
			os << E.M(nx)<<  "]";return os;}
    	case 2 : {

    		int nx = E.sizes(0);
    		int ny = E.sizes(1);

    		os<< "[";
    		for(int i = 0 ; i < ny ; i++){

				os << "[";
				for(int j = 0 ; j < nx ; j++){
					os << E.M(i,j)<< ",";
				}
				os << E.M(i,nx)<<  "],"; }
			os << "[";

			for(int j = 0 ; j < nx ; j++){
				os << E.M(ny,j)<< ",";
			}
			os << E.M(ny,nx)<<  "]]"; return os;

    		}

    	}
    	return os;
    }

	const arma::mat getM() const {
		return M;
	}

protected :
	arma::mat M;
};

} /* namespace vSpace */

#endif /* VFUN_H_ */




