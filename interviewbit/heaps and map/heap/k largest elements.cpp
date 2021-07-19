vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    for(int i=0;i<A.size();i++)
        {
            pq.push(A[i]);
        }
    vector<int> ans;
    for(int i=0;i<B;i++)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
}
