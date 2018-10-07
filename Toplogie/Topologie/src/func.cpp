/*
 * func.cpp
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#include "func.h"
#include <iostream>
#include <tuple>

namespace vSpace {

func::func() {
	// TODO Auto-generated constructor stub

}

double func::diff(function& f, double x) {
	int index = f.index(x);
	realSpace X = f.getX();
	int nx = X.getNx();
	double hx = X.getHx();

	if(index == 0){return (f(X(index+1))-f(X(index)))/hx;}
	else if (index ==nx){return (f(X(index))-f(X(index-1)))/hx;}
	else {return (f(X(index+1))-f(X(index-1)))/(2*hx);}


}

double func::diff(vfun& f, double x, double y, int i) {
//	need to add exception for if i inappropriate, for now by default along Y
	if (i == 1){
		int indexX= f.index(x,y).first;
		realSpace X = f.getX();
		int nx = X.getNx();
		double hx = X.getHx();


		if(indexX == 0){return (f(x+hx,y)-f(x,y))/hx;}
		else if (indexX ==nx){return (f(x+hx,y)-f(x-hx,y))/hx;}
		else {return (f(x,y)-f(x-hx,y))/(2*hx);}
	}
	else {
		int indexY= f.index(x,y).second;
		realSpace Y = f.getY();
		int ny = Y.getNx();
		double hy = Y.getHx();


		if(indexY == 0){return (f(x,y+hy)-f(x,y))/hy;}
		else if (indexY ==ny){
			return (f(x,y+hy)-f(x,y-hy))/hy;
		}
		else {return (f(x,y)-f(x,y-hy))/(2*hy);}
	}
}


arma::vec func::diff(function& f) {
	realSpace X = f.getX();
	int nx = X.getNx();
	double hx = X.getHx();

	arma::vec V = arma::vec(nx+1);

	V(0)= (f(X(1))-f(X(0)))/hx;

	for(int i = 1 ; i < nx; i++){
		V(i) = (f(X(i+1))-f(X(i-1)))/(2*hx);
	}

	V(nx)= (f(X(nx))-f(X(nx-1)))/hx;

	return V;
}

arma::vec func::prim(function& f) {
	realSpace X = f.getX();
	int nx = X.getNx();
	double hx = X.getHx();

	arma::vec V = arma::vec(nx+1);
	V(0) = 0;

	for(int j = 1 ;  j < nx+1 ; j++ ){
		V(j) = (f(X(j))-f(X(j-1)))*hx/2 + f(X(j-1))*hx + V(j-1);
	}
	return V;

}

arma::vec func::prim(function& f, realSpace new_X) {
	realSpace X = new_X;
	int nx = X.getNx();
	double hx = X.getHx();

	arma::vec V = arma::vec(nx+1);
	V(0) = 0;

	for(int j = 1 ;  j < nx+1 ; j++ ){
		V(j) = (f(X(j))-f(X(j-1)))*hx/2 + f(X(j-1))*hx + V(j-1);
	}
	return V;
}

arma::vec vSpace::func::prim(function& f, double a) {
	arma::vec V = prim(f);

	return V - V(f.index(a));
}

double vSpace::func::integ(function& f, double a, double b) {
	realSpace X = f.getX();
	double hx = X.getHx();
//	Create a new realSpace with same step as X to call prime on new_X which will be smaller than X
	int new_nx = (b-a)/hx;
	realSpace new_X = realSpace(a,b,new_nx);

//	Calls prim(f,new_X)

	return prim(f,new_X)(new_nx);
}

double func::max(function& f) {
	if (f.getDim() != 1){
		throw "max only works for 1 dimensional input space!";
	}
	realSpace X = f.getX();
	int n = X.getNx();
	double max = f(X(0));

	for (int i = 1 ; i < n+1 ; i++){
		if (f(X(i))> max){
			max = f(X(i));
		}
	}
	return max;

}

double func::min(function& f) {
	if (f.getDim() != 1){
		throw "min only works for 1 dimensional input space!";
	}
	realSpace X = f.getX();
	int n = X.getNx();
	double min = f(X(0));

	for (int i = 1 ; i < n+1 ; i++){
		if (f(X(i))< min){
			min = f(X(i));
		}
	}
	return min;
}

realSpace func::OutputSpace(function& f, int n) {
	if (n == 0){
		return realSpace(min(f),max(f),f.getSizes()(0));
	}
	return realSpace(min(f),max(f),n);
}

arma::vec func::arc(vfun& f, function& phi) {
//	if (f.getDim() != 0 or phi.getSizes()(0) != phi.getSizes()(0) ){ throw "wrong argument" ;}


	int nt = phi.getSizes()(0);
	arma::vec V = arma::vec(nt+1);
	realSpace T = phi.getX();

	for (int i = 0 ; i <nt ; i++){
		V(i) = f(T(i),  phi(T(i))  );
	}
	return V;
}

double func::dMean(function& f) {
	realSpace X = f.getX();
	int n  = X.getNx();
	double m = 0;

	for(int i = 0 ; i < n+1 ; i++){
		m += f(X(i));
	}
	return m/(n+1);
}



func::~func() {
	// TODO Auto-generated destructor stub
}



} /* namespace vSpace */


