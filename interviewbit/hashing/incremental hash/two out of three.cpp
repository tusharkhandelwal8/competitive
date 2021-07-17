vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    set<int> a,b,c;
    unordered_map<int,int> um;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
        {
            a.insert(A[i]);
        }
    for(int i=0;i<B.size();i++)
        {
            b.insert(B[i]);
        }
    for(int i=0;i<C.size();i++)
        {
            c.insert(C[i]);
        }
    for(auto i=a.begin();i!=a.end();i++)
        {
            um[*i]++;
        }
    for(auto i=b.begin();i!=b.end();i++)
        {
            um[*i]++;
        }
    for(auto i=c.begin();i!=c.end();i++)
        {
            um[*i]++;
        } 
    for(auto i=um.begin();i!=um.end();i++)
        {
            if(i->second>=2)
                ans.push_back(i->first);
        }
    sort(ans.begin(),ans.end());
    
    return ans;
    
}
