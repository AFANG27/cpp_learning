/*************************************************************************************************************************
*1. stack
　　stack是后进先出的数据结构，只能插入，删除，访问栈顶的元素。
　　可以用vector，list，deque来实现，在缺省情况下（缺省即默认），用deque实现
  （也就是说stack在你不特别定义它是其他的容器来实现时，默认是用deque来实现的，下面讲到的其他容器适配器也是这样）。
	用vector和deuqe实现，比用list实现性能好。
　　template<class T, class Cont = deque<T>>
　　class stack
　　{
　　.......
　　};
　　stack上可以进行以下操作：
　　	push 插入元素
　　	pop 弹出元素
　　	top 返回栈顶元素的引用
2. queue
　　和stack基本类似，可以用list和deque实现。缺省情况下用deque实现。
　　template<class T, class Cont = deque<T>>
　　class queue
　　{
　　.......
　　};
　　同样也有push，pop，top函数。
　　但是push发生在队尾；top发生在队头。先进先出。
　　有back成员函数可以返回队尾元素的引用
3. priority_queue
　　template<class T, class Cont = deque<T>,class Compare = less<T>>
　　class priority_queue
　　{
　　......
　　};
　　和queue类似，可以用vector和deque实现。缺省情况下用vector实现。
　　priority_queue通常用堆排序技术实现，保证最大的元素总是在最前面。
	即执行pop操作时，删除的是最大的元素；执行top操作时，返回的是最大元素的引用。
	（这个引用是const的，不能修改）默认的元素比较器是less<T>（就是默认从小到大排序嘛，用“<”来排序）（这不就是队列版的multiset嘛）
　　push，pop的时间复杂度O(logn)
　　top()时间复杂度O(1)
  注：less是从大到小，greater是从小到大。

  4. 容器适配器的元素个数
　　stack，queue，priority_queue都有
　　empty()成员函数用于判断适配器是否为空
　　size()成员函数返回适配器中元素个数
************************************************************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<double> pq1;
	pq1.push(3.2);
	pq1.push(9.8);
	pq1.push(9.8);
	pq1.push(5.4);
	while (!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	priority_queue<double, vector<double>, greater<double>>pq2;
	pq2.push(3.2);
	pq2.push(9.8);
	pq2.push(9.8);
	pq2.push(5.4);
	while (!pq2.empty())
	{
		cout << pq2.top() << " ";
		pq2.pop();
	}

	return 0;
}
