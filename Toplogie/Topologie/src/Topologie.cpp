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

//	Time space corresponding to the data start, end, n ( start and end in years,
//	n = (number of values) -1  .
	realSpace T  = realSpace(0,1,SNP.n_rows-1);

//	creates functions linking the time space and the values
	vfun snp = vfun(T,SNP);

//	Space containing starting at the lowest stock price and going to the max
	realSpace X = func::OutputSpace(snp);

//	T : points where hedging is accomplished, 0.13 volatility, 0.03 risk free rate, 2920 : strike
	euCall SP5 = euCall(T,X,0.137,0.03,2540);

//	value vector : represents the value of the hedging portfolio at time t
	Hedging portf = Hedging(SP5,snp,T);
	vec val = portf.getValue();

	vfun vVal = vfun(T,val);
//	output to a python file for graphical representation
//	outputC::write(T,vVal,"/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.py");

	outputC::writeHedge(portf,"/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.py");
	cout << snp;
return 0;
}
