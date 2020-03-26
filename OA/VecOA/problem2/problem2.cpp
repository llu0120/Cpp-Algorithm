#include<iostream> 

struct Base {
	virtual ~Base() = default; 
	void f(char const* label) const {
		std::cout << label << ": Base\n";
	}
	virtual void g(char const* label) const {
		std::cout << label << ": Base\n";
	} 
};

struct Derived : Base {
	void f(char const* label) const {
		std::cout << label << ": Derived\n";
	}
	void g(char const* label) const {
		std::cout << label << ": Derived\n";
	}
};

int main() {
	Derived d; 
	Base b1 = d; 
	Base &b2 = d; 
	
	d.f("d.f"); //Derived
	d.g("d.g"); //Derived
	b1.f("b1.f"); //Base
	b1.g("b1.g"); //Base
	b2.f("b2.f"); //Base
	b2.g("b2.g"); //Derived

	return 0;
}
