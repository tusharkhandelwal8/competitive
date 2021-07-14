#include<bits/stdc++.h>
using namespace std;
int dp[100001];
void dfs(int i,vector<vector<int>> &a)
    {
        
        if(dp[i]!=-1)
            return;
        dp[i]=0;
        for(int j=0;j<a[i].size();j++)
            {
                if(dp[a[i][j]]==-1)
                    {
                        dfs(a[i][j],a);
                        dp[i]=max(dp[i],1+dp[a[i][j]]);
                    }
                else
                dp[i]=max(dp[i],1+dp[a[i][j]]);
            }
    }
int main()
{
  int n,m;
  cin >> n >> m;
  int edge[m][2];
  for(int i=0;i<m;i++)
    cin >> edge[i][0] >> edge[i][1];
   
    vector<vector<int>> a(n+1);
    for(int i=0;i<m;i++)
        {
            a[edge[i][0]].push_back(edge[i][1]);
        }
    for(int i=0;i<=100000;i++)
        dp[i]=-1;
        
        for(int i=1;i<=n;i++)
            {
                if(dp[i]==-1)
                    dfs(i,a);
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            {
                if(dp[i]>ans)
                    ans=dp[i];
              //  cout << dp[i] << " ";    
            }
            cout << ans << endl;
	
}
