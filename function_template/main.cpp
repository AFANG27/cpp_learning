#include<iostream>

using namespace std;

/*****************************************************************
*			模板 相加函数
* ****************************************************************/
template <class T>
T add(T& a, T& b) {
	
	return a + b;
}

/*****************************************************************
*			模板 相加函数
* ****************************************************************/
template <class T>
void Swap(T& a, T& b) {
	T c = 0;
	c = a;
	a = b;
	b = c;
}

/*****************************************************************
*			模板 求数组最大元素函数
* ****************************************************************/
template <class T>
T MaxElement(T a[], int size) {
	T MaxTemp = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > MaxTemp)
			MaxTemp = a[i];
	}

	return MaxTemp;
}


int main() {
	int a, b;
	double c, d;
	int arr[6] = { 5,34,23,54,23,2 };

	a = 1;
	b = 2;
	c = 3.6;
	d = 4.0;
	cout << "a + b = " << add(a, b) << endl;
	cout << "c + d = " << add(c, d) << endl;

	Swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "MaxElenment = " << MaxElement(arr, 6) << endl;

	return 0;
}

