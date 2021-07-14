#include <bits/stdc++.h>


using namespace std;
//if node a in subtree of b -    b.in < a.in && a.out<< b.in
int timer=1;

void dfs(int a,int *vis,vector<int> arr[7],int* timein,int* timeout)
    {
        vis[a]=1;
        timein[a]= timer++;
        for(int i=0;i<arr[a].size();i++)
        {
            int child=arr[a][i];
            if(vis[child]==0)
            {
                dfs(child,vis,arr,timein,timeout);

            }

        }
        timeout[a]=timer++;

    }
int main()
{   int vis[7]={0};
    int timein[7]={0};
    int timeout[7]={0};
    vector<int> arr[7];
    for(int i=0;i<4;i++)
    {   int a,b;
        cin >> a >>b;

        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    int timer=1;
    dfs(1,vis,arr,timein,timeout);
    for(int i=1;i<6;i++)
    {
        cout << timein[i] << " " << timeout[i] << endl;
    }

    return 0;
}
