/*
 * stoch.h
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef STOCH_H_
#define STOCH_H_

#include "brw.h"

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
