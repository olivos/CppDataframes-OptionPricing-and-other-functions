/*
 * input.h
 *
 *  Created on: Oct 5, 2018
 *      Author: oliv
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <armadillo>



namespace vSpace {

class input {
public:
	static void split(const std::string &chaine, char delimiteur, std::vector<std::string> &elements);
	static std::vector<std::string> split(const std::string &chaine, char delimiteur);

	static std::string readData(std::string fileName);

	static arma::vec inputStock(std::string fileName);

private:
	input();
	virtual ~input();
};

} /* namespace vSpace */

#endif /* INPUT_H_ */
