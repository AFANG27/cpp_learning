/*************************************************************************************************************************
*				multimap的用法
	注：multimap容器中的元素，都是pair形式的，也是排序容器。
	mulitmap<T1,T2> mp;		则mp里的元素都是如下类型：
	struct
 {
     T1 first;//关键字
     T2 second;//值
 };
	multimap中的元素按照first排序，并可以按first进行查找
	multimap具有自动排序的功能，它的底层和set一样是采用平衡树实现的，而multimap中的每个节点存储的是一对信息，包括一个键和一个值。
	而set中的每个节点存储的是一个信息，只有一个键，但是每个键值也是唯一的。set表示的是集合的概念。
	缺省的排序规则是“a.first < b.first”为true，则a排在b前面。就是说默认就是这样排序。


	map与multimap的区别在于：
　　1、map不能有重复的元素。
　　2、map可以使用[]，下标为关键字，返回值为first和关键字相同的元素的second。
　　3、插入元素可能失败。
　　（与set和multiset的差别差不多）



	若pairs为map模版类的对象，
	pairs[key]		返回对关键字等于key的元素的值(second成员变量)的引用。若没有关键字为key的元素，则会往pairs里插入一个关键字为key的元素，其值用无参构造函数初始化，并返回其值的引用
		如 :
	map<int, double>pairs;
	则
		pairs[50] = 5;会修改pairs中关键字为50的元素，使其值变成5若不存在关键字等于50的元素，则插入此元素，并使其值变为5。
************************************************************************************************************************/
#include<iostream>
#include<map>
#include<string>
using namespace std;

class CStudent
{
public:
	struct CInfo		//类的内部还可以定义类
	{
		int id;
		string name;
	};
	int score;
	CInfo info;			//学生的其他信息
};

typedef multimap<int, CStudent::CInfo> MAP_STD;

template<class Key,class Value>
ostream& operator <<(ostream& o, const pair<Key, Value>& p)
{
	o << "(" << p.first << "," << p.second << ")";
	return o;
}


int main() {
/*************************************************************************************************************************
*				map的应用
************************************************************************************************************************/
	typedef map<int, double, less<int>>mmid;
	mmid pairs;
	cout << "(1) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(15,2.7));
	pairs.insert(make_pair(15, 99.3));			//make_pair生成一个pair对象 但 因为map容器不能重复key所以插入失败
	cout << "(2) " << pairs.count(15) << endl;	//结果： 1
	pairs.insert(mmid::value_type(20, 9.3));
	mmid::iterator i;
	cout << "(3) ";
	for (i = pairs.begin();i != pairs.end();i++)
		cout << *i << ",";
	cout << endl;
	cout << "(4) ";
	int n = pairs[40];							//如果没有关键字为40的元素，则插入一个
	cout << n << " ";							//返回对关键字等于key的元素的值(second成员变量)的引用   second未赋值 所以 返回值n = 0；
	for (i = pairs.begin();i != pairs.end();i++)
		cout << *i << ",";
	cout << endl;
	cout << "(5) ";
	pairs[15] = 6.28;							//把关键字为15的元素值改成6.28
	for (i = pairs.begin();i != pairs.end();i++)
		cout << *i << ",";
	cout << endl;


	/*************************************************************************************************************************
						multimap的应用
	一个学生成绩录入和查询系统，接受以下两种输入：
		Add name Id score
		Query score
	name是个不超过16字符的字符串，中间没有空格，代表学生姓名。
	Id是个整数，代表学号。
	score是个整数，代表分数。学号不会重复，分数和姓名都可能重复。
	两种输入交替出现。第一种输入表示要添加一个学生的信息，碰到这种输入，就记下学生的姓名、id和分数。
	第二种输入表示要查询，碰到这种输入，就输出已有记录中分数比score低的最高分获得者的姓名、学号和分数。
	如果有多个学生都满足条件，就输出学号最大的那个学生的信息。如果找不到满足条件的学生，则输出“nobody”
	输入样例：
		A Jack 12 78
		Q 78
		Q 81
		A Percy 9 81
		A marry 8 81
		Q 82
		A Tom 11 79
		Q 80
		Q 81
	输出样例：
		Nobody
		Jack 12 78
		Percy 9 81
		Tom 11 79
		Tom 11 79
*************************************************************************************************************************/
	MAP_STD mp;
	CStudent st;
	string cmd;
	while (cin >> cmd)
	{
		if (cmd == "A")
		{
			cin >> st.info.name >> st.info.id >> st.score;
			mp.insert(MAP_STD::value_type(st.score, st.info));		//pair模板类的对象来存放信息给map	//using value_type = pair<const _Kty, _Ty>;
		}
		else if (cmd == "Q")
		{
			int score;
			cin >> score;
			MAP_STD::iterator p = mp.lower_bound(score);		//mp.lower_bound(score) lower_bound的返回值是某个键的迭代器（若该键不存在，则返回挨着这个键的下一个键的迭代器），这里返回的是成绩大于等于score的迭代器
			if (p != mp.begin())								//找到了
			{
				--p;											//因为multimap/map容器存放数据会按照 first 从小到大来排 所 --p就是比查找到比score低的最高分的那个分数
				score = p->first;							//比要查询分数低的最高分
				MAP_STD::iterator maxp = p;
				int maxId = p->second.id;
				for (;p != mp.begin() && p->first == score;--p)
				{											//遍历所有成绩和score相等的学生，开始比较学号的差别
					if (p->second.id > maxId)
					{
						maxp = p;
						maxId = p->second.id;
					}
				}
				if (p->first == score)
				{											//如果上面循环是因为 p==mp.begin() 而终止，则p指向的元素还要处理
					if (p->second.id > maxId)
					{
						maxp = p;
						maxId = p->second.id;
					}
				}
				cout << maxp->second.name << " " << maxp->second.id << " " << maxp->first << endl;
			}
			else
			{
				cout << "Noboby" << endl;
			}
		}
	}
	return 0;
}