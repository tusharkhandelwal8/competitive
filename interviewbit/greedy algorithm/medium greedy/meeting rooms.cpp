int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());
    int ans=1,curr=1;
    multiset<int> s;
    s.insert(A[0][1]);
    for(int i=1;i<A.size();i++)
        {
           s.insert(A[i][1]);
           while(*s.begin()<=A[i][0])
                s.erase(s.begin());
            
            curr=s.size();
            ans=max(ans,curr);
        }
        return ans;
}
