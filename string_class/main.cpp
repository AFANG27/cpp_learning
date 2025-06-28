#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
/*****************************************************************
*			string类 初始化赋值
* ****************************************************************/
	cout << "string类 初始化赋值" << endl;
	string s1("hellow");
	string s2(6, 'o');
	string s3 = "world";
	string s4;
	s4 = "ok!";
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

/*****************************************************************
*			string类 assign成员函数复制 以及部分复制
* ****************************************************************/
	cout << "\n" << "assign成员函数复制 以及部分复制" << endl;
	string base("hellow_cat");
	string copy1;
	string copy2;
	copy1.assign(base);
	copy2.assign(base, 7, 3);						//从 base中 下标为7的字符开始 往后复制3个字符 给 copy2
	cout << copy1 << endl;
	cout << copy2 << endl;


/*****************************************************************
*			string类 赋值和链接
* ****************************************************************/
	cout << "\n" << "string类 赋值和链接" << endl;
	string s_add1;
	s_add1 = s1 + s3;											//s_add1 = "hellowworld"
	cout << s_add1 << endl;
	string s_add2 = s_add1;										//s_add2 = s_add1 = "hellowworld"
	s_add1.append(s4);											//s_add1 = "hellowworldok!"
	cout << s_add1 << endl;
	s_add2.append(s_add1, 3, s_add1.size());					//s_add1中 下标为3开始 一直到s_add1.size() 复制添加在 s_add2 的后面
	cout << s_add2 << endl;

/*****************************************************************
*			string类 获取字符串长度
*****************************************************************/
	cout << "\n" << "string类 获取字符串长度" << endl;
	cout << s1.length() << endl;

/*****************************************************************
*			比较string
* 1.用关系运算符比较string的大小 <，<=，!= 
* 2.用成员函数compare比较string的大小
* 
* 注：返回值都是bool类型，成立返回true,否则返回false
*****************************************************************/
	cout << "\n" << "成员函数compare比较string的大小" << endl;
	string c1("dog!"), c2("dog!"), c3("dog");
	int f1 = c1.compare(c2);		//0		dog!==dog!	
	int f2 = c1.compare(c3);		//1		dog!>dog
	int f3 = c3.compare(c1);		//-1	dog<dog!
	int f4 = c1.compare(1,2,c3,0,3);	//c1 1-2 与 s3 0-3 比较			-1	og<dog
	int f5 = c1.compare(0,c1.size(),c3);//c1 0-end						 1	dog!>dog
	cout << "f1 = " << f1 << "; f2 = " << f2 << "; f3 = " << f3 << "; f4 = " << f4 << "; f5 = " << f5 << endl;


/*****************************************************************
*			子串 
* 1.成员函数 substr()					z1.substr(4,5); 是指 z1 的下标4开始5个字符
* 2.成员函数 swap()						z3.swap(z4);	是指 z3 和 z4 交换
* 3.成员函数 find()						在s1中--从前向后--查找”lo”第一次出现的地方，如果找到，返回”lo”开始的位置，即l所在位置的下标。如果找不到，返回string::npos（string中定义的静态常量）（npos应该就是 no position吧）
* 4.成员函数 rfind()					在s1中--从后向前--查找”lo”第一次出现的地方，如果找到，返回”lo”开始的位置，即l所在位置的下标。如果找不到，返回string::npos（string中定义的静态常量）（这个rfind的“r”应该就是reverse）
* 5.成员函数 find_first_of()			在s1中从前向后查找"abcd"中任何一个字符第一次出现的地方，如果找到，返回找到字母的位置，如果找不到，返回string::npos。
* 6.成员函数 find_last_of()				在s1中查找"abcd"中任何一个字符最后一次出现的地方，如果找到，返回找到字母的位置，如果找不到，返回string::npos。
* 7.成员函数 find_first_not_of()		在s1中--从前向后--查找不在"abcd"中的字母第一次出现的地方，如果找到，返回找到字母的位置，如果找不到，返回string::npos。
* 8.成员函数 find_last_not_of()			在s1中--从后向前--查找不在"abcd"中的字母第一次出现的地方，如果找到，返回找到字母的位置，如果找不到，返回string::npos。
*****************************************************************/
	cout << "\n" << "子串" << endl;
	cout << "成员函数 substr" << endl;
	string z1("hello world"), z2;
	z2 = z1.substr(4, 5);
	cout << s2 << endl;								//结果：o wor

	cout << "成员函数 swap()" << endl;
	string z3("hello world"), z4("really");
	z3.swap(z4);
	cout << z3 << endl;								//结果：really
	cout << z4 << endl;								//结果：hello world

	cout << "成员函数 find()" << endl;
	cout << z1.find("lo") << endl;

	cout << "成员函数 find_first_of()" << endl;
	cout << z1.find_first_of("abcd") << endl;

	cout << "成员函数 find_first_not_of()" << endl;
	cout << z1.find_first_not_of("abcd") << endl;

/*****************************************************************
*			删除string中的字符
* 1.成员函数erase()			s1.erase(5) 意思是去掉下标5及以后的字符
*****************************************************************/
	cout << "\n" << "删除string中的字符" << endl;
	string e1("hellow world");
	e1.erase(5);
	cout << e1 << endl;
	cout << e1.length() << endl;

/*****************************************************************
*			替换string中的字符
* 1.成员函数replace()			r1.replace(2, 3, "haha")  将s1中下标2开始的3个字符换成"haha"（这里就是把"llo"换成了"haha"）
*								s1.replace(2,3,"haha",0,2);将s1中下标2开始的3个字符换成"haha"中下标1开始的2个字符（这里就是把"llo"换成了"ha"）
*****************************************************************/
	cout << "\n" << "替换string中的字符" << endl;
	string r1("hello world"), r2("hello world");
	r1.replace(2, 3, "haha");
	cout << r1 << endl;

	r2.replace(2, 3, "haha", 0, 2);
	cout << r2 << endl;


/*****************************************************************
*			在string中插入字符
* 1.成员函数insert()
* 
*****************************************************************/
	cout << "\n" << "在string中插入字符" << endl;
	string in1("hello world");
	string in2("show insert");
	in1.insert(5, in2);											//将s2插入s1下标5的位置
	cout << in1 << endl;										//输出：helloshow insert world
	in1.insert(2, in2, 5, 3);									//将s2中下标5开始的3个字符插入s1下标2的位置
	cout << in1 << endl;										//输出：heinslloshow insert world



/*****************************************************************
*			转换成C语言式char*字符串
* 1.成员函数c_str()					s1.c_str()返回传统的const char* 类型字符串，且该字符串以'\0'结尾
* 2.成员函数data()					s1.data()返回一个char* （区别）类型的字符串，对s1的修改可能会使p1出错
*****************************************************************/
	cout << "\n" << "转换成C语言式char*字符串" << endl;
	cout << "成员函数c_str()" << endl;
	string ch1("hello world");
	printf("%s\n", ch1.c_str());

	cout << "成员函数data()" << endl;
	string ch2("hello world");
	const char* p1 = ch2.data();
	for (int i = 0;i < ch2.length();i++)
		printf("%c", *(p1 + i));
	cout << endl;

/*****************************************************************
*			字符串流处理
* 除了标准流和文件流输入输出外，还可以从string进行输入输出；
　　类似istream和ostream进行标准流输入输出，我们用istringstream和ostringstream进行字符串上的输入输出，也称为内存输入输出。
　　#include<string>
　　#include<iostream>
　　#include<sstream>
*****************************************************************/
	cout << "\n" << "字符串流处理" << endl;
	string input("Input test 123 4.7 A");
	istringstream inputString(input);
	string string1, string2;
	int i;
	double d;
	char c;
	inputString >> string1 >> string2 >> i >> d >> c;
	cout << string1 << endl << string2 << endl;
	cout << i << endl << d << endl << c << endl;
	long L;
	if (inputString >> L)
	{
		cout << "long\n";
	}
	else
	{
		cout << "empty\n";
	}
	ostringstream outputString;
	int a = 10;
	outputString << "This " << a << " ok" << endl;				//将 "This "  a  " ok" 这些字符串 打包一起进入流（outputString）里面
	cout << outputString.str() << endl;									//通过outputString.str() 把流里面的字符串拿出来


/*****************************************************************
*			流读取cin 以及 getline
*****************************************************************/
	cout << "\n" << "流读取cin 以及 getline" << endl;
	string s5;
	string s6;
	cin >> s5;
	cout << s5 << endl;
	cin.ignore();				//在getline之前使用cin.ignore()函数来将cin的残留回车符清除，不清除会跳过getline。
	getline(cin, s6);
	cout << s6 << endl;


	return 0;
}
