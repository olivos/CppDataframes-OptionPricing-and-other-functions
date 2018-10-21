/*
 * EuPut.h
 *
 *  Created on: Oct 20, 2018
 *      Author: oliv
 */

#ifndef EUPUT_H_
#define EUPUT_H_
#include "vecSpace.h"
#include "Ndist.h"
#include "bs.h"
#include "math.h"
#include "vfun.h"

namespace vSpace {

class EuPut : public vecSpace {
public:
EuPut();
EuPut(realSpace T,realSpace X, double sigma, double r, double K);
virtual ~EuPut();

virtual double operator() (double t, double x);

Ndist phi = Ndist(100000);


double alpha1 (double t , double x){
return 1/(sigma*sqrt(final(0)-t) ) * (log(x/K)+(r+pow(sigma,2)/2)*(final(0)-t)  ) ;  }

double alpha2 (double t , double x){
return alpha1(t,x) - sigma*sqrt(final(0)-t) ;  }

double phiDiff ( double x){
	return 1/sqrt(2*M_PI)*exp(-pow(x,2)/2);
}

double alphaDiff(double t, double x){
	return 1/(sigma*sqrt(final(0)-t) ) * (1/x ) ;
}

arma::mat surface(); /* Finds the value surface of a European call using the analytical solution
see Leonard Gallardo "Mouvement Brownien et Calcul d'Itô" */
double Delta(double t, double y); /* Finds the delta of a European call using the analytical solution*/



friend std::ostream& operator<<(std::ostream& os, EuPut& P){
	int nt = P.sizes(0);
	int nx = P.sizes(1);
	realSpace X = P.X;
	realSpace Y = P.Y;

	os << "[";
	for (int i = 0 ; i < nx ; i++){

		os << "[";
		for(int j = 0 ; j < nt ; j++){
			os << P.operator () (X(j),Y(i)) << ",";
		}
		os << P.operator() (X(nt),Y(i)) << "],";

	}

	os << "[";
	for(int j = 0 ; j < nt ; j++){
		os << P.operator() (X(j),Y(nx)) << ",";
	}
	os << P.operator()(X(nt),Y(nx)) << "]]";

	return os;
}

const Ndist& getPhi() const;

virtual double getK() const {
	return K;
}

double getR() const {
	return r;
}

double getSigma() const {
	return sigma;
}

protected:
double sigma;
double r;
double K;


double u0 (double x){
	if ( x < K){
		return K-x;
	}
	else {
		return 0;
	}
}
};

} /* namespace vSpace */

#endif /* EUPUT_H_ */
