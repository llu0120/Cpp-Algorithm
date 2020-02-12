#include <iostream> 
using namespace std; 

typedef void (*CALLBACK)(void*); //return type, function pointer, input parameter type

typedef struct _tagObject {
	CALLBACK cb; 
}obj;

void FuncA(void*); 
void FuncB(void*);

void FuncA(void* pParam) {
	char *str = (char *)pParam; 
	cout << "Here is Function A" << endl; 
}

void FuncB(void* pParam) {
	char *str = (char*)pParam;
	cout << "Here is Function B" << endl;  
}

//Register Callback Function 
void RegisterCallBackFunction(obj *pObj, CALLBACK cb) {
	pObj->cb = cb; 
	printf("pObj->cb:0x%x \n", pObj->cb);  
    //cout << "pObj->cb: " << pObj->cb << endl; 
}	

//Object call
void ObjectCall(obj* pObj) {
	void* pParam; 
	pObj->cb(pParam); 
}

int main(){
	//Two Object A, B
	obj objA, objB; 

	//Register Callback Function 
	RegisterCallBackFunction(&objA, FuncA); 
	RegisterCallBackFunction(&objB, FuncB); 
	
	//Choose Callback 
	int opt; 
	do {
		cout << "Which callback function do you want to call: 1 or 2" << endl; 
		cin >> opt; 
		switch (opt) {
			case 1: 
				ObjectCall(&objA); 
				break;
			case 2: 
				ObjectCall(&objB);
				break; 	
			default: 
				cout << "Dosen't exist" << endl; 
				break;  
		}
	} while (opt < 3);
	return 0; 
}

