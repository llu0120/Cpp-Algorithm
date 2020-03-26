#include<iostream> 

void a(int x) {
	x++; 
}

void b(int* x) {
	x += 2; 
}

void c(int& x) {
	x += 4; 
}

int main() {
	int x = 0;
	a(x);
	std::cout << x << std::endl; // x = 0 

	b(&x); 
	std::cout << x << std::endl; // x = 0

	c(x); 
	std::cout << x << std::endl; // x = 4
	return 0; 
}
