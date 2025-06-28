#include<iostream>
using namespace std;

class Score {
private:
	int mid_exam;
	int fin_exam;
	static int count;
	static float sum;
	static float ave;
public:
	Score(int m, int n);
	~Score();
	static void show_count_sum_ave();
};

Score::Score(int m, int n) {
	mid_exam = m;
	fin_exam = n;
	++count;
	sum += fin_exam;
	ave = sum / count;
}

Score::~Score() {
	cout << "Score::~Score " << mid_exam << endl;
}

int Score::count = 0;
float Score::sum = 0.0;
float Score::ave = 0.0;

void Score::show_count_sum_ave() {
	cout << "ѧ��������" << count << endl;
	cout << "��ĩ�ۼӳɼ�:" << sum << endl;
	cout << "��ĩƽ���ɼ���" << ave << endl;
}

int main() {
	Score sco[3] = { Score(90,89), Score(78,69), Score(89,99) };
	Score::show_count_sum_ave();

	return 0;
}