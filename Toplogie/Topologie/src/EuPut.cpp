/*
 * EuPut.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: oliv
 */

#include "EuPut.h"
using namespace arma;
using namespace std;
namespace vSpace {

EuPut::EuPut() {
	// TODO Auto-generated constructor stub

}

EuPut::~EuPut() {
	// TODO Auto-generated destructor stub
}


EuPut::EuPut(realSpace T,realSpace X, double sigma, double r, double K): vecSpace(T,X),sigma(sigma),r(r),K(K) {
}


double EuPut::operator ()(double t, double x) {
	if (x == 0){
		return 0;
	}
	else if ( t == final(0)){
		return u0(x);
	}
	else {
		return -x*phi(-alpha1(t,x))+K * exp( -r*(final(0)-t) ) * phi(-alpha2(t,x));

	}
}


const Ndist& EuPut::getPhi() const {
	return phi;
}

arma::mat EuPut::surface() {
	int nt = sizes(0);
	int nx = sizes(1);

	mat res = mat(nx+1,nt+1);

	for(int i = 0 ; i < nx+1 ; i++){
		for (int j = 0 ; j < nt+1 ; j++){
			res(i,j) =this->operator ()(X(j),Y(i));
		}
	}
	return res;
}


double EuPut::Delta(double t,double x) {
	return -phi(-alpha1(t,x)) ;
}


} /* namespace vSpace */
