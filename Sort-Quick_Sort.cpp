#include <iostream>
using namespace std;

void Quick_Sort(int A[], int left, int right)
{
	if(left >= right)
		return;
	int first = left;
	int last = right;
	int key = A[left];
	while(first < last)
	{
		while(first < last && A[last] >= key)
			last--;
		A[first] = A[last];
		while(first < last && A[first] <= key)
			first++;
		A[last] = A[first];
	}
	A[first] = key;
	Quick_Sort(A, left, first-1);
	Quick_Sort(A, first+1, right);
}

int main()
{
	int N;
	cin>>N;
	int *A = new int[N];
	int i;
	for(i=0; i<N; i++)
		cin>>A[i];

	Quick_Sort(A, 0, N-1);
	
	for(i=0; i<N; i++)
		cout<<A[i]<<" ";
	
	delete []A;
	return 0;
}