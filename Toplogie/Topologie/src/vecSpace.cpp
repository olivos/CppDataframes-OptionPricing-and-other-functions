/*
 * vecSpace.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 */

#include "vecSpace.h"

using namespace arma;

namespace vSpace {



} /* namespace vSpace */

vSpace::vecSpace::vecSpace() : dim(0) {}

vSpace::vecSpace::vecSpace(vSpace::realSpace X) : X(X),dim(1) {
	sizes = ivec(dim);
	deltas = vec(dim);
	init = vec(dim);
	final = vec(dim);


	sizes(0) = X.getNx();
	deltas(0) = X.getHx();
	init(0) = X.getXi();
	final(0) = X.getXf();

}

vSpace::vecSpace::vecSpace(vSpace::realSpace X, vSpace::realSpace Y) : X(X),Y(Y),dim(2) {
	sizes = ivec(dim);
	deltas = vec(dim);
	init = vec(dim);
	final = vec(dim);

	sizes(0) = X.getNx();
	deltas(0) = X.getHx();
	init(0) = X.getXi();
	final(0) = X.getXf();
	sizes(1) = Y.getNx();
	deltas(1) = Y.getHx();
	init(1) = Y.getXi();
	final(1) = Y.getXf();
}

vSpace::vecSpace::~vecSpace() {
}

int vSpace::vecSpace::index(double x) {
	return X(x);
}

std::pair<int, int> vSpace::vecSpace::index(double x, double y) {
	return std::make_pair(X(x),Y(y));
}

//double vSpace::vecSpace::operator ()(int n) {
//	return X(n);
//}
//
//arma::vec vSpace::vecSpace::operator ()(int i, int j) {
//	vec v = vec(2);
//	v(0) = X(i);
//	v(1) = Y(j);
//	return v;
//}

const arma::vec& vSpace::vecSpace::getDeltas() const {
	return deltas;
}

int vSpace::vecSpace::getDim() const {
	return dim;
}

const arma::vec& vSpace::vecSpace::getFinal() const {
	return final;
}

const arma::vec& vSpace::vecSpace::getInit() const {
	return init;
}

const arma::ivec& vSpace::vecSpace::getSizes() const {
	return sizes;
}

const vSpace::realSpace& vSpace::vecSpace::getX() const {
	return X;
}

double vSpace::vecSpace::operator ()(double x) {
	return x;
}

const vSpace::realSpace& vSpace::vecSpace::getY() const {
	return Y;
}
