#include<bits/stdc++.h>
using namespace std;



void dfs(int v,vector<int> graph[7],int* vis,int* dis)
    {
        vis[v]=1;
        for(int i=0;i<graph[v].size();i++)
            {
                if(vis[graph[v][i]]==0)
                    {
                        dis[graph[v][i]]=dis[v]+1;
                        dfs(graph[v][i],graph,vis,dis);
                    }
            }
    }
    
    
int main()
{ 
   int n=6;
    int a,b;
    vector<int> graph[7];
int vis[7]={0};
int dis[7]={0};
    for(int i=0;i<5;i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            
        }
    for(int i=1;i<=n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
                {
                    cout << graph[i][j] << " ";
                }
            cout << endl;
        }  
     
     dfs(1,graph,vis,dis);
     for(int i=1;i<=n;i++)
        {
            cout << dis[i] << " ";
        }

    
}
