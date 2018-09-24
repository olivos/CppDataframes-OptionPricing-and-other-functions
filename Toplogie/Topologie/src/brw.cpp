/*
 * brw.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: oliv
 */

#include "brw.h"
#include <random>

using namespace arma;
using namespace std;

namespace vSpace {

brw::brw() {
	// TODO Auto-generated constructor stub

}

//brw::brw(vecSpace E) : stochastic(E) {
//
//
//
//	Sn = mat(nb,sizes(0)+1,fill::zeros);
//
//	default_random_engine generator;
//	normal_distribution<double> distribution(0,deltas(0));
//
//	for (int i = 0 ; i < nb ; i++){
//		Sn(i,0) = distribution(generator);
//		for(int j = 1 ; j < sizes(0) ; j++ ){
//					Sn(i,j) = Sn(i,j-1) + distribution(generator);
//				}
//	}
//
//}

brw::brw(realSpace X, int nb) : stochastic(vecSpace(X),nb) {

	Sn = mat(nb,sizes(0)+1,fill::zeros);

	default_random_engine generator;
	normal_distribution<double> distribution(0,deltas(0));

	for (int i = 0 ; i < nb ; i++){
		Sn(i,0) = 0;
		for(int j = 1 ; j < sizes(0)+1 ; j++ ){
					Sn(i,j) = Sn(i,j-1) + distribution(generator);
				}
	}
}

double brw::operator ()(double t, int ligne) {
	int n = t/deltas(0);
 return Sn(ligne,n);
}

double brw::operator ()(double t) {
	return brw::operator ()(t, 0) ;

}

//vec brw::E() {
//	vec res = vec(sizes(0));
//	for (int j = 0 ; j < sizes(0) ; j++){
//		for (int i  =0 ; i < nb ; i++){
//		res(j) = brw::operator () (X(j),i);
//		}
//	}
//	return res;
//}
//
//arma::vec brw::V() {
//	vec res = vec(sizes(0));
//	for (int j = 0 ; j < sizes(0) ; j++){
//		for (int i  =0 ; i < nb ; i++){
//		res(j) = (brw::operator () (X(j),i))*(brw::operator () (X(j),i));
//		}
//	}
//	return res;
//}

brw::~brw() {
	// TODO Auto-generated destructor stub
}




} /* namespace vSpace */


