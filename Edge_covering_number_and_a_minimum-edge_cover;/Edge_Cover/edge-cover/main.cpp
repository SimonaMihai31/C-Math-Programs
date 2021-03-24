// C++ program to find Edge Cover
#include <bits/stdc++.h>
using namespace std;

// Function that calculates Edge Cover
int edgeCover(int n)
{
	float result = 0;

	result = ceil(n / 2.0);

	return result;
}

// Driver Code
int main()
{
	int n = 5;

	cout << edgeCover(n);

	return 0;
}
