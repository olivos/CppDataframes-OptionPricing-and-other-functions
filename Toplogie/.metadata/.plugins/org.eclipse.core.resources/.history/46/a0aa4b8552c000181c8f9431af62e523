/*
 * euCall.h
 *
 *  Created on: Aug 4, 2018
 *      Author: oliv
 */

#ifndef EUCALL_H_
#define EUCALL_H_

#include "vecSpace.h"
#include "Ndist.h"
#include "bs.h"
#include "math.h"

namespace vSpace {

class euCall: public vecSpace {
public:
	euCall(realSpace T,realSpace X, double sigma, double r, double K);
	virtual ~euCall();

	virtual double operator() (double t, double x);

	Ndist phi = Ndist();


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



	arma::mat surfaceEDP(); /* Finds the value surface of a European call by resolving the Partial differential equation
	very low performances, just used to test EDP module */
	arma::mat surface(); /* Finds the value surface of a European call using the analytical solution
	see Leonard Gallardo "Mouvement Brownien et Calcul d'Itô" */
	double Delta(double t, double y); /* Finds the delta of a European call using the analytical solution*/

	arma::vec HedgingPortfolio(bs & BS,realSpace HedgingTimes,double mu, double trueSigma, double S0); /* Simulates a portfolio
	to hedge an option which underlying follows Black Scholes model (mu,trueSigma,S0), HedgingTimes is the
	time vector containing the points were the adjustments will be done
	 	 More precisions : uses the space X,T for computing both the price of underlying
	 	 and the option value surface.*/




    friend std::ostream& operator<<(std::ostream& os, euCall& C){
    	int nt = C.sizes(0);
    	int nx = C.sizes(1);
    	realSpace X = C.X;
    	realSpace Y = C.Y;

    	os << "[";
    	for (int i = 0 ; i < nx ; i++){

    		os << "[";
    		for(int j = 0 ; j < nt ; j++){
    			os << C.operator () (X(j),Y(i)) << ",";
    		}
			os << C.operator() (X(nt),Y(i)) << "],";

    	}

		os << "[";
		for(int j = 0 ; j < nt ; j++){
			os << C.operator() (X(j),Y(nx)) << ",";
		}
		os << C.operator()(X(nt),Y(nx)) << "]]";

		return os;
    }

	const Ndist& getPhi() const;

private:
	double sigma;
	double r;
	double K;




	double a0 (double x) {
		  return -r;
	}
	double a1 (double x) {
		  return r/2*x;
	}
	double a2 (double x) {
		  return x*x*sigma*sigma/2;
	}
//	double gMin (double t ){
//		return 0;
//	}
//	double gMax (double t ){
//		return 30*t + 40*(1-t);
//	}
	double u0 (double x){
		if ( x > K){
			return x-K;
		}
		else {
			return 0;
		}
}
};

} /* namespace vSpace */

#endif /* EUCALL_H_ */
