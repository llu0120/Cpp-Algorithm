#include <chrono> 
#include<iostream> 
#include <set>
#include <vector> 
#include <unordered_set> 

using namespace std::chrono;
using namespace std;

void fn1(std::vector<int>& vector) {
	auto fn = [](int x) {return x + 42;};
	std::transform(begin(vector), end(vector), begin(vector), fn);
}


void fn2(std::forward_list<int> list) {
	list.clear(); 
}


void fn3(std::set<int>& set) {
	set.insert(42);
}


void fn4(std::unordered_set<int> const& set) {
	auto result = set.find(42); 
	if (result != end(set)) {
		std::cout << *result; 
	}
}  

int main() {
	vector<int> vec;
 
	forward_list<int> list; 
	auto it = list.before_begin();
		
	set<int> s;  

	for (int i = 0; i < 100000; i++) {
		vec.push_back(i); 
		it = list.insert_after(it, i); 
		
		s.insert(i); 
	}
	unordered_set<int> us(vec.begin(), vec.end()); 
	
	auto start = high_resolution_clock::now();
	fn1(vec); 
	auto end = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(end - start); 
	cout << duration.count() << endl; 
	
	start = high_resolution_clock::now();
 	fn2(list); 
    end = hight_resolution_clock::now(); 
    duration = duration_cast<microseconds>(end - start); 
	cout << duration.count() << endl; 
	
	start = high_resolution_clock::now();
    fn3(s); 
    end = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(end - start); 
	cout << duration.count() << endl; 

	start = high_resolution_clock::now();
    fn4(us); 
    end = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(end - start); 
	cout << duration.count() << endl; 
	return 0;
}	
