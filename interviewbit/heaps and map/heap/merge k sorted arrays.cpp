vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
                pq.push(A[i][j]);
        }
    vector<int> ans;
    while(pq.size())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    
}
