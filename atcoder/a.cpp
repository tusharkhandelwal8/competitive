#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int h[n];
  for(int i=0;i<n;i++)
    	cin >> h[i];
   vector<int> dp(n+1,0) ;
  
  for(int i=2;i<=n;i++)
  {
    dp[i]=min(dp[i-1]+abs(h[i-1]-h[i-2]),dp[i-2]+abs(h[i-1]-h[i-3]));
  }
	cout <<  dp[n];
}
