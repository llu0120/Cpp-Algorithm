#include<iostream> 
using namespace std; 

class Point{
private: 
	int x; 
	int y; 

public: 
	Point(int x1, int y1) {
		x = x1; 
		y = y1; 
	}	
	//Copy Constructor
	Point(const Point &p2) {
		x = p2.x; 
		y = p2.y;
		cout << x << ", " << y << endl;  
	}
};


int main() {	
	Point p1(10,15); //Normal Constructor is called 
	Point p2 = p1; //Copy Constructor is called here 
	
	return 0; 
}
