void alls(vector<int> curr,vector<int> b,vector<vector<int>> &ans,int ind)
    {
        ans.push_back(curr);
        if(ind==b.size())
            return;
        
        for(int i=ind;i<b.size();i++)
        {
        curr.push_back(b[i]);
        alls(curr,b,ans,i+1);
        curr.pop_back();
        }
    }
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> b=A;
    sort(b.begin(),b.end());
    vector<vector<int>> ans;
    vector<int> curr;
    alls(curr,b,ans,0);
    return ans;
}
