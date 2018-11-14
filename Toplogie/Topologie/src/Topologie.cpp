//============================================================================
// Name        : Topologie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <armadillo>
#include <vector>
#include <math.h>

#include "dataframe.h"
#include "vecSpace.h"
#include "realSpace.h"
#include "fun.h"
#include "vfun.h"
#include "function.h"
#include "fonction.h"
#include "stoch.h"
#include "func.h"

#include "outputC.h"
#include "input.h"

#include "Eucall.h"
#include "Euput.h"


using namespace arma;
using namespace std;
using namespace vSpace;

//	redo func

double price( const double& t){
	return 11;
}

int main() {

	double maturity = 1; /* maturity in years : here 1 year */
	double sigma = 0.137; /* annualized volatility */
	double r = 0.03; /* risk free interest rate */
	double q = 0; /* continuous dividend */
	double K = 2540; /* strike */

	int nx = 251; /*nx : parameter of realSpace
	 must be number of points -1 !! because nx is such that maturity/nx = timeStep */

	realSpace T{0,maturity,nx}; /* Time space */
	dataframe Price(nx+1,1,"/Users/oliv/Documents/GitHub/Topo/snp500.csv");/* price data */
//	cout << Price;

	vfun S(T,Price.getData()); /* fonction for the price, e.g. fun or vfun   */

	Eucall C{S,K,r,sigma,q};

	vec HedgingPortfolio(nx+1);
//
	C.hedging(HedgingPortfolio);




}
