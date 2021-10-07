#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

int n = 6;
int L = 0;
int R = n - 1;

int binary_search(int A[], int n, int T)
{
	while(L <= R)
	{
		int m = (L + R) / 2;
		if(A[m] < T)
			L = m + 1;
		else if(A[m] > T)
			R = m - 1;
		else
			return m;
	}
	return -1;
}

int main()
{
	int A[] = {1,2,3,4,5,6};
	int T = 0;
	cout << binary_search(A,n,T);
	return 0;
}

