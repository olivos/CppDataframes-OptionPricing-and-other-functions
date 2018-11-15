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


double price( const double& t){
	return t;
}

int main() {
	realSpace X{1,10,5};
	fun f{X,price};
	cout << func::max(f);



}
