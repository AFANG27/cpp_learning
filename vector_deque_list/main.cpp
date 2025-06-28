
/***************************************************************************************
*			vector������ϸ�Ľ��ܣ�https://zhuanlan.zhihu.com/p/648650828
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
*			��vectorʵ��һά����
* **************************************************************************************/

	int a[5] = { 1,2,3,4,5 };
	vector<int> v1(a, a + 5);									//������������vector
	cout << "(1) " << v1.end() - v1.begin() << endl;			//vector�ĵ�������������ʵ����� ��-���ǺϷ��� ��������� ���ɵó�v���������Ԫ�ظ���

	cout << "(2) ";
	print_vector(v1.begin(),v1.end());							

	v1.insert(v1.begin()+2, 13);									//�ڵڶ���Ԫ�غ������Ԫ��
	cout << "(3) ";
	print_vector(v1.begin(), v1.end());

	v1.erase(v1.begin()+2);										//ɾ��������ָ���Ԫ��
	cout << "(4) ";
	print_vector(v1.begin(), v1.end());

	vector<int> v2(4, 100);										//���캯���������ĸ�Ԫ��ֵΪ100��vector
	cout << "(5) ";
	print_vector(v2.begin(), v2.end());

	v2.insert(v2.begin(), v1.begin()+2, v1.begin()+4);			//��v��һ�β���v2�Ŀ�ͷ
	cout << "(6) ";
	print_vector(v2.begin(), v2.end());

	v2.erase(v2.begin(),v2.begin()+2);							//ɾ����v��һ������
	cout << "(7) ";
	print_vector(v2.begin(), v2.end());					

/***************************************************************************************
*			��vectorʵ�ֶ�ά����
* **************************************************************************************/
	vector<vector<int>> v3(3);									//v��3��Ԫ�أ�ÿ��Ԫ�ض���vector<int>����
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
*			deque		˫�����
��������������vector�Ĳ�����������deque
����deque����push_front����Ԫ�ز��뵽ǰ�棩��pop_front��ɾ����ǰ���Ԫ�أ����������Ӷ���O(1)
* **************************************************************************************/


/***************************************************************************************
*			list����	˫������
	���ĵײ�ʵ�ֲ������飬���Բ�֧�������ȡ
	���κ�λ�ò���ɾ�����ǳ���ʱ�䣬��֧�������ȡ
	���˾�������˳�����������еĳ�Ա�������⣨���vector�е������У�����֧��8����Ա������
	push_front����ǰ�����
	pop_front��ɾ��ǰ���Ԫ��
	sort������list��֧��STL���㷨sort�����Ͼ�����list������������֮�࣬STL���sort�㷨ֻ֧�ֿ���������ʵĵ�������
	remove��ɾ����ָ��ֵ��ȵ�����Ԫ��
	unique��ɾ�����к�ǰһ��Ԫ����ͬ��Ԫ�أ�Ҫ����Ԫ�ز��ظ�����unique֮ǰ����Ҫsort��
	merge���ϲ�������������ձ��ϲ����Ǹ�
	reverse���ߵ�����
	splice����ָ��λ��ǰ�������һ�����е�һ������Ԫ�أ�������һ������ɾ���������Ԫ��
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

	lst1.remove(2);							//ɾ�����к�A(2)��ȵ�Ԫ��
	cout << "(5) ";
	PrintList(lst1);
	cout << endl;

	lst2.unique();							//ɾ�����к�ǰһ��Ԫ����ȵ�Ԫ��
	cout << "(6) ";
	PrintList(lst2);
	cout << endl;

	lst1.merge(lst2);						//�ϲ�lst2��lst1�����lst2
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
	lst1.splice(p1, lst2, p2, p3);					//��[p2,p3)����p1֮ǰ������lst2��ɾ��[p2,p3)
	cout << "(10) ";
	PrintList(lst1);
	cout << endl;

	cout << "(11) ";
	PrintList(lst2);
	cout << endl;

	return 0;
}
