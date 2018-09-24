/*
 * bs.h
 *
 *  Created on: Aug 3, 2018
 *      Author: oliv
 */

#ifndef BS_H_
#define BS_H_

#include "brw.h"

namespace vSpace {

class bs: public brw {
public:
	bs();
	bs(realSpace E, double mu, double sigma, double S0, int nb = 1);

	virtual double operator()(double t,int ligne);
	virtual double operator()(double t);

	virtual ~bs();

	   friend std::ostream& operator<<(std::ostream& os, const bs& B){
	    	int nl = B.nb;
	    	int nc = B.sizes(0);

	    	for (int i = 0 ; i < nl ; i++ ){

	    	os << "[";
	    	for (int j = 0 ; j < nc ; j++){
	    		os << B.S0*exp((B.mu-B.sigma*B.sigma/2)*(j)*B.deltas(0) + B.sigma*B.Sn(i,j)) << ",";
	    	}
	    	os << B.S0*exp((B.mu-B.sigma*B.sigma/2)*nc*B.deltas(0) + B.sigma*B.Sn(i,nc)) << "]"<<"\n";

	    	}

	    	return os;
	    }

private :
	double mu;
	double sigma;
	double S0;
};

} /* namespace vSpace */

#endif /* BS_H_ */
