#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
#define MAXLEN 10000

void Dijkstra(int N, int map[][MAX], int path[], int U[], int aim)
{
	U[aim] = 0;
	path[aim] = 0;

	int i;
	int rest = N-1;      //剩下的未被算出最小距离点的个数
	int from = aim;
	while(rest>0)
	{
		for(i=0; i<N; i++)
		{

			if(U[i] == 1 && map[from][i]>0 && (map[from][i]+path[from]<path[i]))
				path[i] = map[from][i]+path[from];
		}
		int min_path = MAXLEN;
		int min_point;
		for(i=0; i<N; i++)
		{
			if(U[i] == 1 && min_path > path[i])
			{
				min_path = path[i];
				min_point = i;
			}
		}
		U[min_point]=0;
		rest--;
		from = min_point;
	};
}

int main()
{
	int map[MAX][MAX];   //记录图的邻接矩阵
	int path[MAX];   //记录单源点到其他各点的最小距离
	int U[MAX];  //记录还未得出算出最小距离的点

	int N, M;  //N表示结点个数  M表示边的个数
	cin>>N>>M;
	int i;
	//初始化
	for(i=0; i<N; i++)
	{
		path[i] = MAXLEN;
		U[i] = 1;
	}
	//输入图中两点间的距离
	int point1, point2;
	for(i=0; i<M; i++)
	{
		cin>>point1>>point2;
		cin>>map[point1][point2];
		map[point2][point1] = map[point1][point2];
	}
	
	int aim;   //输入源点
	cin>>aim;
	Dijkstra(N, map, path, U, aim);

	for(i=0; i<N; i++)
		cout<<path[i]<<" ";
	cout<<endl;
	return 0;
}