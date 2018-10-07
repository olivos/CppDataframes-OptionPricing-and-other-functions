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

using namespace arma;
using namespace std;
using namespace vSpace;

double f (double x){
	return log(x/2902.54);
}

int main() {
	vec SNP = input::inputStock("/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.csv");
	realSpace X  = realSpace(0,1,SNP.n_rows-1);
	vfun F = vfun(X,SNP);
	cout << stoch::V(F,f)<<endl;
	cout << stoch::V(F,log)<<endl;




return 0;
}
