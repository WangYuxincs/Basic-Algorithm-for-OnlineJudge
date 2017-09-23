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
	int rest = N-1;      //ʣ�µ�δ�������С�����ĸ���
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
	int map[MAX][MAX];   //��¼ͼ���ڽӾ���
	int path[MAX];   //��¼��Դ�㵽�����������С����
	int U[MAX];  //��¼��δ�ó������С����ĵ�

	int N, M;  //N��ʾ������  M��ʾ�ߵĸ���
	cin>>N>>M;
	int i;
	//��ʼ��
	for(i=0; i<N; i++)
	{
		path[i] = MAXLEN;
		U[i] = 1;
	}
	//����ͼ�������ľ���
	int point1, point2;
	for(i=0; i<M; i++)
	{
		cin>>point1>>point2;
		cin>>map[point1][point2];
		map[point2][point1] = map[point1][point2];
	}
	
	int aim;   //����Դ��
	cin>>aim;
	Dijkstra(N, map, path, U, aim);

	for(i=0; i<N; i++)
		cout<<path[i]<<" ";
	cout<<endl;
	return 0;
}