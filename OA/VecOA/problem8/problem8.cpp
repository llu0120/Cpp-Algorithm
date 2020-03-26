#include<iostream>
#include<utility>
using namespace std;
template<class Type> 

/*
void fn(Type a) {
	fn2(std::forward<Type&&>(a));
}

void fn(Type& a) {
	fn2(std::forward<Type&>(a));
}

void fn(Type const& a) {
	fn2(std::forward<Type>(a));
}
*/
void fn(Type&& a) {
	fn2(std::forward<Type>(a));
}

