#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,w;
  cin >> n >> w;
  int wi[n],v[n];
  for(int i=0;i<n;i++)
    	cin >> wi[i] >> v[i];
   long long dp[n+1][100001];
   
  
    
  for(int i=0;i<=n;i++)
  { 
    for(int j=0;j<=100000;j++)
        {   dp[i][j]=w+1;
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=w+1;
            else if(j>=v[i-1])
                {
                    dp[i][j]=min(dp[i-1][j-v[i-1]]+wi[i-1],dp[i-1][j]);
                }
            else
                dp[i][j]=dp[i-1][j];
        }
  }
   
    for(int j=100000;j>=0;j--)
        {   
            if(dp[n][j]<=w)
                 {
                     cout << j << endl;
                     break;
                 }
        }
  
	
}
