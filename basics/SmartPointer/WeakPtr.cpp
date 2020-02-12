#include<iostream> 
using namespace std; 

class Player{
public:
    weak_ptr<Player> companion;
    ~Player() { cout << "~Player\n"; }
};
int main()
{
    shared_ptr<Player> jasmine = make_shared<Player>();
    shared_ptr<Player> albert = make_shared<Player>();
    
    // Here doesn't increase the reference counter
    jasmine->companion = (weak_ptr<Player>)(albert); 
    albert->companion  = (weak_ptr<Player>)(jasmine);
    // So, program can successfully destruct this two pointers
	return 0; 
}
