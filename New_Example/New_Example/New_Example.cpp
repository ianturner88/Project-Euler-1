#include <iostream>

int main(void)
{
	int example[10] = {1,4,5,6};

	for (int i = 0; i < 4; i++)
	{
		std::cout << example[i] << std::endl;
	}

	std::cout << "Break point: " << std::endl;

	int* example_two = new int[1000000]{9};

	int counter = 0;

	for (int i = 0; i < 1000000; i++)
	{
		std::cout << counter << ":  "<< example_two[i] << std::endl;
	}

	getchar();
}