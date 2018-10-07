/*
 * input.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: oliv
 */

#include "input.h"

using namespace std;

namespace vSpace {

input::input() {
	// TODO Auto-generated constructor stub

}

void input::split(const string& chaine, char delimiteur,
		vector<string>& elements) {
	 stringstream ss(chaine);
	 string sousChaine;
	 while (getline(ss, sousChaine, delimiteur))
	 {
	 elements.push_back(sousChaine);
	 }
}

vector<string> input::split(const string& chaine,
		char delimiteur) {
	 vector<string> elements;
	 split(chaine, delimiteur, elements);
	 return elements;
	// credit https://www.journaldunet.fr/web-tech/developpement/1202959-comment-decouper-une-chaine-string-en-c/

}

std::string input::readData(std::string fileName) {
		std::ifstream fichier(fileName, std::ios::in);  // on ouvre le fichier en lecture
		if(fichier)  // si l'ouverture a réussi
		{
				std::string val;
				getline(fichier,val);
				fichier.close();  // on ferme le fichier
				return val;
		}
		else{
			throw "echec";
		}
	//        Credit https://openclassrooms.com/fr/courses/1133001-lecture-et-ecriture-dans-les-fichiers-en-c

}

arma::vec  input::inputStock(std::string fileName) {
	string st = input::readData(fileName);
	char c = 13;
	vector<string> lines = split(st,c);
	int n = lines.size();
	arma::vec res = arma::vec(n);
	for(int i = 0 ; i < n ; i++){
		res[i] = stod(lines[i]);
	}
	return res;
}

input::~input() {
	// TODO Auto-generated destructor stub
}

} /* namespace vecSpace */
