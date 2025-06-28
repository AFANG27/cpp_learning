#include<iostream>

using namespace std;

int main()
{
	int i, j = 1;
	for (i = 1;i < 10;i++)
	{
		for (j = 1;j < i + 1;j++)
		{
			cout << i << "*" << j << "=" << i * j<<"  ";
		}
		cout << endl;
	}
	return 0;

}