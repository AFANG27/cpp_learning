
/***************************************************************************************
*			vector更加详细的介绍：https://zhuanlan.zhihu.com/p/648650828
* **************************************************************************************/
#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
using namespace std;

template<class T>
void print_vector(T s,T e) {
	for (;s != e;s++)
		cout << *s << " ";
	cout << endl;
}

class A{
private: 
	int n;
public:
	A(int n_) { n = n_; }
	friend bool operator<(const A & al, const A & a2);
	friend bool operator==(const A & al, const A & a2);
	friend ostream & operator<<(ostream& o, const A& a);
};

bool operator<(const A & a1, const A & a2) {
	return a1.n < a2.n;
}

bool operator==(const A& a1, const A& a2) {
	return a1.n == a2.n;
}

ostream & operator<<(ostream& o, const A& a) {
	o << a.n;
	return o;
}

template<class T>
void PrintList(const list<T>& lst){
	typename list<T>::const_iterator i;
	i = lst.begin();
	for (i = lst.begin();i != lst.end();i++)
	{
		cout << *i << ",";
	}
}



int main() {
/***************************************************************************************
*			用vector实现一维数组
* **************************************************************************************/

	int a[5] = { 1,2,3,4,5 };
	vector<int> v1(a, a + 5);									//用数组来构造vector
	cout << "(1) " << v1.end() - v1.begin() << endl;			//vector的迭代器是随机访问迭代器 “-”是合法的 迭代器相减 即可得出v容器里面的元素个数

	cout << "(2) ";
	print_vector(v1.begin(),v1.end());							

	v1.insert(v1.begin()+2, 13);									//在第二个元素后面插入元素
	cout << "(3) ";
	print_vector(v1.begin(), v1.end());

	v1.erase(v1.begin()+2);										//删除迭代器指向的元素
	cout << "(4) ";
	print_vector(v1.begin(), v1.end());

	vector<int> v2(4, 100);										//构造函数，创造四个元素值为100的vector
	cout << "(5) ";
	print_vector(v2.begin(), v2.end());

	v2.insert(v2.begin(), v1.begin()+2, v1.begin()+4);			//将v的一段插入v2的开头
	cout << "(6) ";
	print_vector(v2.begin(), v2.end());

	v2.erase(v2.begin(),v2.begin()+2);							//删除了v的一个区间
	cout << "(7) ";
	print_vector(v2.begin(), v2.end());					

/***************************************************************************************
*			用vector实现二维数组
* **************************************************************************************/
	vector<vector<int>> v3(3);									//v有3个元素，每个元素都是vector<int>容器
	for (int i = 0;i < v3.size();i++) 
	{
		for (int j = 0;j < 4;j++) 
		{
			v3[i].push_back(j);
		}
	}
	cout << "(8) " << endl;
	for (int i = 0;i < v3.size();i++)
	{
		for (int j = 0;j < 4;j++)
		{
			cout << v3[i][j] << " ";
		}
		cout << endl;
	}

/***************************************************************************************
*			deque		双向队列
　　所有适用于vector的操作都适用于deque
　　deque还有push_front（将元素插入到前面）和pop_front（删除最前面的元素）操作，复杂度是O(1)
* **************************************************************************************/


/***************************************************************************************
*			list容器	双向链表
	它的底层实现不是数组，所以不支持随机存取
	在任何位置插入删除都是常数时间，不支持随机存取
	除了具有所有顺序容器都具有的成员函数以外（差不多vector有的它都有），还支持8个成员函数：
	push_front：在前面插入
	pop_front：删除前面的元素
	sort：排序（list不支持STL的算法sort）（毕竟这是list，而不是数组之类，STL库的sort算法只支持可以随机访问的迭代器）
	remove：删除和指定值相等的所有元素
	unique：删除所有和前一个元素相同的元素（要做到元素不重复，则unique之前还需要sort）
	merge：合并两个链表，并清空被合并的那个
	reverse：颠倒链表
	splice：在指定位置前面插入另一链表中的一个或多个元素，并在另一链表中删除被插入的元素
* **************************************************************************************/
	list<A> lst1, lst2;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(2);

	lst2.push_back(10);
	lst2.push_front(20);
	lst2.push_back(30);
	lst2.push_back(30);
	lst2.push_back(30);
	lst2.push_front(40);
	lst2.push_back(40);

	cout << "(1) ";
	PrintList(lst1);
	cout << endl;

	cout << "(2) ";
	PrintList(lst2);
	cout << endl;

	lst2.sort();
	cout << "(3) ";
	PrintList(lst2);
	cout << endl;

	lst2.pop_front();
	cout << "(4) ";
	PrintList(lst2);
	cout << endl;

	lst1.remove(2);							//删除所有和A(2)相等的元素
	cout << "(5) ";
	PrintList(lst1);
	cout << endl;

	lst2.unique();							//删除所有和前一个元素相等的元素
	cout << "(6) ";
	PrintList(lst2);
	cout << endl;

	lst1.merge(lst2);						//合并lst2到lst1并清空lst2
	cout << "(7) ";
	PrintList(lst1);
	cout << endl;

	cout << "(8) ";
	PrintList(lst2);
	cout << endl;

	lst1.reverse();
	cout << "(9) ";
	PrintList(lst1);
	cout << endl;

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	list<A>::iterator p1, p2, p3;
	p1 = find(lst1.begin(), lst1.end(), 3);
	p2 = find(lst2.begin(), lst2.end(), 200);
	p3 = find(lst2.begin(), lst2.end(), 400);
	lst1.splice(p1, lst2, p2, p3);					//将[p2,p3)插入p1之前，并从lst2中删除[p2,p3)
	cout << "(10) ";
	PrintList(lst1);
	cout << endl;

	cout << "(11) ";
	PrintList(lst2);
	cout << endl;

	return 0;
}
