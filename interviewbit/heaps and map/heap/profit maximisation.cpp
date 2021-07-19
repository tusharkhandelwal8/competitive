int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    priority_queue<int> pq;
    for(int i=0;i<A.size();i++)
        {
            pq.push(A[i]);
        }
    for(int i=0;i<B;i++)
        {
            int curr=pq.top();
            pq.pop();
            ans+=curr;
            pq.push(curr-1);
        }
        return ans;
    
}
