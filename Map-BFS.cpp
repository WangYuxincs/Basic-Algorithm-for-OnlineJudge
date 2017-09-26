#include <iostream>
#include <queue>
using namespace std;

int map[20][20];
int reach[20];

void BFS(int root , int N)
{
	queue<int> Q;
	Q.push(root);
	while(!Q.empty())
	{
		int d = Q.front();
		Q.pop();
		reach[d] = true;
		cout<<d<<" ";
		int i;
		for(i=0; i<N; i++)
		{
			if(map[d][i]==1 && reach[i] == false)
			{
				Q.push(i);
			}
		}
	}
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
	BFS(root, N);
	return 0;
}