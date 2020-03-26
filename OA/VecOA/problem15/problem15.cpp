#include<iostream>
#include<memory>

struct Base {
	virtual ~Base() = default; 
	
	virtual void f(char const* label = "Base default") const {
		std::cout << label << ": Base\n"; 
	}
};

struct Derived : Base {
	void f(char const* label = "Derived default") const {
		std::cout << label << ": Derived\n";
	}
};

int main() {
	std::unique_ptr<Base> b(new Derived);
	b->f(); //Base default: Derived
	return 0;
}
