#include<iostream> 
#include<memory> 

struct Base {
	Base() {
		f("Base::ctor");
	}
	virtual ~Base() {
		f("Base::dtor");
	}
	
	virtual void f(char const* label) const {
		std::cout << label << ": Base\n";
	}
	void g() const {
		return f("Base::g");
	}
};

struct Derived : Base {
	Derived() {
		f("Derived::ctor");
	}
	~Derived() {
		f("Derived::dtor");
	}
	
	void f(char const* label) const {
		std::cout << label << ": Derived\n";
	}	
	void g() const {
		return f("Derived::g");
	}
};


int main() {
	std::unique_ptr<Base> b(new Derived); 
	b->g();
	/*
	Base::ctor: Base
	Derived::ctor: Derived
	Base::g: Derived
	Derived::dtor: Derived
	Base::dtor: Base
	*/

	return 0; 
}
