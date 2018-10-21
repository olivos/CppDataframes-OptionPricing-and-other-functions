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

using namespace arma;
using namespace std;
using namespace vSpace;



int main() {
	stocks S = stocks("/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/138FromSNP8400.csv","/Users/oliv/Documents/ColumbiaMSOR/OptionMetrics/138FromSNP8400Vol.csv",140,8400);
	S.hedgePut();
	//	vector<euCall> calls = S.gen_calls();
//	vec Prix = (S.getPrices()).col(0);
//
//	Vhedging H = Vhedging(calls[0],Prix);
//	EuPut p = EuPut(realSpace(0,1,100),realSpace(0,1,100),0.12,0.03,20);
	return 0;
}
