#include <iostream>
#include <stack>
using namespace std;

int map[20][20];
int reach[20];

//使用递归的方法
void DFS1(int root, int N)
{
	int i;
	reach[root] = true;
	cout<<root<<" ";
	for(i=0; i<N; i++)
	{
		if(map[root][i] == 1 && reach[i] == false)
		{
			DFS1(i, N);
		}
	}
}

//使用栈的方法
void DFS2(int root , int N)
{
	stack<int> S;
	S.push(root);
	while(!S.empty())
	{
		int d;
		d = S.top();
		S.pop();
		reach[d] = true;
		cout<<d<<" ";
		int i;
		for(i=0; i<N; i++)
		{
			if(map[d][i]==1 && reach[i] == false)
				S.push(i);
		}
	};
}

int main()
{

	int N, M;
	cin>>N>>M;
	int i;
	for(i=0; i<N; i++)
		reach[i] = false;
	for(i=0; i<M; i++)
	{
		int d1, d2;
		cin>>d1>>d2;
		map[d1][d2]=1;
		map[d2][d1]=1;
	}
	int root;
	cin>>root;
//	DFS1(root, N);
//	cout<<endl;
	DFS2(root, N);
	return 0;
}