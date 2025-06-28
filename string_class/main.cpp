#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
/*****************************************************************
*			string�� ��ʼ����ֵ
* ****************************************************************/
	cout << "string�� ��ʼ����ֵ" << endl;
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
*			string�� assign��Ա�������� �Լ����ָ���
* ****************************************************************/
	cout << "\n" << "assign��Ա�������� �Լ����ָ���" << endl;
	string base("hellow_cat");
	string copy1;
	string copy2;
	copy1.assign(base);
	copy2.assign(base, 7, 3);						//�� base�� �±�Ϊ7���ַ���ʼ ������3���ַ� �� copy2
	cout << copy1 << endl;
	cout << copy2 << endl;


/*****************************************************************
*			string�� ��ֵ������
* ****************************************************************/
	cout << "\n" << "string�� ��ֵ������" << endl;
	string s_add1;
	s_add1 = s1 + s3;											//s_add1 = "hellowworld"
	cout << s_add1 << endl;
	string s_add2 = s_add1;										//s_add2 = s_add1 = "hellowworld"
	s_add1.append(s4);											//s_add1 = "hellowworldok!"
	cout << s_add1 << endl;
	s_add2.append(s_add1, 3, s_add1.size());					//s_add1�� �±�Ϊ3��ʼ һֱ��s_add1.size() ��������� s_add2 �ĺ���
	cout << s_add2 << endl;

/*****************************************************************
*			string�� ��ȡ�ַ�������
*****************************************************************/
	cout << "\n" << "string�� ��ȡ�ַ�������" << endl;
	cout << s1.length() << endl;

/*****************************************************************
*			�Ƚ�string
* 1.�ù�ϵ������Ƚ�string�Ĵ�С <��<=��!= 
* 2.�ó�Ա����compare�Ƚ�string�Ĵ�С
* 
* ע������ֵ����bool���ͣ���������true,���򷵻�false
*****************************************************************/
	cout << "\n" << "��Ա����compare�Ƚ�string�Ĵ�С" << endl;
	string c1("dog!"), c2("dog!"), c3("dog");
	int f1 = c1.compare(c2);		//0		dog!==dog!	
	int f2 = c1.compare(c3);		//1		dog!>dog
	int f3 = c3.compare(c1);		//-1	dog<dog!
	int f4 = c1.compare(1,2,c3,0,3);	//c1 1-2 �� s3 0-3 �Ƚ�			-1	og<dog
	int f5 = c1.compare(0,c1.size(),c3);//c1 0-end						 1	dog!>dog
	cout << "f1 = " << f1 << "; f2 = " << f2 << "; f3 = " << f3 << "; f4 = " << f4 << "; f5 = " << f5 << endl;


/*****************************************************************
*			�Ӵ� 
* 1.��Ա���� substr()					z1.substr(4,5); ��ָ z1 ���±�4��ʼ5���ַ�
* 2.��Ա���� swap()						z3.swap(z4);	��ָ z3 �� z4 ����
* 3.��Ա���� find()						��s1��--��ǰ���--���ҡ�lo����һ�γ��ֵĵط�������ҵ������ء�lo����ʼ��λ�ã���l����λ�õ��±ꡣ����Ҳ���������string::npos��string�ж���ľ�̬��������nposӦ�þ��� no position�ɣ�
* 4.��Ա���� rfind()					��s1��--�Ӻ���ǰ--���ҡ�lo����һ�γ��ֵĵط�������ҵ������ء�lo����ʼ��λ�ã���l����λ�õ��±ꡣ����Ҳ���������string::npos��string�ж���ľ�̬�����������rfind�ġ�r��Ӧ�þ���reverse��
* 5.��Ա���� find_first_of()			��s1�д�ǰ������"abcd"���κ�һ���ַ���һ�γ��ֵĵط�������ҵ��������ҵ���ĸ��λ�ã�����Ҳ���������string::npos��
* 6.��Ա���� find_last_of()				��s1�в���"abcd"���κ�һ���ַ����һ�γ��ֵĵط�������ҵ��������ҵ���ĸ��λ�ã�����Ҳ���������string::npos��
* 7.��Ա���� find_first_not_of()		��s1��--��ǰ���--���Ҳ���"abcd"�е���ĸ��һ�γ��ֵĵط�������ҵ��������ҵ���ĸ��λ�ã�����Ҳ���������string::npos��
* 8.��Ա���� find_last_not_of()			��s1��--�Ӻ���ǰ--���Ҳ���"abcd"�е���ĸ��һ�γ��ֵĵط�������ҵ��������ҵ���ĸ��λ�ã�����Ҳ���������string::npos��
*****************************************************************/
	cout << "\n" << "�Ӵ�" << endl;
	cout << "��Ա���� substr" << endl;
	string z1("hello world"), z2;
	z2 = z1.substr(4, 5);
	cout << s2 << endl;								//�����o wor

	cout << "��Ա���� swap()" << endl;
	string z3("hello world"), z4("really");
	z3.swap(z4);
	cout << z3 << endl;								//�����really
	cout << z4 << endl;								//�����hello world

	cout << "��Ա���� find()" << endl;
	cout << z1.find("lo") << endl;

	cout << "��Ա���� find_first_of()" << endl;
	cout << z1.find_first_of("abcd") << endl;

	cout << "��Ա���� find_first_not_of()" << endl;
	cout << z1.find_first_not_of("abcd") << endl;

/*****************************************************************
*			ɾ��string�е��ַ�
* 1.��Ա����erase()			s1.erase(5) ��˼��ȥ���±�5���Ժ���ַ�
*****************************************************************/
	cout << "\n" << "ɾ��string�е��ַ�" << endl;
	string e1("hellow world");
	e1.erase(5);
	cout << e1 << endl;
	cout << e1.length() << endl;

/*****************************************************************
*			�滻string�е��ַ�
* 1.��Ա����replace()			r1.replace(2, 3, "haha")  ��s1���±�2��ʼ��3���ַ�����"haha"��������ǰ�"llo"������"haha"��
*								s1.replace(2,3,"haha",0,2);��s1���±�2��ʼ��3���ַ�����"haha"���±�1��ʼ��2���ַ���������ǰ�"llo"������"ha"��
*****************************************************************/
	cout << "\n" << "�滻string�е��ַ�" << endl;
	string r1("hello world"), r2("hello world");
	r1.replace(2, 3, "haha");
	cout << r1 << endl;

	r2.replace(2, 3, "haha", 0, 2);
	cout << r2 << endl;


/*****************************************************************
*			��string�в����ַ�
* 1.��Ա����insert()
* 
*****************************************************************/
	cout << "\n" << "��string�в����ַ�" << endl;
	string in1("hello world");
	string in2("show insert");
	in1.insert(5, in2);											//��s2����s1�±�5��λ��
	cout << in1 << endl;										//�����helloshow insert world
	in1.insert(2, in2, 5, 3);									//��s2���±�5��ʼ��3���ַ�����s1�±�2��λ��
	cout << in1 << endl;										//�����heinslloshow insert world



/*****************************************************************
*			ת����C����ʽchar*�ַ���
* 1.��Ա����c_str()					s1.c_str()���ش�ͳ��const char* �����ַ������Ҹ��ַ�����'\0'��β
* 2.��Ա����data()					s1.data()����һ��char* ���������͵��ַ�������s1���޸Ŀ��ܻ�ʹp1����
*****************************************************************/
	cout << "\n" << "ת����C����ʽchar*�ַ���" << endl;
	cout << "��Ա����c_str()" << endl;
	string ch1("hello world");
	printf("%s\n", ch1.c_str());

	cout << "��Ա����data()" << endl;
	string ch2("hello world");
	const char* p1 = ch2.data();
	for (int i = 0;i < ch2.length();i++)
		printf("%c", *(p1 + i));
	cout << endl;

/*****************************************************************
*			�ַ���������
* ���˱�׼�����ļ�����������⣬�����Դ�string�������������
��������istream��ostream���б�׼�����������������istringstream��ostringstream�����ַ����ϵ����������Ҳ��Ϊ�ڴ����������
����#include<string>
����#include<iostream>
����#include<sstream>
*****************************************************************/
	cout << "\n" << "�ַ���������" << endl;
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
	outputString << "This " << a << " ok" << endl;				//�� "This "  a  " ok" ��Щ�ַ��� ���һ���������outputString������
	cout << outputString.str() << endl;									//ͨ��outputString.str() ����������ַ����ó���


/*****************************************************************
*			����ȡcin �Լ� getline
*****************************************************************/
	cout << "\n" << "����ȡcin �Լ� getline" << endl;
	string s5;
	string s6;
	cin >> s5;
	cout << s5 << endl;
	cin.ignore();				//��getline֮ǰʹ��cin.ignore()��������cin�Ĳ����س�������������������getline��
	getline(cin, s6);
	cout << s6 << endl;


	return 0;
}
