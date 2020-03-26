struct exp {
	explicit exp(char const* x) {}
};

void fn(exp x) {}

int main() {
	//exp y = exp("ok"); 

//	exp z("ok");
//	fn(exp("ok")); 
	fn("ok");
	exp x = "ok";
}
