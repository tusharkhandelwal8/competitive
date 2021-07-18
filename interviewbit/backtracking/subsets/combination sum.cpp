void alls(vector<int> curr,int csum,vector<int> &b,vector<vector<int>> &ans,int ind,int B,set<vector<int>> &s)
    {
       // ans.push_back(curr);
        
        if(csum==B)
            {
                if(s.find(curr)==s.end())
               { ans.push_back(curr);
                s.insert(curr);}
                return;
            }
        
        for(int i=ind;i<b.size();i++)
        { 
              if(csum+b[i]<=B)
              { curr.push_back(b[i]);
                 alls(curr,csum+b[i],b,ans,i,B,s);
               
                 curr.pop_back();
              }     
            
        }
        return;
    }
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
      vector<int> b=A;
    sort(b.begin(),b.end());
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> curr;
    int csum=0;
    alls(curr,csum,b,ans,0,B,s);
    return ans;
}
