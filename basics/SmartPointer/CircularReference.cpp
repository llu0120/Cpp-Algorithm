#include<iostream> 
using namespace std; 

class Player{
public: 
	shared_ptr<Player> companion; 
	~Player(){
		cout << "~Player\n" << endl;
	}
};

int main() {
	shared_ptr<Player> joseph(new Player); 
	shared_ptr<Player> anna(new Player); 
	
	joseph->companion = anna; 
	anna->companion = joseph;
	//When Joseph is about to destruct anna->companion still points this reference which make unsuccessful destruction 
	return 0; 
}
