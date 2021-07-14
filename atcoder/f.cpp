#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;
  cin >> s >> t;
  
   int dp[s.size()+1][t.size()+1];
   pair<int,int> p[s.size()+1][t.size()+1];
   for(int i=0;i<=s.size();i++)
    {
        dp[i][0]=0;
        p[i][0]={-1,-1};
    }
     for(int i=0;i<=t.size();i++)
    {
        dp[0][i]=0;
        p[0][i]={-1,-1};
    }
    
   for(int i=1;i<=s.size();i++)
    { 
    for(int j=1;j<=t.size();j++)
        {   
            
             if(s[i-1]==t[j-1])
                {  
                   dp[i][j]=max(1+dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1])); 
                    if(dp[i][j]==dp[i-1][j])
                        {
                            p[i][j]=p[i-1][j];
                        }
                    else if(dp[i][j]==dp[i][j-1])
                        p[i][j]=p[i][j-1];   
                    else
                        p[i][j]={i-1,j-1};
                        
                        
                }
            else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(dp[i][j]==dp[i-1][j])
                            p[i][j]=p[i-1][j];
                    else
                        p[i][j]=p[i][j-1];
                }
        }
  }
   
   string ans;
    int a=s.size();
    int b=t.size();
  
   while(1)
    {   int l=p[a][b].first;
        int m=p[a][b].second;
        if(l==-1)
            break;
         ans+=s[l];
        a=l;
        b=m;
    }    
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
  
  
	
}
