#include <iostream> 
using namespace std; 

void add(int a, int b) {
	cout << "Addition is: " << a+b << endl; 	
}

void subtract(int a, int b) {
	cout << "Subtraction is: " << a-b << endl; 
}

void multiply(int a, int b) {
	cout << "Multiplication is : " << a*b << endl; 
}

int main() {
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a =15, b =10; 
	while (true) {
	cout << "Enter Choice: 0 for add, 1 for subtract, 2 for multiply" << endl;
	scanf("%d", &ch); 
	if (ch > 2) {
		cout << "Exit" << endl;
		return 0; 
	}
	(*fun_ptr_arr[ch])(a,b);
	}
	return 0;
}
