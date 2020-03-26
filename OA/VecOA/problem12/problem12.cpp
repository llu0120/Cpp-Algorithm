#include<iostream> 
#include<map> 
#include<string> 

using namespace std; 

void f(map<string, int> map) {
	map["bar"] = 3; 
}

int main() {
	map<string, int> map; 
	map["foo"] = 5; 
	f(map); 
	map["baz"] = map["foo"] + map["quz"]; 
	for (auto i : map) {
		cout << i.first <<' ' << i.second << endl;
	}
	return 0; 
}
