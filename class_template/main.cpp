#include<iostream>

using namespace std;


/*****************************************************************
*			��ģ�� 
* ****************************************************************/
template<class T1, class T2>
class Pair
{
public:
	T1 key;
	T2 value;
	Pair(T1 k, T2 v) :key(k), value(v) { };
	bool operator < (const Pair<T1, T2> & p) const;
};
template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> & p) const
{
	return key < p.key;
}


/*****************************************************************
*			����ģ����Ϊ��ģ���Ա
* ****************************************************************/
template<class T>
class A {
public:
	template<class T2>
	void Func(T2 t) { cout << t; }
};

/*****************************************************************
*			��ģ��������Ͳ���
* ****************************************************************/
template <class T, int size>
class CArray {
	T array[size];
public:
	void Print()
	{
		for (int i = 0; i < size; ++i)
			cout << array[i] << endl;
	}
};


int main() {
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value << endl;

	A<int> a;
	a.Func('K');
	a.Func("hellow");

	CArray<double, 40> a2;
	CArray<int, 50> a3;

	a2.Print();
	a3.Print();
	return 0;
}