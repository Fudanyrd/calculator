#include "complex_num.h"

using std::cout;		using std::cin;
using std::endl;		using std::string;

int main(int argc,char** argv){
	//input: a set of complex number
	//output: what you type in.
	//type "exit" to escape.
	string temp, exit = "exit";
	cin >> temp;
	complex_num n;
	while(temp != exit){
		n = converter(temp);
		cout << ">>> " << n << endl;
		cout << ">>> "; n.report(cout); cout << endl;
		cin >> temp;
	}
	
	return 0;
}
