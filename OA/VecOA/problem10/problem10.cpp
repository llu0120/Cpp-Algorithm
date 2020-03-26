#include<iostream> 
struct parent {
	virtual ~parent(){};
};

struct child1 : parent {}; 
struct child2 : parent {};
struct childchild1 : child1 {};


int main () {
	childchild1 obj; 
	parent* p = &obj; 
	child1* c1 = dynamic_cast<child1*>(p);
	child2* c2 = dynamic_cast<child2*>(p);
	childchild1* cc1 = dynamic_cast<childchild1*>(p); 
	std:: cout << std::boolalpha << (c1 == nullptr) 
			   << ' ' << (c2 == nullptr) //Bad Cast 
			   << ' ' << (cc1 == nullptr);
	return 0;
}
