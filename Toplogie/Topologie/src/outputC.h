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






private:
	outputC();
	virtual ~outputC();
};
} /* namespace vSpace */

#endif /* OUTPUTC_H_ */
