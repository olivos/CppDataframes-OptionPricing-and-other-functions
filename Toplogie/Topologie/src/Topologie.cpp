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
	return pow(cos(x),2);
}

void split(const string &chaine, char delimiteur, vector<string> &elements)
{
 stringstream ss(chaine);
 string sousChaine;
 while (getline(ss, sousChaine, delimiteur))
 {
 elements.push_back(sousChaine);
 }
}

vector<string> split(const string &chaine, char delimiteur)
{
 vector<string> elements;
 split(chaine, delimiteur, elements);
 return elements;
// credit https://www.journaldunet.fr/web-tech/developpement/1202959-comment-decouper-une-chaine-string-en-c/
}

int main() {
	realSpace K =  realSpace(0,2*M_PI,100);
	fun F = fun(K,f);
	cout << func::dMean(F);



return 0;
}
