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
#include "stocks.h"
#include "Vhedging.h"
#include "EuPut.h"
#include "EuPutPDV.h"
#include "VPutPDVhedging.h"
#include "EuCallPDV.h"
#include "VCallPDVhedging.h"

using namespace arma;
using namespace std;
using namespace vSpace;



int main() {
//	stocks S = stocks("/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP7980.csv","/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP7980Vol.csv",133,7980);
//	stocks S = stocks("/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP2017.csv","/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP2017Vol.csv",133,7980);
//	stocks S = stocks("/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP2008.csv","/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/133FromSNP2008Vol.csv",133,7980);
	stocks S = stocks("/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/snp2013_2014_273.csv","/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/snp2013_2014_273Vol.csv",1,273);

// Procedure : 
// Import Data as csv from Option metrics with :
// 1st file from secutities with only sedID, date, opening price
// 2nd file from iterpolatedVol with secid,date,days,impl_volatility,impl_strike,cp_flag,index_flag

// Warning 1st file must be sorted in increasing order with unix end of line characters

//  returns a vector containing the one VPuthedging obeject for each stock imported, and prints the resuls of the hedging
	vector<VPuthedging> Hedges = S.hedgePut();


	//	vector<euCall> calls = S.gen_calls();
	// vec Prix = (S.getPrices()).col(0);
//
//	Vhedging H = Vhedging(calls[0],Prix);
	// realSpace T = realSpace(0,1,272);
	// realSpace X = realSpace(38.0,61.12,100);
	// cout << Prix;
	// EuCallPDV p1 = EuCallPDV(T,X,0.1160,0.22,0.03,1514);
	// VCallPDVhedging H1 = VCallPDVhedging(p1,Prix,0);
	// outputC::writeHedge( H1, Prix, 0 ,"/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/HedgePDV.py",true );


	// EuCallPDV p2 = EuCallPDV(T,X,0.1190,0.15,0.03,1514);
	// VCallPDVhedging H2 = VCallPDVhedging(p2,Prix,0,false);
	// outputC::writeHedge( H2, Prix, 0 ,"/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/Hedge.py",true );
	return 0;
}
