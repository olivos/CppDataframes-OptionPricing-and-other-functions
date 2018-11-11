/*
 * function.h
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "vecSpace.h"

namespace vSpace {

class function: public vecSpace {
public:
	virtual double operator() (const double& x);


protected :
	function();
	function(const vecSpace& E);
	virtual ~function();
};

} /* namespace vSpace */

#endif /* FUNCTION_H_ */
