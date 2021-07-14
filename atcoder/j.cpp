#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n ;
  int a[n];
  int c[4]={0};
  int d[4]={0};
  for(int i=0;i<n;i++)
    {
         cin >> a[i];
         c[a[i]]++;
         d[a[i]]++;
    }
    c[1]=c[1]+c[2]+c[3];
    c[2]=c[2]+c[3];
 long double dp[n+1][n+1][n+1];
 
    
     
   
for(int k=0;k<=c[3];k++)
    { 
        for(int j=0;j<=c[2]-k;j++)
            {
               for(int i=0;i<=c[1]-j-k;i++)
                {
                    if(i==0&&j==0&&k==0)
                        dp[i][j][k]=0;
                    else
                        {
                            dp[i][j][k]=0;
                            dp[i][j][k]+=((double)n)/((double)(i+j+k));
                            if(i>0)
                            dp[i][j][k]+=(dp[i-1][j][k]*(double(i)))/((double)(i+j+k));
                            if(j>0)
                            dp[i][j][k]+=(dp[i+1][j-1][k]*(double(j)))/((double)(i+j+k));
                            if(k>0)
                            dp[i][j][k]+=(dp[i][j+1][k-1]*(double(k)))/((double)(i+j+k));
                        }
                    //cout << dp[i][j][k] << " ";    
                }
            }
    }
    

   
     cout << setprecision(20) << dp[d[1]][d[2]][d[3]] << endl;
}
