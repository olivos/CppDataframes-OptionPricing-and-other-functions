/*
 * DataFrame.cpp
 *
 *  Created on: Nov 11, 2018
 *      Author: oliv
 */

#include "dataframe.h"

using namespace arma;
using namespace std;
namespace vSpace {


dataframe::dataframe():n(0),m(0) {
	data = mat(0,0);
	titles = std::vector<std::string>(0);

}

dataframe::dataframe(const int& n, const int& m, const std::string& filename):n(n),m(m) {
	data = mat(n,m);
	titles = std::vector<std::string>(m);

	string temp{};
	ifstream ip(filename);

//	extract the titles

	for(int j = 0 ; j != m-1 ; ++j){
		getline(ip,temp,',');
		titles[j] = temp;
	}
	getline(ip,temp,'\n');
	titles[m-1] = temp;

//	extract the values (double)

	for(int i = 0 ; i != n ; ++i){
		for(int j = 0 ; j != m-1 ; ++j){
			getline(ip,temp,',');
			data(i,j) = stod(temp);
		}
		getline(ip,temp,'\n');
		data(i,m-1) = stod(temp);
	}

	ip.close();
}

dataframe::dataframe(const int& n, const std::vector<bool>& cols,
		const std::string& filename): n(n),m(0) {

//	initialisation of m :
	for(vector<bool>::const_iterator it = cols.begin() ; it != cols.end() ; ++it){
	if(*it){ ++m;	}
	}

	data = mat(n,m);
	titles = std::vector<std::string>(m);

	string temp{};
	ifstream ip(filename);

//	extract the titles
	int pos{0};
	for(int j = 0 ; j != cols.size() ; ++j){
		getline(ip,temp,',');
		cout << temp<<" ";
		if(cols[j]){titles[pos] = temp;++pos;}
	}
	getline(ip,temp,'\n');
	cout << temp<<"\n";
	if(cols[m-1]){titles[m-1] = temp;}

//	extract the values (double)
	for(int i = 0 ; i != n ; ++i){
		pos = 0;
		for(int j = 0 ; j != cols.size() ; ++j){
			getline(ip,temp,',');
			cout << temp<<" ";
			if(cols[j]){data(i,pos) = stod(temp);++pos;}
		}
		getline(ip,temp,'\n');
		cout << temp<<"\n";

		if(cols[pos]){data(i,pos) = stod(temp);}
	}

	ip.close();

}

dataframe::~dataframe() {
	// TODO Auto-generated destructor stub
}

} /* namespace vSpace */


