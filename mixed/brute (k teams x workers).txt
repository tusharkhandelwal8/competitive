
#include <bits/stdc++.h> 
using namespace std; 

long long mini=10000000000000000;
vector<long long> primeFactors(long long n) 
{ 
	vector<long long> a;
	long long k=1;
	while (n % 2 == 0) 
	{   
	        k=k*2;
		n = n/2; 
	} 
	if(k%2==0)
	    a.push_back(k);

	
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		long long u=1;
		while (n % i == 0) 
		{ 
			u=u*i;
			n = n/i; 
		} 
		if(u%i==0)
		    a.push_back(u);
	} 

	
	if (n > 2) 
		{
		    a.push_back(n);
		   
		}
		return a;
} 

void brute(vector<long long> &a,vector<long long> &b,int j)
    {
        if(j==a.size())
            {
                long long sum=0;
                for(int i=0;i<b.size();i++)
                    sum=sum+b[i];
                
                if(sum<mini)
                    mini=sum;
            }
        else
            {
                for(int i=0;i<b.size();i++)
                    {
                        b[i]=b[i]*a[j];
                        brute(a,b,j+1);
                        b[i]=b[i]/a[j];
                    }
            }
    }

int main() 
{  int t;
   cin >> t;
   while(t--)
    {   long long k,x;
        cin >> k >> x;
        
	    vector<long long> a=primeFactors(x);
	    if(a.size()<=k)
	        cout << accumulate(a.begin(), a.end(), 0)+(k-a.size()) << endl;
	    else
	        {   vector<long long> b;
	            for(int i=0;i<k;i++)
	                b.push_back(1);
	            brute(a,b,0);
	                
	           cout << mini << endl;     
	            mini=10000000000000000;
	            
	        }

    }

} 
