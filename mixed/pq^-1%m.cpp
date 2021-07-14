
#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int* x, int* y);

int modInverse(int a, int m)
{
	int x, y;
	int g = gcdExtended(a, m, &x, &y);
		int res = (x % m + m) % m;
		return res;
	
}

int gcdExtended(int a, int b, int* x, int* y)
{
	// Base Case
	if (a == 0) 
	{
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

// Driver Code
int main()
{
	int q = 9, m = 998244353;
    int p=1;
    
    
	// Function call
    cout << 	(p*(modInverse(q, m)))%(998244353);
	return 0;
}
