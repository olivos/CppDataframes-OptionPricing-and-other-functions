//============================================================================
// Name        : Topologie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <armadillo>

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


using namespace arma;
using namespace std;
using namespace vSpace;

double a0 (double x){
	return 1;}
double a1 (double x){
	return 0;}
double a2 (double x){
	return 0;}
double sol (double x, double t){
	return exp(t);
}
double u0 (double x){
	return sol(x,0);
}
double umin(double t){
	return sol(0,t);
}
double umax(double t){
	return sol(10,t);
}
double f (double x){
	return pow(x,2);
}


int main() {

//	fun A0 = fun(X,a0);
//	fun A1 = fun(X,a1);
//	fun A2 = fun(X,a2);
//	fun U0 = fun(X,u0);
//	fun Umin = fun(T,umin);
//	fun Umax = fun(T,umax);


	realSpace T = realSpace(0,1,100); /* time */
//	Parameters to model euCall
	double sigma = 0.1;
	double r = 0.05;
	double K = 5;
//	Parameters to simulate the underlying price
	double mu = 0;
	double trueSigma = sigma;
	double S0 = 5;

	bs BS = bs(T,mu,sigma,S0);
//	cout << BS << endl;
	realSpace X = func::OutputSpace(BS);
//	cout << X <<endl;
	euCall C = euCall(T,X,sigma,r,K);

	vec B = C.HedgingPortfolio(BS,T, mu,  trueSigma,  S0);

	vfun S = vfun(vecSpace(T,X),C.surface() );

	vfun Vf = vfun(T,func::arc(S,BS));

	outputC::write(T,Vf);

	vfun bank = vfun(T,B);
	cout << bank;
return 0;
}
