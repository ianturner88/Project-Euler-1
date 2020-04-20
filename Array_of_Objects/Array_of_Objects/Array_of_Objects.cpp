#include <iostream> 

class MyClass {
    int x;
public:
    void setX(int i) { x = i; }
    int getX() { return x; }
};

void main()
{
    MyClass obs[4][4];
 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            obs[i][j].setX(i);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << "obs[" << i << "].getX(): " << obs[i][j].getX() << "\n";
        }
    }
     
    getchar();
}