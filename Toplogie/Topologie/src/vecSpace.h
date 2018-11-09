/*
 * vecSpace.h
 *
 *  Created on: Jul 26, 2018
 *      Author: oliv
 *
 *   Represents a Subset of a vectorial Space of dimension 1 (segment) or 2 (cartesian product of two segments)
 */

#ifndef VECSPACE_H_
#define VECSPACE_H_

#include <armadillo>
#include <iostream>
#include "realSpace.h"
#include <vector>
#include <tuple>


namespace vSpace {

class vecSpace {
public:
//	constructors
	vecSpace();
	vecSpace(const vSpace::realSpace& X);
	vecSpace(const vSpace::realSpace& X,const vSpace::realSpace& Y);

//	destructor
	virtual ~vecSpace();

//	cout override
    friend std::ostream& operator<<(std::ostream& os, const vecSpace& E){
    	switch(E.dim){
    	case 1 : os << E.X; break;
    	case 2 : os << E.X << "\n" << E.Y;break;
    	default : os <<"";break;
    	}
    	return os;
    }


	virtual int index(const double& x) const; /* Returns index of x in the vector */
	virtual std::pair<int, int> index(const double& x,const double& y) const; /* Returns index (i,j) of (x,y) in the matrix */


	const arma::vec& getDeltas() const;
	int getDim() const;

	const arma::vec& getFinal() const;
	const arma::vec& getInit() const;
	const arma::ivec& getSizes() const;
	const vSpace::realSpace& getX() const;
	const vSpace::realSpace& getY() const;

protected :
	vSpace::realSpace X;
	vSpace::realSpace Y;
	int dim;
	arma::ivec sizes;
	arma::vec deltas;
	arma::vec init;
	arma::vec final;

};

} /* namespace vSpace */

#endif /* VECSPACE_H_ */
