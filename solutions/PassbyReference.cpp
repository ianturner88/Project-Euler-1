/* #include <iostream>
using namespace std;

void passReference (int &x, int &y);

int main ()
{
    int value = 10;
    int dog = 400;
    passReference(value, dog);

    cout << value << " " << dog << endl;

return 0;
}

void passReference (int &x, int &y){

    x = 2;
    y = 1;
}
*/
/////////////////////


#include <iostream>
using namespace std;

void PassByReference(int &x, int &y);

int main()
{
	int n1 = 10;
	int n2 = 20;
	
	PassByReference (n1, n2);
	
	cout << n1 << endl;
	cout << n2;
}

void PassByReference(int &x, int &y)
{
	x = 2;
	y = 1;
}
