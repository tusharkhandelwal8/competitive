


#include <bits/stdc++.h>
using namespace std;
    
int main()
{ 
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++)   cin >> a[i];
            
        int dp[k+1] = {0};

        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if( !dp[i] && i+a[j] <= k) dp[i+a[j]] = 1;
            }
        }

       if(dp[k] == 1) cout << "First" << endl;
       else cout << "Second" << endl; 
        
    
}
