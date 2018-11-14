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
	return 250;
}

int main() {

	dataframe d{1,vector<bool>{true,false,true},"/Users/oliv/Documents/GitHub/Topo/test.csv"};
	cout << d;


}
