#include <bits/stdc++.h> 
using namespace std; 

 void allsub(vector<int>& a,vector<int>& subset,vector<vector<int>>& res,int index )
 {
     res.push_back(subset);
     for(int k=index;k<a.size();k++)
     {
         subset.push_back(a[k]);
         allsub(a,subset,res,k+1);
         subset.pop_back();
     }
     return;
 }
 
 vector<vector<int>> subset(vector<int>& a)
    {
        vector<int> subset;
        vector<vector<int>> res;
        int index=0;
        allsub(a,subset,res,index);
        return res;
    }
    
    
int main()
{   
   
    vector<int> arr={1,2,2,7,8,3};
    vector<vector<int>> res = subset(arr);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
}
