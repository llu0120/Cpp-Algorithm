#include<iostream> 
using namespace std; 

class Base {
	public: 
		void function1() {
			cout << "Base class function1" << endl; 
		}
		
		virtual void function2() {
			cout << "Base class function2" << endl; 
		}
};

class Derived1:public Base {
	public: 
	    void function1() {
			cout << "Derived class function1" << endl; 
		}
		void function2() {
			cout << "Derived class function2" << endl; 
		}
};

int main() {
	Derived1 d1; 
	Base* b = &d1; 
	b->function1();// 
	b->function2();
	return 0; 
}
