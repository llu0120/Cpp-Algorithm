#include <iostream> 
using namespace std; 

void foo(const int*); 

void foo(const int* p) {
	int *v = const_cast<int*>(p); //Change const into changable
	*v = 20; 	
}
int main() {
	int var = 10; 
	cout << var << endl; 
		
	foo(&var); 
	
	cout << var << endl;
	return 0; 
}
