#include<iostream> 
using namespace std; 

void func() {
	unique_ptr<int> ptr(new int); 
	unique_ptr<int> ptr2 = ptr; //Cannot make a copy of unique_ptr 
}

int main() {
	func(); 
	return 0;
}
