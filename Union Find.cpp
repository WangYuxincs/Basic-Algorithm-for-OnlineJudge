//--------------------------------------------------------------
//                              并查集基本应用
//--------------------------------------------------------------
/*
		这个程序主要是考察并查集最基本的用法
		Input:  第一行输入总结点个数N，和总结点对M。
		            接下来的M行每一行输入的是结点对
		N M
		n1 n2
		n3 n4
		...  ...
		
		Output: 所有不同集合的数目
*/
//-------------------------------------------------------------

#include <iostream>
using namespace std;

int *Father;
int sum;

int find(int point)
{
	int fa = Father[point];
	if (fa != -1)
	{
		return find(fa);
	}
	else
		return point;
}

void make_pair(int point1, int point2)
{
	if (point1 > point2)
	{
		int temp = point1;
		point1 = point2;
		point2 = temp;
	}
	int f1 = find(point1);
	int f2 = find(point2);
	if ( f1 !=  f2 )
	{
		Father[point2] = f1;
		sum--;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	sum = N;
	Father = new int[N];
	int i;
	for (i = 0; i < N; i++)
		Father[i] = -1;

	for (i = 0; i < M; i++)
	{
		int point1, point2;
		cin >> point1 >> point2;
		make_pair(point1, point2);
	}
	
	cout << sum << endl;

	return 0;
}