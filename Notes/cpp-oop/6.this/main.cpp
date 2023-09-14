#include <iostream>

using namespace std;

class A {
	public:
		int isitme(A *ptr) {
			if (ptr == this) return 1;
			else return 0;
		}
		int* get_address_of_this() {
			return (int*)this;
		}
};

int main(void) {
	A obj;
	A obj2;
	cout << ((obj.isitme(&obj))? "It's me!": "It's not me.") << endl;
	cout << ((obj.isitme(&obj2))? "It's me!": "It's not me.") << endl;
	cout << "&obj: " << &obj << endl;
	cout << "This: " << obj.get_address_of_this() << endl;
	return 0;
}
