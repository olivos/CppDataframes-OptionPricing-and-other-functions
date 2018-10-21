/*
 * Hedging.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: oliv
 */

#include "Hedging.h"
using namespace arma;
using namespace std;

namespace vSpace {



Hedging::Hedging(euCall C, vfun* BS, realSpace HedgingTimes, bool display):euCall(C),HedgingTimes(HedgingTimes),Stock(BS) {


	n = HedgingTimes.getNx();
	B = vec(n+1);/* vector representing evolution of the value of the hedgers bank account (does not count tha value of the underlying stock he holds*/
	thetaV = vec(n+1); /* amount of stock held by the hedger at instant i */
	value = vec(n+1); /* value of the hedgers portfolio at instant i = B+theta*St */

	int nH = HedgingTimes.getNx();
	double S0 = (*Stock)(HedgingTimes(0));

//	Initialization

	double theta = Delta(0,S0);

	B(0) = C(0,S0) - theta*S0;
	thetaV(0) = theta;
	value(0) = C(0,S0);



	if(display){
	cout << "Initialization Option price is " << this->operator ()(0,S0) << "theta is" << theta << "bank account" << B(0)<< "\n";
	}

//	Heredity

	for (int i = 1 ; i<nH ; i++){
		B(i) = B(i-1)*exp(r*deltas(0)); /* Interest return */

		if(display){
		cout << "Step"<<i << "St " << (*Stock)(HedgingTimes(i)) << "after interests" << B(i);
		}

		B(i) = B(i) + theta*(*Stock)(HedgingTimes(i)); /* Selling theta underlying */
		value(i) = B(i);

		if(display){
		cout << "after sale" << B(i);
		}

		theta = Delta( HedgingTimes(i) ,(*Stock)(HedgingTimes(i))  );
		thetaV(i) = theta;


		B(i) = B(i) - theta*(*Stock)(HedgingTimes(i)); /* Buying newTheta underlying */

		if(display){
		cout << "newtheta" << theta << "after buying" << B(i)<<endl;
		}

	}
//	Final stage

	B(nH) = B(nH-1)*exp(r*deltas(0)); /* Interest return */

	if(display){
	cout << "Last Step St " << (*Stock)(HedgingTimes(nH)) << "after interests" << B(nH);
	}
	thetaV(nH) = theta;
	B(nH) = B(nH) + theta*(*Stock)(X(nH)); /* Selling theta underlying */
	value(nH) = B(nH);
	cout << "after sale" << B(nH)<< "\n";

	if ( (*Stock)(X(nH)) > K ){
		B(nH) = B(nH) - (*Stock)(X(nH)) + K;
		cout << "after selling the stock to the customer:"<< B(nH)<< "\n";
	}


}

Hedging::Hedging():Stock(0) {
}

Hedging::~Hedging() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */
