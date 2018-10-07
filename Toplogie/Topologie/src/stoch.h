/*
 * stoch.h
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef STOCH_H_
#define STOCH_H_

#include "vfun.h"
#include "brw.h"
#include <string>
#include "input.h"

namespace vSpace {

class stoch {
public:
	static arma::vec E( stochastic & Xt);


private :
	stoch();
	virtual ~stoch();
};

} /* namespace vSpace */

#endif /* STOCH_H_ */
