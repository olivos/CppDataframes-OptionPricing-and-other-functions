SIMULATING DELTA HEDGING WITH MARKET DATA FROM A CSV FILE

int main() {
//	Importing the data ( CSV file with one column
	vec SNP = input::inputStock("/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.csv");

//	Time space corresponding to the data start, end, n ( start and end in years,
//	n = (number of values) -1  .
	realSpace T  = realSpace(0,1,SNP.n_rows-1);

//	creates functions linking the time space and the values
	vfun snp = vfun(T,SNP);

//	Space containing starting at the lowest stock price and going to the max
	realSpace X = func::OutputSpace(snp);

//	T : points where hedging is accomplished, 0.13 volatility, 0.03 risk free rate, 2920 : strike
	euCall SP5 = euCall(T,X,0.13,0.03,2920);

//	bank vector : represents the money in the hedgers' bank account at each time
//	where hedging is performed

	vec Bank = SP5.HedgingPortfolio(snp,T);

	realSpace T2 = realSpace(0,1,(SNP.n_rows-1)/2);

//	Step by step display can be unactivated by setting the last variable to false
	vec Bank2 = SP5.HedgingPortfolio(snp,T2,false);

//	We can see that on this case hedging every two days instead of daily you are $4 further
//	from equilibrium ( +$4.63 instead of +$0.54 )
	cout << Bank[SNP.n_rows-1] << " " << Bank2[(SNP.n_rows-1)/2];




return 0;
}


// Tuto 2

//	Importing the data ( CSV file with one column
	vec SNP = input::inputStock("/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.csv");

//	Time space corresponding to the data start, end, n ( start and end in years,
//	n = (number of values) -1  .
	realSpace T  = realSpace(0,1,SNP.n_rows-1);

//	creates functions linking the time space and the values
	vfun snp = vfun(T,SNP);

//	Space containing starting at the lowest stock price and going to the max
	realSpace X = func::OutputSpace(snp);

//	T : points where hedging is accomplished, 0.13 volatility, 0.03 risk free rate, 2920 : strike
	euCall SP5 = euCall(T,X,0.137,0.03,2540);

//	bank vector : represents the money in the hedgers' bank account (not including the value of the uunderlying he owns !) at each time
//	where hedging is performed

	vec Bank = SP5.HedgingPortfolio(snp,T,true);



	realSpace T2 = realSpace(0,1,(SNP.n_rows-1)/2);

//	Step by step display can be unactivated by setting the last variable to false
//	vec Bank2 = SP5.HedgingPortfolio(snp,T2,false);

//	We can see that on this case hedging every two days instead of daily you are $4 further
//	from equilibrium ( +$4.63 instead of +$0.54 )
//	cout << Bank[SNP.n_rows-1] << " " << Bank2[(SNP.n_rows-1)/2];

//  converting the bank vector to a vfun
	vfun vBank = vfun(T,Bank);

//	output to a python file for graphical representation
	outputC::write(T,vBank,"/Users/oliv/Documents/ColumbiaMSOR/Programming/snp500.py");
	cout << snp;