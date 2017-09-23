#include <iostream>
using namespace std;

int Binary_Search(int A[], int left, int right, int aim)
{
	if(left > right)
		return -1;
	int low = left;
	int high = right;
	int mid = (low + high)/2;
	if(aim == A[mid])
		return mid;
	else if(aim > A[mid])
		return Binary_Search(A, mid+1, high, aim);
	else
		return Binary_Search(A, low, mid-1, aim);
}

int main()
{
	cout<<"��������������飨��С���󣩣�"<<endl;
	int N;
	cin>>N;
	int *A = new int[N];
	int i;
	for(i=0; i<N; i++)
	{
		cin>>A[i];
	}

	int aim;
	cin>>aim;
	int position = Binary_Search(A, 0, N-1, aim);
	if(position>=0)
		cout<<position<<endl;
	else
		cout<<"�����ڣ�"<<endl;
	delete []A;
	return 0;
}