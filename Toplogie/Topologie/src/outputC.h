/*
 * outputC.h
 *
 *  Created on: Aug 4, 2018
 *      Author: oliv
 */

#ifndef OUTPUTC_H_
#define OUTPUTC_H_

#include <iostream>
#include <fstream>
#include <armadillo>




namespace vSpace {
class outputC {
public:


	template<class T1, class T2>
	static void plot(T1 x,T2 y) {
		std::cout << "import matplotlib.pyplot as plt"<<"\n\n";
		std::cout << "x =";
		std::cout << x;
		std::cout << "\n";
		std::cout << "y =";
		std::cout <<y ;
		std::cout << "\n";
		std::cout << "plt.plot(x,y) \n";
		std::cout << "plt.show() \n";
	}

	template<class T1, class T2>
	static void write(T1 x,T2 y,std::string fileName = "/Users/oliv/eclipse-workspace/file1.py") {
		std::ofstream myfile;
		myfile.open(fileName , std::ios::trunc );
		myfile << "import matplotlib.pyplot as plt"<<"\n\n";
		myfile << "x =";
		myfile << x;
		myfile << "\n";
		myfile << "y =";
		myfile <<y ;
		myfile << "\n";
		myfile << "plt.plot(x,y) \n";
		myfile << "plt.show() \n";
	}

	template<class T1, class T2>
	static void write3d(T1 x, T1 y,T2 z) {
//		credit https://jakevdp.github.io/PythonDataScienceHandbook/04.12-three-dimensional-plotting.html
		std::ofstream myfile;
		myfile.open ("/Users/oliv/eclipse-workspace/plotS.py" , std::ios::trunc );

		myfile << "from mpl_toolkits.mplot3d import Axes3D \nimport matplotlib.pyplot as plt \nfrom matplotlib import cm \nfrom matplotlib.ticker import LinearLocator, FormatStrFormatter \nimport numpy as np  \nimport math as m \n";

		myfile << "x =np.array(" << x<< ")\n";
		myfile << "y =np.array(" << y << ")\n";


		myfile << "x, y = np.meshgrid(x, y) \n";

		myfile << "z=np.array(" << z << ")\n";
		myfile << "ax = plt.axes(projection='3d') \nax.plot_surface(x, y, z, rstride=1, cstride=1, cmap='viridis', edgecolor='none') \nax.set_title('surface') ; \nplt.show()";

		myfile.close();
	}

	template<class T1, class T2, class T3>
	static void write3d(T1 x, T1 y,T2 z1,T3 z2) {

//		Credit https://jakevdp.github.io/PythonDataScienceHandbook/04.12-three-dimensional-plotting.html
		std::ofstream myfile;
		myfile.open ("/Users/oliv/eclipse-workspace/plotS.py" , std::ios::trunc );

		myfile << "from mpl_toolkits.mplot3d import Axes3D \nimport matplotlib.pyplot as plt \nfrom matplotlib import cm \nfrom matplotlib.ticker import LinearLocator, FormatStrFormatter \nimport numpy as np  \nimport math as m \n";

		myfile << "x =np.array(" << x<< ")\n";
		myfile << "y =np.array(" << y << ")\n";


		myfile << "x, y = np.meshgrid(x, y) \n";

		myfile << "z1=np.array(" << z1 << ")\n";
		myfile << "z2=np.array(" << z2 << ")\n";

		myfile << "ax = plt.axes(projection='3d') \nax.plot_surface(x, y, z1, rstride=1, cstride=1, cmap='viridis', edgecolor='none') \nax.plot_surface(x, y, z2, rstride=1, cstride=1, cmap='viridis', edgecolor='none') \nax.set_title('surface') ; \nplt.show()";

		myfile.close();
	}

	template<class T1, class T2, class T3>
	static void write3dL(T1 x, T1 y,T2 z1,T3 z2) {
		std::ofstream myfile;
		myfile.open ("/Users/oliv/eclipse-workspace/plotS.py" , std::ios::trunc );

		myfile << "from mpl_toolkits.mplot3d import Axes3D \nimport matplotlib.pyplot as plt \nfrom matplotlib import cm \nfrom matplotlib.ticker import LinearLocator, FormatStrFormatter \nimport numpy as np  \nimport math as m \n";

		myfile << "x =" << x<< "\n";
		myfile << "y =" << y << "\n";


		myfile << "x, y = np.meshgrid(x, y) \n";

		myfile << "z1=" << z1 << "\n";
		myfile << "z2=" << z2 << "\n";

		myfile << "ax = plt.axes(projection='3d') \nax.plot_surface(x, y, z1, rstride=1, cstride=1, cmap='viridis', edgecolor='none') \nax.plot_surface(x, y, z2, rstride=1, cstride=1, cmap='viridis', edgecolor='none') \nax.set_title('surface') ; \nplt.show()";

		myfile.close();
	}

//	static void writeHedge( Hedging& P, std::string fileName, bool delta = false){
//
//		std::ofstream myfile;
//		myfile.open(fileName , std::ios::trunc );
//
//		myfile << "import matplotlib.pyplot as plt"<<"\n\n";
//		myfile << "x =";
//		realSpace T  = P.getX();
//		myfile << T;
//		myfile << "\n";
//
//		realSpace HedgingTimes = P.getHedgingTimes();
//		myfile << "ht =";
//		myfile << HedgingTimes;
//		myfile << "\n";
//
//		myfile << "y =";
//		vfun val = vfun(HedgingTimes,P.getValue());
//		myfile << val;
//		myfile << "\n";
//
//		vfun Stock = P.getStock();
//		myfile << "st = ";
//		myfile << Stock;
//		myfile << "\n";
//		vfun Delta = P.getStock();
//		if(delta){
//		myfile << "delta = ";
//		myfile << Delta;
//		myfile << "\n";}
//
//		myfile << "for i in range(len(st)):\n\tst[i] = max(st[i] - ";
//		myfile <<P.getK()<< " , 0)\n";
//		if(delta){
//		myfile << "for i in range(len(delta)):\n\tdelta[i] = st[0]*delta[i]\n";
//		}
//		myfile << "fig, ax = plt.subplots()\nax.plot(ht, y, '-b', label='Hedging profolio value')\nax.plot(x, st, '-r', label='(St - K)+')\n";
//		if(delta){
//		myfile << "ax.plot(ht, delta, '-g', label='delta*S0')\n";
//		}
//		myfile << "leg = ax.legend();\n#Credit https:jakevdp.github.io/PythonDataScienceHandbook/04.06-customizing-legends.html ";
//		myfile.close();
//	}
//
//	static void writeHedge( VPutPDVhedging& P,arma::mat& Prices, int s, std::string fileName, bool delta = false){
//
//		std::ofstream myfile;
//		myfile.open(fileName , std::ios::trunc );
//
//		myfile << "import matplotlib.pyplot as plt"<<"\n\n";
//		myfile << "x =";
//		realSpace T  = P.getX();
//		myfile << T;
//		myfile << "\n";
//
//		realSpace HedgingTimes = P.getHedgingTimes();
//		myfile << "ht =";
//		myfile << HedgingTimes;
//		myfile << "\n";
//
//		myfile << "y =";
//		vfun val = vfun(HedgingTimes,P.getValue());
//		myfile << val;
//		myfile << "\n";
//
//		arma::vec S = Prices.col(s); /* Inefficient would require to modify the vec class !!!*/
//		vfun Stock = vfun(T,S);
//		myfile << "st = ";
//		myfile << Stock;
//		myfile << "\n";
//		vfun Delta = vfun(T,P.getDelta());
//		if(delta){
//		myfile << "delta = ";
//		myfile << Delta;
//		myfile << "\n";}
//
//		myfile << "for i in range(len(st)):\n\tst[i] = max("<< P.getK() << "-st[i], ";
//		myfile <<"0)\n";
//		if(delta){
//		myfile << "for i in range(len(delta)):\n\tdelta[i] = st[0]*delta[i]\n";
//		}
//		myfile << "fig, ax = plt.subplots()\nax.plot(ht, y, '-b', label='Hedging profolio value')\nax.plot(x, st, '-r', label='(St - K)+')\n";
//		if(delta){
//		myfile << "ax.plot(ht, delta, '-g', label='delta*S0')\n";
//		}
//		myfile << "leg = ax.legend();\n#Credit https:jakevdp.github.io/PythonDataScienceHandbook/04.06-customizing-legends.html ";
//		myfile.close();
//	}
//
//	static void writeHedge( VCallPDVhedging& P,arma::mat& Prices, int s, std::string fileName, bool vol = false){
//
//		std::ofstream myfile;
//		myfile.open(fileName , std::ios::trunc );
//
//		myfile << "import matplotlib.pyplot as plt"<<"\n\n";
//		myfile << "x =";
//		realSpace T  = P.getX();
//		myfile << T;
//		myfile << "\n";
//
//		realSpace HedgingTimes = P.getHedgingTimes();
//		myfile << "ht =";
//		myfile << HedgingTimes;
//		myfile << "\n";
//
//		myfile << "y =";
//		vfun val = vfun(HedgingTimes,P.getValue());
//		myfile << val;
//		myfile << "\n";
//
//		arma::vec S = Prices.col(s); /* Inefficient would require to modify the vec class !!!*/
//		vfun Stock = vfun(T,S);
//		myfile << "st = ";
//		myfile << Stock;
//		myfile << "\n";
//		vfun Vol = vfun(T,P.getVol());
//		if(vol){
//		myfile << "vol = ";
//		myfile << Vol;
//		myfile << "\n";}
//
//		myfile << "for i in range(len(st)):\n\tst[i] = max(st[i] - ";
//		myfile <<P.getK()<< " , 0)\n";
//		if(vol){
//		myfile << "for i in range(len(vol)):\n\tvol[i] = st[0]*vol[i]\n";
//		}
//		myfile << "fig, ax = plt.subplots()\nax.plot(ht, y, '-b', label='Hedging profolio value')\nax.plot(x, st, '-r', label='(St - K)+')\n";
//		if(vol){
//		myfile << "ax.plot(ht, vol, '-g', label='vol*S0')\n";
//		}
//		myfile << "leg = ax.legend();\n#Credit https:jakevdp.github.io/PythonDataScienceHandbook/04.06-customizing-legends.html ";
//		myfile.close();
//	}
//
//



private:
	outputC();
	virtual ~outputC();
};
} /* namespace vSpace */

#endif /* OUTPUTC_H_ */
