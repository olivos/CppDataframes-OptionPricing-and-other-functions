/*
 * VPutPDVhedging.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: oliv
 */

#include "VPutPDVhedging.h"
using namespace std;
using namespace arma;
namespace vSpace {

VPutPDVhedging::VPutPDVhedging() {
	// TODO Auto-generated constructor stub

}

VPutPDVhedging::VPutPDVhedging(EuPutPDV P, arma::mat& Stock, int s,
	bool display):EuPutPDV(P) {

	HedgingTimes = P.getX();
	int nH = HedgingTimes.getNx();


	B = vec(nH+1);/* vector representing evolution of the value of the hedgers bank account (does not count tha value of the underlying stock he holds*/
	thetaV = vec(nH+1); /* amount of stock held by the hedger at instant i */
	value = vec(nH+1); /* value of the hedgers portfolio at instant i = B+theta*St */

	double S0 = Stock(0,s);

//	Initialization
//	we initialize the short path used by the Heuristic
	vec shortPath = vec(pathLength, fill::zeros);

	double theta = Delta(0,S0,shortPath);


	B(0) = P(0,S0) - theta*S0;
	thetaV(0) = theta;
	value(0) = P(0,S0);



	if(display){
	cout << "Initialization Option price is " << this->operator ()(0,S0) << "theta is" << theta << "bank account" << B(0)<< "\n";
	}

//	Heredity

	for (int i = 1 ; i<nH ; i++){
		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */

		if(display){
		cout << "Step"<<i << "St " << Stock(i,s) << "after interests" << B(i);
		}

		B(i) = B(i) + theta*Stock(i,s); /* Selling theta underlying */
		value(i) = B(i);

		if(display){
		cout << "after sale" << B(i);
		}

		theta = Delta( HedgingTimes(i) ,Stock(i,s) , shortPath );
		thetaV(i) = theta;


		B(i) = B(i) - theta*Stock(i,s); /* Buying newTheta underlying */

		if(display){
		cout << "newtheta" << theta << "after buying" << B(i)<<endl;
		}

	}
//	Final stage

	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */

	if(display){
	cout << "Last Step St " << Stock(nH,s) << "after interests" << B(nH);
	}
	thetaV(nH) = theta;
	B(nH) = B(nH) + theta*Stock(nH,s); /* Selling theta underlying */
	value(nH) = B(nH);
	cout << "after sale" << B(nH)<< "\n";

	if ( Stock(nH,s) < K ){
		B(nH) = B(nH) + Stock(nH,s) - K;
		cout << "after selling the stock to the customer:"<< B(nH)<< "\n";
	}

}

VPutPDVhedging::~VPutPDVhedging() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */
