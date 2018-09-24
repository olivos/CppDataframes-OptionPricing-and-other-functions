
/*
 * brw.h
 *
 *  Created on: Aug 1, 2018
 *      Author: oliv
 */

#ifndef BRW_H_
#define BRW_H_

#include "stochastic.h"

namespace vSpace {

class brw: public stochastic {
public:
	brw();
//	brw(vecSpace E);
	brw(realSpace X,int nb = 1);

	virtual double operator() (double t,int ligne);
	virtual double operator() (double t);


//	virtual arma::vec E();
//	virtual arma::vec  V();

	virtual ~brw();

    friend std::ostream& operator<<(std::ostream& os, const brw& dt){
    	int nl = dt.nb;
    	int nc = dt.sizes(0);

    	for (int i = 0 ; i < nl ; i++){

    		os << "[";
    		    	for (int j = 0 ; j < nc ; j++){
    		    		os << dt.Sn(i,j) << ",";
    		    	}
    		    	os << dt.Sn(i,nc) << "]"<<"\n";

    	}
    	return os;
    }

	const arma::mat& getSn() const {
		return Sn;
	}

protected :
	arma::mat Sn;
};

} /* namespace vSpace */

#endif /* BRW_H_ */
