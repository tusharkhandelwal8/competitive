#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n ;
  long double dp[n+1][n+1];
  long double a[n];
  for(int i=0;i<n;i++)
    {
         cin >> a[i]; 
    }
    dp[0][0]=1;
 for(int i=1;i<=n;i++)
    {
      dp[0][i]=0;
    }
 for(int i=1;i<=n;i++)
    {
         dp[i][0]=(dp[i-1][0]*(1-a[i-1]));
    }    
   
for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            {   
                dp[i][j]=a[i-1]*(dp[i-1][j-1])+dp[i-1][j]*(1-a[i-1]);
            }
    }
   
 long double ans=0;
    int k=n/2+1;
    for(int i=k;i<=n;i++)
        ans+=dp[n][i];
    
    cout << setprecision(20)<<ans << endl;    
   
   
  
	
}
