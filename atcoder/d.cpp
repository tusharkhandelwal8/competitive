#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,w;
  cin >> n >> w;
  int wi[n],v[n];
  for(int i=0;i<n;i++)
    	cin >> wi[i] >> v[i];
   long long dp[n+1][w+1];
   
  
    
  for(int i=0;i<=n;i++)
  { 
    for(int j=0;j<=w;j++)
        {   
            if(i==0||j==0)
                dp[i][j]=0;
            else if(j>=wi[i-1])
                {
                    dp[i][j]=max(dp[i-1][j-wi[i-1]]+v[i-1],dp[i-1][j]);
                }
            else
                dp[i][j]=dp[i-1][j];
        }
  }
	cout <<  dp[n][w];
}
