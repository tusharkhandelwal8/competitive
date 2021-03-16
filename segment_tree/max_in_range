#include <bits/stdc++.h>
 
using namespace std;

 void build( vector<int> arr,int* tree,int tl,int tr,int v )
{  if(tl==tr)
     {tree[v]=arr[tl];
         return;
     }
   int m=(tl+tr)/2;
   build(arr,tree,tl,m,2*v+1);
   build(arr,tree,m+1,tr,2*v+2);
    tree[v]=max(tree[2*v+1],tree[2*v+2]);   
   
}
int getmax(int* tree,int left,int right,int start,int end,int v)
{
    if (start > end) 
        return 0;
    if (left == start && right == end) {
        return tree[v];
    }
    int tm = (left + right) / 2;
    return max(getmax(tree, left, tm, start, min(end, tm),2*v+1), getmax(tree, tm+1, right, max(start, tm+1), end,2*v+2));
}

int main()
{  vector <int> arr={9,2,6,-4,1};
    int* tree= new int[arr.size()*4];
    build(arr,tree,0,arr.size()-1,0);
    for(int i=0;i<arr.size()*4;i++)
    {
        cout << tree[i] << " ";
    }
    int a,b;
    cin >> a >> b;
    int d=getmax(tree,0,4,a,b,0);
    cout << endl << d;
} 
