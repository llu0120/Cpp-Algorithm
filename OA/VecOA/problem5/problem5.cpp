#include<iostream> 
using namespace std;
/*
//error: cannot assign to non-static data member 'x' with const-qualified type 'const int'
struct some_class {
	const int x; 
	some_class(const int y) {
		x = y;
	}
};
*/

/*
//Correct 
void fn(const char* ptr) {
	ptr = "string"; 
}

int main() {

	const char* ptr = "string1"; 
	fn(ptr);
	return 0;	
}
*/


/*
//error: implicit instantiation of undefined template 'std::__1::vector<std::__1::basic_string<char>, std::__1::allocator<std::__1::basic_string<char> > >'
std::size_t fn(std::vector<std::string> const& vector) {
	vector.reserve(100); 
	return vector.size(); 
}
*/

//Segmentation Fault 
void fn(std::unique_ptr<std::string> const& ptr) {
	(*ptr) += "!";
}

int main() {
	std::unique_ptr<std::string> const ptr; 
	fn(ptr); 
	return 0;
}

