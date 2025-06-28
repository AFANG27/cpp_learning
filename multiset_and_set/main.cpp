/*************************************************************************************************************************
*				set / multiset 容器基本概念：
	set 和 multiset 是 C++ 标准库中的关联容器，它们使用红黑树（Red-Black Tree）作为底层数据结构来存储元素。
	这些容器中的元素是自动按照一定的规则进行排序的，不允许有重复的元素（std::set），或允许有重复的元素（std::multiset）                       
	原文链接：https://blog.csdn.net/qq_46403377/article/details/132007636

				set / multiset 容器的成员函数汇总：
	1. s.begin()  // 起始迭代器，指向第一个元素
	2. s.end()    // 结束迭代器，指向最后一个元素的后面一个虚拟位置，用于辅助遍历
	3. s.clear()  // 删除set容器中的所有的元素
	4. s.empty()  // 判断set容器是否为空
	5. s.insert() // 插入一个元素
	6. s.erase()  // 删除一个元素
	7. s.size()   // 返回当前 set 容器中的元素个数
	8. s.swap()   // 交换两个集合
	9. s.find()   // 查找 key值元素
	10. s.count() // 统计 key值元素，主要在 multiset 容器上使用
	11. s.empty() // 判断set容器是否为空
	12.iterator lower_bound(const T & val);查找一个最大的位置 it,使得[begin(),it)中所有的元素都比 val 小。
	13.iterator upper_bound(const T & val);查找一个最小的位置 it,使得[it,end())中所有的元素都比 val 大。

	注：set / multiset的迭代器与指针不同：　multiset上的迭代器可++，--，用!=和==比较，不可比大小，不可加减整数，不可相减。
* ***********************************************************************************************************************/
#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

class rulel {		//定义了一个函数对象 用于后面的排序规则
public:
	bool operator()(const int & a, const int & b)const		//后面不加const就会报错：“bool rulel::operator ()(const int &,const int &)”: 不能将“this”指针从“const rulel”转换为“rulel &”	
	{														//前面使用const 表示返回值为const		后面加 const表示函数不可以修改class的成员													
		return (a % 10) < (b % 10);
	}//返回值为true说明a必须排在b前面
};


struct Student
{
	char name[20];
	int id;
	int score;
};
Student student[] =
{
	{"Jack",112,78 },
	{"Mary",102,85 },
	{"Ala",333,92 },
	{"Zero",101,70 },
	{"Cindy",102,78 }
};
struct rule
{
	bool operator()(const Student& s1, const Student& s2) const
	{
		if (s1.score != s2.score){
			return s1.score > s2.score;
		}
		else {
			return(strcmp(s1.name, s2.name) < 0);
		}
	}
};



int main() {
/*************************************************************************************************************************
*			multiset 简单用法
************************************************************************************************************************/
	multiset<int>st;
	int a[10] = { 1,14,12,13,7,13,21,19,8,8 };
	for (int i = 0; i < 10;i++) 
	{
		st.insert(a[i]);
	}
	multiset<int>::iterator i;
	for (i = st.begin();i != st.end();i++)
	{
		cout << *i << ",";					//输出：1, 7, 8, 8, 12, 13, 13, 14, 19, 21,
	}
	cout << endl;
	i = st.find(22);
	if (i == st.end()){
		cout << "Not Found" << endl;
	}else {
		cout << "Found:" << *i << endl;
	}
	i = st.lower_bound(13);					//都在13前面，复杂度log(n)   返回指向13的迭代器
	cout << *i << endl;
	i = st.upper_bound(8);					//都在8后面，复杂度log(n)    返回指向12的迭代器
	cout << *i << endl;
	st.erase(i);
	for (i = st.begin();i != st.end();i++) {
		cout << *i << ",";
	}
	cout << endl;

/*************************************************************************************************************************
*			multiset 自定义排序规则
************************************************************************************************************************/
	multiset<int, greater<int>>st1;
	int a1[10] = { 1,14,12,13,7,13,21,19,8,8 };
	for (int i = 0;i < 10;i++)
	{
		st1.insert(a1[i]);
	}
	multiset<int, greater<int>>::iterator it;
	for (it = st1.begin();it != st1.end();it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	multiset<int, rulel>st2;
	for (int i = 0;i < 10;i++)
	{
		st2.insert(a1[i]);
	}
	multiset<int, rulel>::iterator p;
	for (p = st2.begin();p != st2.end();p++)
	{
		cout << *p << ",";
	}
	cout << endl;
	p = st2.find(13);
	cout << *p << endl;
	
/*************************************************************************************************************************
*			multiset 结构体及其自定义排序规则
************************************************************************************************************************/
	multiset<Student, rule> st3;
	for (int i = 0;i < 5;i++)
	{
		st3.insert(student[i]);
	}
	multiset<Student, rule>::iterator p3;
	for (p3 = st3.begin();p3 != st3.end();p3++) {
		cout << p3->score << " " << p3->name << " " << p3->id << endl;
	}

	Student s = { "Mary",1000,85 };
	p3 = st3.find(s);						 //因为没比较id，所以。。。找到了
	if (p3 != st3.end())
	{
		cout << p3->score << " " << p3->name << " " << p3->id << endl;
	}
/*************************************************************************************************************************
*			set 的基本用法
************************************************************************************************************************/
	typedef set<int>::iterator IT;
	set<int> st4;
	int a4[10] = { 1,2,3,8,7,7,5,6,8,12 };
	for (int i = 0;i != 10; i++) {
		st4.insert(a4[i]);
	}
	cout << st4.size() << endl;
	
	IT p4;
	for (p4 = st4.begin();p4 != st4.end();p4++)
	{
		cout << *p4 << " ";
	}
	cout << endl;

	pair<IT, bool> result = st4.insert(2);
	/*****************************************************************************
						pair<IT,bool>
							等价于
						struct
						{
						set<int>::iterator first;
						bool second;
						}
	***************************************************************************** */
	if (!result.second)				//条件成立说明插入不成功
	{
		cout << *result.first << " already exists." << endl;
	}
	else {
		cout << *result.first << " inserted." << endl;			//结果：2 already exists.  相同数据不能插入
	}
	return 0;
}