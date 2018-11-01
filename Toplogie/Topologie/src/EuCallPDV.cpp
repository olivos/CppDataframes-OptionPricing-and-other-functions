/*
 * EuCallPDV.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: oliv
 */

#include "EuCallPDV.h"

using namespace std;
using namespace arma;

namespace vSpace {

EuCallPDV::EuCallPDV() {
	// TODO Auto-generated constructor stub

}

EuCallPDV::EuCallPDV(realSpace T, realSpace X, double sigmaL, double sigmaH,
		double r, double K):vecSpace(T,X),sigmaH(sigmaH),sigmaL(sigmaL),r(r),K(K) {
}

EuCallPDV::~EuCallPDV() {
	// TODO Auto-generated destructor stub
}

double EuCallPDV::operator ()(double t, double x, bool lowSigma) {
	if (x == 0){
		return 0;
	}
	else if ( t == final(0)){
		return u0(x);
	}
	else {
		return x * (phi)(alpha1(t,x,lowSigma))- K * exp( -r*(final(0)-t) ) * (phi)(alpha2(t,x,lowSigma));

	}
}

//double EuCallPDV::Delta(const double& t, const double& x,
//		arma::vec& shortPath,arma::vec upPath, arma::vec& vol, int i) {
//	shortPath = shift(shortPath,-1);
//	int n = shortPath.n_cols;
//	shortPath(n-1 ) = x;
//
//	upPath = shift(upPath,-1);
//	int nup = upPath.n_cols;
//	upPath(nup-1 ) = x;
//
//
//	if(x > Heuristic(shortPath)) {
//		vol = sigmaL;
//		return (phi)(alpha1(t,x,true));
//	}
//	else{
//		if(vol()){
//			vol = sigmaL;
//			return (phi)(alpha1(t,x,true));
//		}
//		else{
//		cout << "high ";
//		vol = sigmaH;
//		return (phi)(alpha1(t,x,false));}
//	}
//}

double EuCallPDV::Delta(const double& t, const double& x,
		arma::vec& longPath,arma::vec& shortPath, arma::vec& vol, int i) {
	longPath = shift(longPath,-1);
	int n = longPath.n_cols;
	longPath(n-1 ) = x;

	shortPath = shift(shortPath,-1);
	int nup = shortPath.n_cols;
	shortPath(nup-1 ) = x;

	switch(i){
	case 0 : {vol(0) = sigmaL;return (phi)(alpha1(t,x,true));}
	default : {
//		When the previous vol is low he use heuristic on the long path (13 days?)
		if(vol(i-1) == sigmaL){
			if(x > Heuristic(longPath)){ vol(i) = sigmaL;return (phi)(alpha1(t,x,true)); }
			else{vol(i) = sigmaH;return (phi)(alpha1(t,x,false));}
		}
//		When the previous vol is high we dont want to miss a market restart so use a shorter path
		else{
			if(x > Heuristic(shortPath)){vol(i) = sigmaL;return (phi)(alpha1(t,x,true));}
			else{vol(i) = sigmaH;return (phi)(alpha1(t,x,false));}
		}
	}
	}

}

} /* namespace vSpace */
