/*
 * Eucallpdv.cpp
 *
 *  Created on: Nov 15, 2018
 *      Author: oliv
 */

#include "Eucallpdv.h"
using namespace std;
using namespace arma;
namespace vSpace {

Eucallpdv::Eucallpdv(const fonction& S, const double& K, const double& r,
		const double& sigmaL, const double& sigmaH, const double& q, const int& memory, const double& initAVG):
		Option(S,K,r),
		sigmaL(sigmaL),
		sigmaH(sigmaH),
		q(q),
		memory(memory),
		sigma{0},
		avg{0}{
			sigma = vec(sizes(0)+1);
			avg = vec(sizes(0)+1,fill::zeros);
			if(initAVG == -1){
				avg(0) = S(0);
			}
			else{
				avg(0) = initAVG;
			}
			heuristic1();
			primSigma = func::prim(volfun(),func::puiss2); /* the sigma vec has already been initialized
			 so the call to volfun() will work propoerly*/
		}

Eucallpdv::~Eucallpdv() {
	// TODO Auto-generated destructor stub
}

double Eucallpdv::operator ()(const double& t) const {
	return exp(-q*(T-t))*S(t)* normcdf(d1(t)) - exp(-r*(T-t)) * K * normcdf(d2(t));
}

double Eucallpdv::vol(const double& t) const {
	vfun vsigma{X,sigma}; /* unexpensive because vsigma only stores references
	to X and sigma */
	return vsigma(t);
}

double Eucallpdv::delta(const double& t) const {
	return exp(-q*(T-t))*normcdf(d1(t));
}

vfun Eucallpdv::volfun() const {
	return vfun(X,sigma);
}

vfun Eucallpdv::avgfun() const {
	return vfun(X,avg);
}



void Eucallpdv::heuristic1() {
	queue<double> line{};
	for(int i = 0 ; i != memory ; ++i){
		line.push(avg(0));
	}
	sigma(0) = sigmaL;
	for(int i = 1 ; i != sizes(0)+1 ; ++i){
		avg(i) = func::mavg(avg(i-1),S(X(i)),memory,line);
		if( avg(i) > S(X(i)) ){
			sigma(i) =sigmaH;
		}
		else{
			sigma(i) = sigmaL;
		}
	}
}

double Eucallpdv::sigmaQ(const double& t) const {
	vfun v{X,primSigma};
	return v(T)-v(t);
}

} /* namespace vSpace */
