#include<iostream> 
#include<vector> 

using namespace std; 

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i); 
	}

	//Print out contents
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << endl;
	}
	
	//Print out the address of each contents 
	for (int *i = &v[0], *end = &v[v.size()]; i < end; i++) {
		std::cout << i << endl; 
	}
	
	//Print out contents
	std::for_each(v.begin(), v.end(), [](int x) {
		std::cout << x << endl;
	});

	//Print out contents 	
	for (int x : v) {
		std::cout << x << endl; 
	}
	
 	//error: invalid operands to binary expression ('std::__1::ostream' (aka 'basic_ostream<char>') and 'std::__1::__wrap_iter<int *>')	
	for (auto i = v.begin(), end = v.end(); i != end; i++) {
		std::cout << i << endl;
	}
	
	return 0;
}
