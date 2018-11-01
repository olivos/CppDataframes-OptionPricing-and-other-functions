/*
 * EuPutPDV.h
 *
 *  Created on: Oct 21, 2018
 *      Author: oliv
 */

#ifndef EUPUTPDV_H_
#define EUPUTPDV_H_

#include "vecSpace.h"
#include "Ndist.h"
#include "bs.h"
#include "math.h"
#include "vfun.h"


namespace vSpace {

class EuPutPDV : public vecSpace  {
public:
	EuPutPDV();
	EuPutPDV(realSpace T,realSpace X, double sigmaL, double sigmaH, double r, double K);
	virtual ~EuPutPDV();

	virtual double operator() (double t, double x, bool lowSigma = true);


	double alpha1 (double t , double x, bool low){
	if(low){
		return 1/(sigmaL*sqrt(final(0)-t) ) * (log(x/K)+(r+pow(sigmaL,2)/2)*(final(0)-t) );}
	else{
		return 1/(sigmaH*sqrt(final(0)-t) ) * (log(x/K)+(r+pow(sigmaH,2)/2)*(final(0)-t) );}
	}

	double alpha2 (double t , double x, bool low){
		switch(low){
		case 1 : return alpha1(t,x,low) - sigmaL*sqrt(final(0)-t) ;
		default : return alpha1(t,x,low) - sigmaH*sqrt(final(0)-t);
		}
	}
//	PDV delta : new price in the short memory path, computes heuristic and chooses between high or low sigma
	double Delta(const double& t,const double& x,arma::vec& shortPath);

	double getK() const {
		return K;
	}

protected:
double sigmaH;
double sigmaL;
double r;
double K;
Ndist phi = Ndist(100000);


double u0 (double x){
	if ( x < K){
		return K-x;
	}
	else {
		return 0;
	}
}

double Heuristic(arma::vec& shortPath){
	return mean(shortPath);
}

};

} /* namespace vSpace */

#endif /* EUPUTPDV_H_ */
