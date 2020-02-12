#include <vector> 
#include <iostream> 
using namespace std; 
int main() {
	int b = 10; 
	int a[3]; 
	a[0] = 1; 
	a[1] = 2;
	a[2] = 3; 
	cout << "b: " << b << endl;  
	a[6] = 4; 
	cout << "b: " << a[6] << endl;  
	return 0; 
}
