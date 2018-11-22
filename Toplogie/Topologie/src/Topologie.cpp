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
#include "Eucallpdv.h"


using namespace arma;
using namespace std;
using namespace vSpace;




int main() {
	double maturity = 1; /* maturity in years : here 1 year */
	double sigmaL = 0.12; /* annualized low volatility */
	double sigmaH = 0.18; /* high vol */
	double r = 0.03; /* risk free interest rate */
	double q = 0; /* continuous dividend */
	double K = 1510; /* strike */

	int nx = 272; /*nx : parameter of realSpace


	must be number of points -1 !! because nx is such that maturity/nx = timeStep */

	realSpace T{0,maturity,nx}; /* Time space */
	dataframe Price(nx+1,vector<bool>{0,0,1},"/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/snp2013_2014_273.csv");/* price data */

	vfun S(T,Price.getData()); /* fonction for the price, e.g. fun or vfun   */
	Eucallpdv C20{S,K,r,sigmaL,sigmaH,q,20,1512.056};
	vec Port = vec(nx+1);
	C20.hedging(Port,false);
//
	Eucallpdv C30{S,K,r,sigmaL,sigmaH,q,30,1505.860333};
	C30.hedging(Port,false);

	Eucallpdv C40{S,K,r,sigmaL,sigmaH,q,40,1495.7825};
	C40.hedging(Port,false);

	Eucallpdv C50{S,K,r,sigmaL,sigmaH,q,50,1482.228};
	C50.hedging(Port,false);

	Eucallpdv C60{S,K,r,sigmaL,sigmaH,q,60,1471.287};
	C60.hedging(Port,false);


	Eucallpdv C100{S,K,r,sigmaL,sigmaH,q,100,1471.287};
	C100.hedging(Port,false);


	Eucall Cinf{S,K,r,sigmaL,q};
	Cinf.hedging(Port,false);

}
