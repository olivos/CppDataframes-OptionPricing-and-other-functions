/*
 * ed.cpp
 *
 *  Created on: Jul 28, 2018
 *      Author: oliv
 */

#include "ed.h"

using namespace arma;

namespace vSpace {

ed::ed() {
	// TODO Auto-generated constructor stub

}

vec ed::resout( function& a0, function& a1,  function& a2,
		 function& f, double uInit , double uFinal) {
	realSpace X = f.getX();
	int n = X.getNx();
	double hX = X.getHx();

//	Make Matrix

//	auto start2 = std::chrono::high_resolution_clock::now();
//
	mat spMatrix = mat(n-1,n-1,fill::zeros);
	spMatrix(0,0)= a0(X(1)) - 2*a2(X(1))/(hX*hX);
	spMatrix(0,1)= a1(X(1))/(2*hX)+a2(X(1))/(hX*hX);
	spMatrix(n-2,n-3) = -a1(X(n-1))/(2*hX)+a2(X(n-1))/(hX*hX);
	spMatrix(n-2,n-2) = a0(X(n-1)) - 2*a2(X(n-1))/(hX*hX);
	for (int i = 1 ; i < n-2 ; i++){
		spMatrix(i,i-1) = -a1(X(i+1))/(2*hX)+a2(X(i+1))/(hX*hX);
		spMatrix(i,i) = a0(X(i+1)) - 2*a2(X(i+1))/(hX*hX);
		spMatrix(i,i+1) = a1(X(i+1))/(2*hX)+a2(X(i+1))/(hX*hX);
	}
//
//	auto finish2 = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> elapsed2 = finish2 - start2;
//	std::cout << "Elapsed time: " << elapsed2.count() << " s\n";
//
	//	Modifie F pour adapter aux conditions aux limites
	vec B = vec(n-1,fill::zeros);
	B(0) = f(X(1)) - (-a1(X(1))/(2*hX)+a2(X(1))/(hX*hX))*uInit;
	B(n-2) =  f(X(n-1))- (a1(X(n-1))/(2*hX)+a2(X(n-1))/(hX*hX))*uFinal;
	for (int i = 1 ; i< n-2 ; i++){
		B(i) = f(X(i+1));
	}

//	Sparse matrix
	vec ResSp = vec(n+1);
	ResSp(0) = uInit;
	ResSp(n) = uFinal;
	ResSp.rows(1,n-1) = solve(spMatrix,B);

//
	return ResSp;
}

arma::vec ed::resoutDP(function& a0, function& a1, function& a2, function& f,
		double ht, double uInit, double uFinal) {
	realSpace X = f.getX();
	int n = X.getNx();
	double hX = X.getHx();
//	-u0/ht !!

//	Make Matrix

//	auto start2 = std::chrono::high_resolution_clock::now();
//
	mat spMatrix = mat(n-1,n-1,fill::zeros);
	spMatrix(0,0)= a0(X(1)) - 2*a2(X(1))/(hX*hX)-1/ht;
	spMatrix(0,1)= a1(X(1))/(2*hX)+a2(X(1))/(hX*hX);
	spMatrix(n-2,n-3) = -a1(X(n-1))/(2*hX)+a2(X(n-1))/(hX*hX);
	spMatrix(n-2,n-2) = a0(X(n-1)) - 2*a2(X(n-1))/(hX*hX)-1/ht;
	for (int i = 1 ; i < n-2 ; i++){
		spMatrix(i,i-1) = -a1(X(i+1))/(2*hX)+a2(X(i+1))/(hX*hX);
		spMatrix(i,i) = a0(X(i+1)) - 2*a2(X(i+1))/(hX*hX)-1/ht;
		spMatrix(i,i+1) = a1(X(i+1))/(2*hX)+a2(X(i+1))/(hX*hX);
	}
//
//	auto finish2 = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> elapsed2 = finish2 - start2;
//	std::cout << "Elapsed time: " << elapsed2.count() << " s\n";
//
	//	Modifie F pour adapter aux conditions aux limites
	vec B = vec(n-1,fill::zeros);
	B(0) = -f(X(1))/ht - (-a1(X(1))/(2*hX)+a2(X(1))/(hX*hX))*uInit;
	B(n-2) =  -f(X(n-1))/ht- (a1(X(n-1))/(2*hX)+a2(X(n-1))/(hX*hX))*uFinal;
	for (int i = 1 ; i< n-2 ; i++){
		B(i) = -f(X(i+1))/ht;
	}

//	Sparse matrix
	vec ResSp = vec(n+1);
	ResSp(0) = uInit;
	ResSp(n) = uFinal;
	ResSp.rows(1,n-1) = solve(spMatrix,B);

//
	return ResSp;
}

arma::mat ed::resoutP(function& a0, function& a1, function& a2, function& u0,
		function& uXMin, function& uXMax) {
	realSpace T = uXMin.getX();
	double tMin = T.getXi();
	double tMax = T.getXf();
	int nt = T.getNx();

	realSpace X = u0.getX();
	int nx = X.getNx();



	double hT = (tMax - tMin)/nt;
	mat U = mat(nx+1,nt+1);

//	U0
	for(int i = 0 ; i < nx+1 ; i++){
		U(i,0) = u0(X(i));
	}
//	t = tMin
	U.col(1) = resoutDP(a0,a1,a2,u0,hT,uXMin(T(1)),uXMax(T(1)));
//	Herédité
	for(int j = 2 ; j< nt+1;j++){
		vfun U_i = vfun(X,U.col(j-1));
		U.col(j) = resoutDP(a0,a1,a2,U_i,hT,uXMin(T(j+1)),uXMax(T(j+1)));
	}
	return U;
}

arma::mat ed::resoutP(function& a0, function& a1, function& a2, function& u0, realSpace& T) {

	double tMin = T.getXi();
	double tMax = T.getXf();
	int nt = T.getNx();

	realSpace X = u0.getX();
	int nx = X.getNx();

	double hT = (tMax - tMin)/nt;
	mat U = mat(nx+1,nt+1);

//	U0
	for(int i = 0 ; i < nx+1 ; i++){
		U(i,0) = u0(X(i));
	}
//	t = tMin
	U.col(1) = resoutDP(a0,a1,a2,u0,hT,u0(X(0)),u0(X(0)));
//	Herédité
	for(int j = 2 ; j< nt+1;j++){
		vfun U_i = vfun(X,U.col(j-1));
		U.col(j) = resoutDP(a0,a1,a2,U_i,hT,U(1,j-1),U(nx-1,j-1) );
	}
	return U;
}

ed::~ed() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */
