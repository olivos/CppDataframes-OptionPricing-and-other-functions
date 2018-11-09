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
//	vfun represents a function defined on a vecSpace and whose values
//	are stored in an armadillo mat (or vec)
	realSpace X = realSpace(1.,10.,9);
	fun f = fun(X,fu);
	cout << f;

	return 0;
}
