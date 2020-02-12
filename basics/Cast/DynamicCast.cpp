#include <iostream> 
using namespace std; 

class Base {
public: 
		virtual void foo() = 0; 
};

class Derived1: public Base {
public:
	void foo() {
		cout << "Derived1" << endl; 
	}
	void showOne() {
		cout << "Yes! It's Derived1." << endl; 
	}
};

class Derived2: public Base {
public:
	void foo() {
		cout << "Derived2" << endl; 
	}
	void showTwo() {
		cout << "Yes! It's Derived2." << endl; 
	}
};


void showWho(Base &base) {
	try {
		Derived1 derived1 = dynamic_cast<Derived1&>(base);
		 //if use static_cast --> need check by this 
		/*
		if(typeid(*base) == typeid(Derived1)) {
  	 		 Derived1 *derived1 = static_cast<derived1*>(base);
   			 derived1->showOne();
		} 
		*/
		derived1.showOne(); 
	}
	catch(bad_cast) {
		cout << "bad_cast" << endl; 
	}
}

int main() {
	Derived1 derived1; 
	Derived2 derived2; 

	showWho(derived1); 
	showWho(derived2); //Bad Cast  

	return 0; 
}
