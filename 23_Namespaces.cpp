#include <iostream>

using namespace std;

namespace prvni_prostor {
   void fun() {
      cout << "Uvnitr prvniho prostoru" << endl; 
}  }


namespace druhy_prostor {
   void fun() {
      cout << "Uvnitr druheho prostoru" << endl;
}  }

using namespace prvni_prostor;
int main(void){
	prvni_prostor::fun();
	druhy_prostor::fun(); 
	fun();
	return 0;
}
