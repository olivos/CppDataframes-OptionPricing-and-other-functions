/*
 * VPuthedging.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: oliv
 */

#include "VPuthedging.h"
using namespace arma;
using namespace std;

namespace vSpace {

VPuthedging::VPuthedging() {
	// TODO Auto-generated constructor stub

}

VPuthedging::~VPuthedging() {
	// TODO Auto-generated destructor stub
}

VPuthedging::VPuthedging(EuPut P, arma::mat& Stock,int s,  bool display):EuPut(P){
	HedgingTimes = P.getX();
	int nH = HedgingTimes.getNx();

	B = vec(nH+1);/* vector representing evolution of the value of the hedgers bank account (does not count tha value of the underlying stock he holds*/
	thetaV = vec(nH+1); /* amount of stock held by the hedger at instant i */
	value = vec(nH+1); /* value of the hedgers portfolio at instant i = B+theta*St */

	double S0 = Stock(0,s);

//	Initialization

	double theta = Delta(0,S0);

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

		theta = Delta( HedgingTimes(i) ,Stock(i,s)  );
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


} /* namespace vSpace */
