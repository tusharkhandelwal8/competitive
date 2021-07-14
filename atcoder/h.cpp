#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h,w;
  cin >> h >> w;
  int dp[h+1][w+1];
  char a[h][w];
  for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cin >> a[i][j];
    }
    int mod=1000000007;
for(int i=0;i<=h;i++)
    {
        for(int j=0;j<=w;j++)
            {   
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(i==1&&j==1)
                    dp[i][j]=1;
                else if(a[i-1][j-1]=='.')
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                else
                    dp[i][j]=0;
            }
    }    
    cout << dp[h][w];
   
   
  
	
}
