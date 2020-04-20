#include <iostream> 

class MyClass {
    int x;
public:
    void setX(int i) { x = i; }
    int getX() { return x; }
};

void main()
{
    MyClass obs[4];
    int i;

    for (i = 0; i < 4; i++)
        obs[i].setX(i);

    for (i = 0; i < 4; i++)
        std::cout << "obs[" << i << "].getX(): " << obs[i].getX() << "\n";

    getchar();
}