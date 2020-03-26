#include<memory> 
/*WORKS
int main() {
	std::shared_ptr<int> x(new int(42));
	auto y = x; 
	return 0;
}
*/

/*
//unique_ptr can only points to one memory 
int main() {
	 std::unique_ptr<int> x(new int(42));
     auto y = x; 
     return 0;
}
*/

/*WORKS
int main() {
	std::shared_ptr<int> x(new int(42)); 
	std::weak_ptr<int> y(x); 
	return 0;
}
*/

//Can only construct a weak_ptr out of a shared_ptr or a weak_ptr 
int main() {
	std::unique_ptr<int> x(new int(42)); 
	std::weak_ptr<int> y(x);
	return 0;
}
