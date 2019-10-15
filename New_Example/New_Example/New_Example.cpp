#include <iostream>

int main(void)
{
	int example[10] = {1,4,5,6};

	for (int i = 0; i < 4; i++)
	{
		std::cout << example[i] << std::endl;
	}

	std::cout << "Break point: " << std::endl;

	int* example_two = new int[100000]{ 0 };

	int counter = 0;

	for (int i = 0; i < 100000; i++)
	{
		std::cout << counter << ":  "<< example_two[i] << std::endl;
		counter++;
	}

	getchar();
}