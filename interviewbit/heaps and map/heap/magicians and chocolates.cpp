int Solution::nchoc(int A, vector<int> &B) {
      priority_queue<long long> pq;
    for(int i=0;i<B.size();i++)
        {
            pq.push(B[i]);
        }
    long long ans=0;
    for(int i=0;i<A;i++)
        {
            long long curr=pq.top();
            pq.pop();
            ans=(ans+curr)%1000000007;
            pq.push(curr/2);
        }
        int kk=ans;
        return kk;
}
