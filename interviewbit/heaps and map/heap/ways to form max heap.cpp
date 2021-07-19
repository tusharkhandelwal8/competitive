
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
long long fac(int k)
    {
        long long a[k];
        a[0]=1;
        for(int i=1;i<=k;i++)
            {
                if(i==1)
                    a[i]=1;
                else
                    {
                        a[i]=(i*a[i-1])%(1000000007);
                    }
            }
            return a[k];
        
    }
int Solution::solve(int A) {
    if(A<=1)
        return 1;
    
    int l=0,r;
    int m=1000000007;
    int curr=A-1,ll=2;
    while(curr>0)
        {
            if(curr>=ll/2)
                {
                    l+=(ll)/2;
                    curr=curr-ll;
                    ll=2*ll;
                }
            else 
                {
                    l+=curr;
                    curr=0;
                }
        }
  //  return l;    
    long long ncl= (fac(A-1)*modInverse((fac(l)*fac(A-1-l))%m,m))%m  ; 
  //  return ncl;
    long long ans=(((ncl*solve(l))%m)*(solve(A-1-l)))%m;
    return ans;
    
}
