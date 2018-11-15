/*
 * Option.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#include "Option.h"

using namespace arma;

namespace vSpace {

Option::Option():fonction(),S{fun()},K(0),r(0),T(0) {
	// TODO Auto-generated constructor stub

}

Option::Option(const fonction& S, const double& K,const double& r):fonction(S),S(S),K(K),r(r){
	T = final(0);
}

Option::~Option() {
	// TODO Auto-generated destructor stub
}

void Option::hedging(arma::vec& B , const bool& display) {
	int nH = sizes(0);

	B = vec(nH+1);/* vector representing evolution of the value of the hedgers bank account (does not count tha value of the underlying stock he holds*/

//	Initialization

	B(0) = this->operator()(0) - delta(0)*S(0);

	if(display){
	cout << "Initialization Option price is " << this->operator ()(0) << "theta is" << delta(0) << "bank account" << B(0)<< "\n";
	}

//	Heredity

	for (int i = 1 ; i != nH ; i++){

		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */

		if(display){
		cout << "Step"<<i << "St " << S(X(i)) << "after interests" << B(i);
		}

		B(i) = B(i) + delta(X(i-1))*S(X(i)); /* Selling theta underlying */

		if(display){
		cout << "after sale" << B(i);
		}

		B(i) = B(i) - delta(X(i))*S(X(i)); /* Buying newTheta underlying */

		if(display){
		cout << "newtheta" << delta(X(i)) << "after buying" << B(i)<<'\n';
		}

	}
//	Final stage

	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */

	if(display){
	cout << "Last Step St " << S(X(nH)) << "after interests" << B(nH);
	}
	B(nH) = B(nH) + delta(X(nH-1))*S(X(nH)); /* Selling theta underlying */

	cout << "after sale" << B(nH)<< "\n";

//	If the option ends up in the money broker needs to pay the option owner
	if ( this->operator ()(X(nH)) > 0 ){
		B(nH) = B(nH) - this->operator ()( X(nH) );
		cout << "In the money";
	}
	cout << "after closing the position"<< B(nH)<< "\n";
}

} /* namespace vSpace */
