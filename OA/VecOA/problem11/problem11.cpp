#include<iostream>
using namespace std;
int main() {
	/*WORKS
	int* ptr = new int(4);
	delete[] ptr;
	*/

	/*WORKS	
	int* ptr = new int(4); 
	delete ptr;
	*/

	/*	
	int* ptr = new int[4];
	for (std::size_t i = 0; i < 4; i++) {
		delete ptr[i]; //error: cannot delete expression of type 'int'
	}
	*/
	
	/*WORKS	
	int* ptr = new int[4];
	delete[] ptr;
	*/

	//*WORKS BUT WARNING	
	int* ptr = new int[4];
	delete ptr; //Memeory leak  
	
	return 0;
}
/*
所以总结下就是，如果ptr代表一个用new申请的内存返回的内存空间地址，即所谓的指针，那么：

delete ptr -- 代表用来释放内存，且只用来释放ptr指向的内存。
delete[] rg -- 用来释放rg指向的内存，！！还逐一调用数组中每个对象的 destructor！！
对于像 int/char/long/int* /struct 等等简单数据类型，由于对象没有 destructor，所以用 delete 和 delete [] 是一样的！但是如果是C++ 对象数组就不同了！


*/



