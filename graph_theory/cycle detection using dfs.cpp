#include <bits/stdc++.h>


using namespace std;


bool dfs(int a,int *vis,vector<int> arr[7],int* parent)
    {
        vis[a]=1;
        for(int i=0;i<arr[a].size();i++)
        {
            int child=arr[a][i];
            if(vis[child]==0)
            {   parent[child]=a;
                if(dfs(child,vis,arr,parent))
                    return true;
            }
            else
            {
                if(parent[a]!=child)
                {
                    return true;
                }
            }
        }
        return false;
    }
int main()
{   int vis[7]={0};
    int parent[7]={0};
    vector<int> arr[7];
    for(int i=0;i<5;i++)
    {   int a,b;
        cin >> a >>b;

        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    parent[1]=1;
    if(dfs(1,vis,arr,parent))
        cout << "cycle";
    else
        cout << "no cycle";
    return 0;
}
