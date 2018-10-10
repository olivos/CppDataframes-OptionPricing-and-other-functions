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

#include "vecSpace.h"
#include "realSpace.h"
#include "fun.h"
#include "vfun.h"
#include "ed.h"
#include "brw.h"
#include "stoch.h"
#include "func.h"
#include "bs.h"
#include "euCall.h"
#include "Ndist.h"
#include "outputC.h"
#include "input.h"
#include "Hedging.h"

using namespace arma;
using namespace std;
using namespace vSpace;

double f (double x){
	return log(x/2902.54);
}

int main() {
//	Importing the data ( CSV file with one column )
	vec SNP = input::inputStock("/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.csv");

//	Time segment corresponding to the data start, end, n ( start and end in years,
//	n = (number of values) -1  .
	realSpace T  = realSpace(0,1,SNP.n_rows-1);

//	creates functions linking the time space and the values
	vfun snp = vfun(T,SNP);

//	Price segment starting at the lowest stock price and going to the max
	realSpace X = func::OutputSpace(snp);


//	T : Times segment, 0.13 volatility, 0.03 risk free rate, 2920 : strike
	euCall SP5 = euCall(T,X,0.137,0.03,2540);

//	Time segment representing the moments when portfolio adjustments are performed
	realSpace HedgingPoints = realSpace(0,1,250);


//	Object representing the hedging portfolio

	Hedging portf = Hedging(SP5,snp,HedgingPoints);

	//	value vector : represents the value of the hedging portfolio at time t
	vec val = portf.getValue();

//	function linking the time segment with the value vector
	vfun vVal = vfun(T,val);


//	output to a python file for graphical representation

	outputC::writeHedge(portf,"/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.py");

	return 0;
}
