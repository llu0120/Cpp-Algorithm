//Lamda Function
#include<cctype>
#include<iostream> 
using namespace std;
template<typename Transformer> 
void transformer_and_print(Transformer t, std::string str) {
	t(str);
	std::cout << str << '\n';
}

int main() {
	auto toupper1 = [](string str) {for (auto c : str) c = std::toupper(c);};
	auto toupper2 = [](string& str) {for (auto c : str) c = std::toupper(c);};
	auto toupper3 = [](string str) {for (auto& c : str) c = std::toupper(c);};
	auto toupper4 = [](string& str) {for (auto& c : str) c = std::toupper(c);};
	
	transformer_and_print(toupper1, "toupper1"); //output: toupper1
	transformer_and_print(toupper2, "toupper2"); //output: toupper2
	transformer_and_print(toupper3, "toupper3"); //output: toupper3
	transformer_and_print(toupper4, "toupper4"); //output: TOUPPER4 
	return 0; 
}
