#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define endl "\n"
#define pb push_back
#define sorta(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.begin(),a.end(),greater<int> ())
const int mod = 1000000007;

const int INF = 2147483647;
const int MAX = 10005;
int D[MAX], N; // Keeps minimum distance to each node
vector<pair<int,int>> E[MAX]; // Adjacency list
int s,d;
 
void dijkstra()
{
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
 
    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();
 
        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;
 
        for(pair<int,int> pr : E[u])
        {
            int v = pr.first;
            int next_dist = dist + pr.second;
 
            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }

    if(D[d] == INF) cout << "NO" << endl;
    else cout << D[d] << endl;
}

void solve()
{
    int v,e; cin >> v >> e;
    N = v;
    for(int i=0; i<=v; i++) E[i].clear();
    for(int i=0; i<e; i++)
    {
        int v1,v2,w; cin >> v1 >> v2 >> w;
        E[v1].push_back({v2,w});
     //   E[v2].push_back({v1,w});
    }

    cin >> s >> d;
    dijkstra();
}

int32_t main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}
