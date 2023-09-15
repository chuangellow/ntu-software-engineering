#include <iostream>
#include <string>

using namespace std;

class Mom {
	string name;
	public:
		Mom () {
			cout << "I'm mom" << endl;
		}
		Mom(string name) {
			this->name = name;
		}
};

class Daughter: public Mom {
	public:
		Daughter(string name) {
			cout << "Daughter's name is " << name << endl;
		}
};

class Son: public Mom {
	public:
		Son(string name): Mom(name) {
			cout << "Son's name is " << name << endl;
		}
};

int main(void) {
	Mom mom("Jane");
	Daughter daughter("Kate");
	Son son("John");
	Daughter daughter2("Mary");
	return 0;
}
