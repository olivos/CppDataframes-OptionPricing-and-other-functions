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
#include "stoch.h"
#include "func.h"
#include "Ndist.h"
#include "outputC.h"
#include "input.h"


using namespace arma;
using namespace std;
using namespace vSpace;

double fu(double x){
	return pow(x,2);
}

int main() {
//	dataframe d{1,vector<bool>{1,1,1},"/Users/oliv/Documents/GitHub/Topo/test.csv"};
	cout << vector<bool>{1,1,1}.size();
	return 0;
}
