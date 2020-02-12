#include<iostream> 
using namespace std; 

void func() {
	shared_ptr<int>ptr(new int); 
	*ptr = 50; 
	shared_ptr<int> ptr2 = ptr; 
	cout << ptr.use_count() << endl; //how many pointers refer to the same resource 
	cout << &ptr << endl; //address of the ptr
	cout << ptr << endl; //address of the ptr point to 50 
	cout << *ptr << endl;  //50 
}

int main() {
	func(); 

	return 0; 
}
