#include<iostream> 

enum class action {
	do_nothing, do_break, do_continue, do_return
};

void test(action a, char const* label) {
	std::cout << label << ':';
	do {
		switch(a) {
			case action::do_nothing:
				std::cout << " do_nothing";
			case action::do_break:
				std::cout << " do_break";
				break; 
			case action::do_continue:
				std::cout << " do_continue";
				continue; 
			case action::do_return:
				std::cout << " do_return";
				return;
			}	
			std::cout << " after_switch"; 	
		} while(false);
		std::cout << " after_do\n";
	
}

int main() {
	test(action::do_nothing, "nothing"); 
	test(action::do_break, "break"); 
	test(action::do_continue, "continue");
	test(action::do_return, "return"); 
	//nothing: do_nothing do_break after_switch after_do
	//break: do_break after_switch after_do
	//continue: do_continue after_do
	//return: do_return
	return 0; 
}
