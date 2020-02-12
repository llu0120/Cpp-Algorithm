#include<iostream> 
using namespace std; 

template <class G> 
G myMax(G x, G y) {
	cout << x - y << endl;
	return (x>y)?x:y; 
}

int main() {
	myMax<int>(3,7); 
	myMax<float>(3.3, 7.5); 
	myMax<char>('c', 'g'); 
	return 0; 
}
