/*
 * funDD.h
 *
 * Function of type (double, double) -> (double) , same methods as the "fun" class
 *
 *  Created on: Aug 3, 2018
 *      Author: oliv
 */

#ifndef FUNDD_H_
#define FUNDD_H_

#include "function.h"

namespace vSpace {

class funDD: public function {
public:
	funDD(vecSpace E,double (&f) (double x, double y));
	virtual ~funDD();

	virtual double operator() (double x,double y);


//	override of <<
    friend std::ostream& operator<<(std::ostream& os, const funDD& E){

    		os << "to do";
			return os;
    }
private :
	double (&f) (double x, double y);
};

} /* namespace vSpace */

#endif /* FUNDD_H_ */
