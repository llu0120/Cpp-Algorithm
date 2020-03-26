#include<iostream> 
#define MAX(a, b) a > b ? a : b

/*The function  way to use define
#define MAX(a,b) \ 
	((a) > (b) ? (a) : (b))
*/

int main() {
	int a = 1;
	int b = 2; 
	int c = 3 + MAX(a,b) + 4;
	std::cout << c << '\n'; //c = 1
	return 0; 
};
