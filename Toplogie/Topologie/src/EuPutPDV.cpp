/*
 * EuPutPDV.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: oliv
 */

#include "EuPutPDV.h"
using namespace arma;
namespace vSpace {

EuPutPDV::EuPutPDV(){
	// TODO Auto-generated constructor stub

}

EuPutPDV::EuPutPDV(realSpace T, realSpace X, double sigmaL, double sigmaH,
		double r, double K) : vecSpace(T,X),sigmaH(sigmaH),sigmaL(sigmaL),r(r),K(K){
}

EuPutPDV::~EuPutPDV() {
	// TODO Auto-generated destructor stub
}

double EuPutPDV::operator ()(double t, double x, bool lowSigma) {
	if (x == 0){
		return 0;
	}
	else if ( t == final(0)){
		return u0(x);
	}
	else {
		return -x * (phi)(-alpha1(t,x,lowSigma))+ K * exp( -r*(final(0)-t) ) * (phi)(-alpha2(t,x,lowSigma));

	}
}

double EuPutPDV::Delta(const double& t,const double& x,vec& shortPath){
	shortPath = shift(shortPath,-1);
	int n = shortPath.n_cols;
	shortPath(n-1 ) = x;

	if(x > Heuristic(shortPath)) {
		return -(phi)(-alpha1(t,x,true));
	}
	else{
		cout << "high ";
		return -(phi)(-alpha1(t,x,false));
	}
}


} /* namespace vSpace */
