/*
 * fonction.h
 *
 *  Created on: Nov 12, 2018
 *      Author: oliv
 */

#ifndef FONCTION_H_
#define FONCTION_H_

#include "vecSpace.h"

namespace vSpace {

class fonction: public vecSpace {
public:
//	fonction();
	fonction(const vecSpace& E);
	virtual ~fonction();

	virtual double operator() (const double& x) const= 0;

private:



};

} /* namespace vSpace */

#endif /* FONCTION_H_ */
