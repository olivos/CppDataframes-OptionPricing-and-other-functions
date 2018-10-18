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

//	Transforms a csv to a matrix of n lines, p columns. Note the row zero is
//	systematically eliminated because it contains titles and not doubles.
	static arma::mat csvToMat(std::string filename,int n, int p);

private:
	input();
	virtual ~input();
};

} /* namespace vSpace */

#endif /* INPUT_H_ */
