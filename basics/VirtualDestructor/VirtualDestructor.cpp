#include <iostream> 
using namespace std; 
class base {
	public: 
		base() {
			cout << "Constructing base" << endl;	
		}
		//If not using virtual here, only the base class will be destructed 
		virtual ~base() {
			cout << "Destructing base" << endl; 	
		}
};

class derived: public base {
	public: 
		derived() {
			cout << "Constructing derived" << endl; 
		}
		~derived() {
			cout << "Destructing derived" << endl; 
		}
};

int main() {
	derived* d = new derived(); 
	base* b = d;
	delete b; 
	return 0; 
}
