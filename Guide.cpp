// DATASTRUCTURES

//	A realSpace(const double& xi,const double& xf, const int& nx) represents
//	a discrete segment from xi to xf with a step of (xf-xi)/nx
//	There is no vector data member, only the boundaries, nx and the step are stored
//	constructor :
	realSpace R = realSpace(1.,10.,9);
//	There are nx+1 points !, the ith value can be accessed with (i)
	cout << R << ";" << R(1);

//	A vecSpace(const realSpace& X,const realSpace Y) represents
//	a "rectangle" formed by 2 realSpace (it can also be of dim 0, or of dim 1 i.e. a realSpace)
	realSpace X = realSpace(1.,10.,9);
	realSpace Y = realSpace(1.,5.,4);
	vecSpace V = vecSpace(X,Y);
//	There are nx+1 points !, the ith value can be accessed with (i)
	cout << V ;

//	fun represents a function defined on a realSpace and 
// whose values are given by double (fu) double . 
// The nx in the definition of the realSpace does not matter
	realSpace X = realSpace(1.,10.,9);
	fun f = fun(X,fu);
	cout << f;

//	vfun represents a function defined on a vecSpace and whose values
//	are stored in an armadillo mat (or vec)
	realSpace X = realSpace(1.,10.,9);
	vec M = vec(10);
	for(int i = 0 ; i != 10 ; ++i){
		M(i) = i;
	}
	vfun v = vfun(X,M);
	cout << v;


// dataframe (inspired by R dataframe) is used to load data from a csv file (With UNIX LINE ENDINGS !!)
// the titles (1st line) are stored in a vector<string> and the numerical value(other lines) are
// stored in an armadillo matrix
// 1st argument  : number of rows (excluding 1st row which is always treated as titles)
// 2nd argument : number of columns

	dataframe d{2,3,"path to csv file"};
	cout << d;

// for this csv :
price,strike,vol
12,10,0.3
123,120,0.2
// the output will be  :
   price        strike       vol   
   1.2000e+01   1.0000e+01   3.0000e-01
   1.2300e+02   1.2000e+02   2.0000e-01

// if we only want some of the columns a vector<bool> can be used as 2nd argument :
   	dataframe d{2,vector<bool>(false,true,false),"path to csv file"};
// the output will be :
   	   strike   
   1.0000e+01
   1.2000e+02



// OPTION PRICING FEATURES

// Eu calls and puts inherit from the abstrac class Option which itself iherits from fuction, 
	
	double price( const double& t){ /* function giving the underlying price in function of time if only known
	 at t = t_init it is okay to use a constant function like here (But in this case do not use C(t) for other 
	 values of t !)*/
	return 12;
}

	double maturity = 3./12; /* maturity in years : here 3 months */
	double t = 0; /* current time in years */
	double sigma = 0.3; /* annualized volatility */
	double r = 0.03; /* risk free interest rate */
	double q = 0; /* continuous dividend */
	double K = 10; /* strike */

	realSpace T{0,maturity,100}; /* Time space */
	fun S(T,price); /* fonction for the price, e.g. fun or vfun   */
	Euput P{S,K,r,sigma,q};
	cout << P(t); /* prints the value of the put at time t given the price S(t)*/



	// Hedging a Eucall with Black Scholes on data imported from a csv file

	double maturity = 1; /* maturity in years : here 1 year */
	double sigma = 0.137; /* annualized volatility */
	double r = 0.03; /* risk free interest rate */
	double q = 0; /* continuous dividend */
	double K = 2540; /* strike */

	int nx = 251; /*nx : parameter of realSpace


	must be number of points -1 !! because nx is such that maturity/nx = timeStep */

	realSpace T{0,maturity,nx}; /* Time space */
	dataframe Price(nx+1,1,"/Users/oliv/Documents/GitHub/Topo/snp500.csv");/* price data */
//	cout << Price;

	vfun S(T,Price.getData()); /* fonction for the price, e.g. fun or vfun   */

	Eucall C{S,K,r,sigma,q};

	vec HedgingPortfolio(nx+1); /* Creates the vector containing the value of the Hedging portfolio
	 which will be passed by ref to the hedging method */
//
	C.hedging(HedgingPortfolio); /* performs the hedging , display can vbe disable by prodiding a
	false bool as second argument*/


