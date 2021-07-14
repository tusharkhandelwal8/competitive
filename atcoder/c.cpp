#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n ;
  int a[n][3];
  for(int i=0;i<n;i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int dp[n][3];
   
    for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
                {   if(i==0)
                        dp[i][j]=0;
                    else if(j==0)
                        dp[i][j]=max(dp[i-1][j+1]+a[i-1][j],dp[i-1][j+2]+a[i-1][j]);
                    else if(j==1)
                        dp[i][j]=max(dp[i-1][j-1]+a[i-1][j],dp[i-1][j+1]+a[i-1][j]);
                    else
                        dp[i][j]=max(dp[i-1][j-1]+a[i-1][j],dp[i-1][j-2]+a[i-1][j]);
                }
        }
        
        cout << max(dp[n][0],max(dp[n][1],dp[n][2]));
  
}
