#include<iostream> 
using namespace std; 

struct person {
	std::string name; 
	int age; 
};

/*error: reference to overloaded function could not be resolved
void operator<< (std::ostream& os, person const& p) {
	os << p.name << "of age " << p.age; 
}
*/

/*error: invalid operands to binary expression ('const std::ostream' (aka 'const basic_ostream<char>') and 'const std::string' (aka 'const basic_string<char, char_traits<char>, allocator<char> >'))

std::ostream const& operator<<(std::ostream const& os, person const& p) {
	os << p.name << " of age " << p.age; 
	return os; 
}
*/

/*WORKS
std::ostream& operator<<(std::ostream& os, person const& p) {
	os << p.name << " of age " << p.age;
	return os;
}
*/
//*WORKS
std::ostream& operator<<(std::ostream& os, person const& p) {
	std::cout << p.name << " of age " << p.age; 
	return os;
}

int main() {
	std::cout << person{"John", 32} << std::endl;
	return 0 ;
}
