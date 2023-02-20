#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define endl "\n"
#define pb push_back
#define sorti(a) sort(a.begin(),a.end()); 
#define sortd(a) sort(a.begin(),a.end(),greater<int> ()); 
const int mod = 1000000007;


const int N = 1000000;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p /= 2; ) t[p] = t[p * 2] + t[p * 2 + 1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
void solve()
{
        cin >> n;
        vector<int> a(n);
        forn(i,0,n)  cin >> a[i] , t[n+i] = 0;
        build();
    
        int ans = 0;
        vector<int> pre(n,0),suf(n,0);
        map<int,int> m,m1;
        forn(i,0,n)   m[a[i]]++ ,pre[i] = m[a[i]];
        for(int i=n-1; i>=0; i--) m1[a[i]]++ , suf[i] = m1[a[i]];
        
        for(int i=n-1; i>=0; i--)
        {   
          ans += query(1,pre[i]);
          modify(suf[i],t[n+suf[i]]+1);
        }

        cout << ans << endl;

     
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t = 1;
   // cin >> t;
    while(t--) solve();

    return 0;
}
