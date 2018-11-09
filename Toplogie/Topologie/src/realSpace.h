/*
 * realSpace.h
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */

#ifndef REALSPACE_H_
#define REALSPACE_H_

#include <iostream>

namespace vSpace {

class realSpace {
public:
//	constructors
	realSpace();
	realSpace(const double& xi,const double& xf,const int& nx);

//	destructor
	virtual ~realSpace();

//	cout override
    friend std::ostream& operator<<(std::ostream& os, const realSpace& E){
    		int nx = E.nx;
    		double hx = E.hx;

    		os << "[";
    		for(int i = 0 ; i < nx ; i++){
    			os << E.xi + i*hx << ",";
    		}
    		os << E.xf << "]";
    		return os;

    }


//	()override
	virtual double operator()(int const& n) const;

	double getHx() const {
		return hx;
	}

	int getNx() const {
		return nx;
	}

	double getXf() const {
		return xf;
	}

	double getXi() const {
		return xi;
	}

private :
	double xi;
	double xf;
	int nx;
	double hx;

};
} /* namespace vSpace */

#endif /* REALSPACE_H_ */
