void alls(vector<int> curr,vector<int> b,vector<vector<int>> &ans,int ind,set<vector<int>> &s)
    {   if(s.find(curr)!=s.end())
            return;
        ans.push_back(curr);
        s.insert(curr);
        if(ind==b.size())
            return;
        
        for(int i=ind;i<b.size();i++)
        {
        curr.push_back(b[i]);
        alls(curr,b,ans,i+1,s);
        curr.pop_back();
        }
    }
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
        vector<int> b=A;
    sort(b.begin(),b.end());
    vector<vector<int>> ans;
    vector<int> curr;
    set<vector<int>> s;
    alls(curr,b,ans,0,s);
    return ans;
}
