#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
#include<list>
using namespace std;

/***************************************************************************************
*			函数对象:	若一个类重载了运算符“()”，则该类的对象就成为函数对象
*	常用函数对象（结合了类模板）
	<functional> 头文件中定义了一些常用的函数对象（结合了类模板），包括：
	std::function：一个通用的多态函数封装器。
	std::bind：用于绑定函数的参数。
	std::plus、std::minus、std::multiplies、std::divides、std::modulus：基本的算术操作。
	std::equal_to、std::not_equal_to、std::greater、std::less、std::greater_equal、std::less_equal：比较操作。
	std::unary_negate、std::binary_negate：逻辑否定操作。
	std::logical_and、std::logical_or、std::logical_not：逻辑操作。
* **************************************************************************************/

class CMyAverage{			//函数对象
public:
	double operator()(int a1, int a2, int a3)
	{
		return (double)(a1 + a2 + a3) / 3;
	}
};

class myless {				//函数对象
public:
	bool operator()(const int& c1, const int& c2) {
		return (c1 % 10) < (c2 % 10);							//比较个位数大小
	}
};

class mymax {				//函数对象
public:
	bool operator()(const int& c1, const int& c2) {
		return (c1 % 10) > (c2 % 10);							//比较个位数大小
	}
};




int sumSquares(int total, int value)
{
	return total + value * value;
}

template<class T>
void PrintInterval(T first, T last) {
	for (;first != last;++first)
	{
		cout << *first << " ";
	}
	cout << endl;
}

template<class T>				//函数对象 + 类模板 结合写法
class SumPowers {
private:
	int power;
public:
	SumPowers(int p):power(p){}
	const T operator()(const T& total, const T& value) 
	{
		T v = value;
		for (int i = 0;i < power - 1;i++)
		{
			v = v * value;
		}
		return total + v;
	}
};



/***************************************************************************************
*			T My_Compare(T first,T last, Pred p) 模板说明：
*注：void sort(Compare op)的函数模板  是将list中的元素 按op规定的比较方法 来进行排序
* T My_Compare(T first,T last, Pred p) 模板类似于sort的模板 按p规定的比较方法 来进行排序
*   注： p放的是函数对象 也可以是函数 函数指针
* **************************************************************************************/
template<class T,class Pred>
T My_Compare(T first,T last, Pred p) {
	T temp_max = first;
	for (;first != last;++first)
	{
		if (p(*temp_max, *first))
		{
			temp_max = first;
		}
	}
	return temp_max;
}



template<class T>
void Print(T first, T last) {				//输出容器内容的函数模板
	for (;first != last;++first) 
	{
		cout << *first << ",";
	}
}


int main() {
	CMyAverage average;			//函数对象
	cout << average(3, 2, 3);

	const int SIZE = 10;
	int a1[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v(a1, a1 + SIZE);

/***************************************************************************************
*在int result = accumulate(v.begin(),v.end(),0,SumSquares) 这段代码中，实例化出：
* int accumlate(vector<int>::iterator first, vector<int>::iterator last, int init, int(*op)(int,int))
{
    for (; first != last; ++first)
    {
        init = op(init,*first);
    }
    return init;
}

而在accumulate(v.begin(),v.end(),0,SumPowers<int>(3));实例化出：
int accumlate(vector<int>::iterator first, vector<int>::iterator last, int init, SumPowers<int>op)
{
    for (; first != last; ++first)
    {
        init = op(init,*first);
    }
    return init;
}
* **************************************************************************************/

	cout << "(1) ";
	PrintInterval(v.begin(), v.end());
	int result = accumulate(v.begin(), v.end(), 0, sumSquares);					//Tp accumulate(inputlterator _first, inputlterator _last,Tp init,BinaryOperation _binary_op)
																				//调用accumulate时，和binary_op对应的实参可以是个函数指针 函数 或函数对象
	cout << "(2) 平方和" << result << endl;
	result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(3));				// ***本节的重点！！！！
	cout << "(3) 立方和" << result << endl;
	result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(4));
	cout << "(4) 四次方和" << result << endl;

/***************************************************************************************
*			greater的应用
* list有两个sort成员函数
　　void sort();					将list中的元素按“<”规定的比较方法升序排列。

　　template<class Compare>
	void sort(Compare op)			将list中的元素 按op规定的比较方法 升序排序。即要比较x，y大小时，看op(x,y)的返回值，为true则认为x小于y
* **************************************************************************************/
	const int Size = 5;
	int a[Size] = { 5,21,14,2,3 };
	list<int> lst(a, a + Size);
	lst.sort(myless());
	Print(lst.begin(), lst.end());
	cout << endl;
	lst.sort(greater<int>());						//greater<int>()是个对象
	Print(lst.begin(), lst.end());
	cout << endl;

	int b[] = { 35,7,13,19,12 };
	list<int> lstb(b, b + 5);
	cout << *My_Compare(b, b + 5, myless()) << endl;							//输出：19
	cout << *My_Compare(b, b + 5, mymax()) << endl;								//输出：12
	cout << *My_Compare(lstb.begin(), lstb.end(), myless()) << endl;			//输出：19
	cout << *My_Compare(lstb.begin(), lstb.end(), mymax()) << endl;				//输出：12
	return 0;

}

