/*
 * euCall.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: oliv
 */

#include "euCall.h"
#include "vfun.h"
#include "ed.h"
#include "func.h"

using namespace arma;

namespace vSpace {

euCall::euCall(realSpace T,realSpace X, double sigma, double r, double K): vecSpace(T,X),sigma(sigma),r(r),K(K) {
}

euCall::~euCall() {
	// TODO Auto-generated destructor stub
}

double vSpace::euCall::operator ()(double t, double x) {
	if (x == 0){
		return 0;
	}
	else if ( t == final(0)){
		return u0(x);
	}
	else {
		return x*phi(alpha1(t,x))-K * exp( -r*(final(0)-t) ) * phi(alpha2(t,x));

	}
}


arma::mat euCall::surfaceEDP() {
//  X corresponds to time, Y corresponds to space
//	The partial derivative equation if final conditon is transformed to one with initial condition in order to
//	use resoutP, and then the result matrix's columns are reorderd into a new matrix.

	vec  VA0 = vec(sizes(1)+1);
	for (int i = 0 ; i < sizes(1)+1 ; i++){
		VA0(i) = a0(Y(i));
	}
	vfun A0 = vfun(Y,VA0);

	vec  VA1 = vec(sizes(1)+1);
	for (int i = 0 ; i < sizes(1)+1 ; i++){
		VA1(i) = a1(Y(i));
	}
	vfun A1 = vfun(Y,VA1);

	vec  VA2 = vec(sizes(1)+1);
	for (int i = 0 ; i < sizes(1)+1 ; i++){
		VA2(i) = a2(Y(i));
	}
	vfun A2 = vfun(Y,VA2);

	vec  VU0 = vec(sizes(1)+1);
	for (int i = 0 ; i < sizes(1)+1 ; i++){
		VU0(i) = u0(Y(i));
	}
	vfun U0 = vfun(Y,VU0);


	arma::mat temp = ed::resoutP(A0,A1,A2,U0,X);
	mat res = fliplr( temp );
	return res;
}

const Ndist& euCall::getPhi() const {
	return phi;
}

arma::mat euCall::surface() {
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


double euCall::Delta(double t,double x) {
	return phi(alpha1(t,x)) ;
}
// version using numeric derivation
//vec euCall::HedgingPortfolio(bs & BS, realSpace HedgingTimes, double mu, double trueSigma,double S0) {
//	int nH = HedgingTimes.getNx();
//	vec B = vec(nH+1); /* vector representing evolution of the value of the portfolio*/
//	mat Val = surface(); /* matrix containing value of the option*/
//
////	How to avoid vecSpace(X,Y) ??
//	vfun V = vfun(vecSpace(X,Y),Val);
//
////	Initialization
//
//	int theta = func::diff(V,0,S0,2);
//	B(0) = V(0,S0) - theta*S0;
//	cout << "Initialization Option price is " << V(0,S0) << "theta is" << theta << "bank account" << B(0)<< "\n";
//
//
////	Heredity
//
//	for (int i = 1 ; i<nH ; i++){
//
//		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */
//
//		cout << "Step"<<i << "St " << BS(HedgingTimes(i)) << "after interests" << B(i);
//
//		B(i) = B(i) + theta*BS(HedgingTimes(i)); /* Selling theta underlying */
//
//		cout << "after sale" << B(i);
//
//		theta = func::diff(V,HedgingTimes(i),BS(HedgingTimes(i)),2);
//		B(i) = B(i) - theta*BS(HedgingTimes(i)); /* Buying newTheta underlying */
//		cout << "newtheta" << theta << "after buying" << B(i)<<endl;
//
//	}
////	Final stage
//
//	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */
//	B(nH) = B(nH) + theta*BS(X(nH)); /* Selling theta underlying */
//	if ( BS(X(nH)) > K ){
//		B(nH) = B(nH) - BS(X(nH)) - K;
//	}
//	return B;
//}

//	using numeric evaluation of the analytic formula of delta

vec euCall::HedgingPortfolio(bs & BS, realSpace HedgingTimes, double mu, double trueSigma,double S0) {
	int nH = HedgingTimes.getNx();
	vec B = vec(nH+1); /* vector representing evolution of the value of the portfolio*/



//	Initialization

	double theta = Delta(0,S0);
//	cout << "["<< theta <<",";
	B(0) = this->operator ()(0,S0) - theta*S0;
	cout << "Initialization Option price is " << this->operator ()(0,S0) << "theta is" << theta << "bank account" << B(0)<< "\n";


//	Heredity

	for (int i = 1 ; i<nH ; i++){
		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */

		cout << "Step"<<i << "St " << BS(HedgingTimes(i)) << "after interests" << B(i);

		B(i) = B(i) + theta*BS(HedgingTimes(i)); /* Selling theta underlying */

		cout << "after sale" << B(i);

		theta = Delta( HedgingTimes(i) ,BS(HedgingTimes(i))  );
		cout << theta <<",";
		B(i) = B(i) - theta*BS(HedgingTimes(i)); /* Buying newTheta underlying */

		cout << "newtheta" << theta << "after buying" << B(i)<<endl;

	}
//	Final stage

	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */

	cout << "Last Step St " << BS(HedgingTimes(nH)) << "after interests" << B(nH);

	B(nH) = B(nH) + theta*BS(X(nH)); /* Selling theta underlying */

	cout << "after sale" << B(nH)<< "\n";

	if ( BS(X(nH)) > K ){
		B(nH) = B(nH) - BS(X(nH)) - K;
	}
//	cout << theta <<"]"<<"\n";
	return B;
}

arma::vec euCall::HedgingPortfolio(vfun& BS, realSpace HedgingTimes,
		double mu, double trueSigma, double S0) {
	int nH = HedgingTimes.getNx();
	vec B = vec(nH+1); /* vector representing evolution of the value of the portfolio*/



//	Initialization

	double theta = Delta(0,S0);
//	cout << "["<< theta <<",";
	B(0) = this->operator ()(0,S0) - theta*S0;
	cout << "Initialization Option price is " << this->operator ()(0,S0) << "theta is" << theta << "bank account" << B(0)<< "\n";


//	Heredity

	for (int i = 1 ; i<nH ; i++){
		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */

		cout << "Step"<<i << "St " << BS(HedgingTimes(i)) << "after interests" << B(i);

		B(i) = B(i) + theta*BS(HedgingTimes(i)); /* Selling theta underlying */

		cout << "after sale" << B(i);

		theta = Delta( HedgingTimes(i) ,BS(HedgingTimes(i))  );
		cout << theta <<",";
		B(i) = B(i) - theta*BS(HedgingTimes(i)); /* Buying newTheta underlying */

		cout << "newtheta" << theta << "after buying" << B(i)<<endl;

	}
//	Final stage

	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */

	cout << "Last Step St " << BS(HedgingTimes(nH)) << "after interests" << B(nH);

	B(nH) = B(nH) + theta*BS(X(nH)); /* Selling theta underlying */

	cout << "after sale" << B(nH)<< "\n";

	if ( BS(X(nH)) > K ){
		B(nH) = B(nH) - BS(X(nH)) - K;
	}
//	cout << theta <<"]"<<"\n";
	return B;

}

} /* namespace vSpace */


