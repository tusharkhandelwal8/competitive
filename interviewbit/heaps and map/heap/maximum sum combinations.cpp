vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int> b;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<A.size();i++)
        {
         //   a.push(A[i]);
            b.push(B[i]);
        }
    vector<int> a=A;
    sort(a.begin(),a.end(),greater<>());
    for(int i=0;i<C;i++)
        {
            pq.push(b.top()+a[i]);
        }
        b.pop();
     for(int i=1;i<A.size();i++)
        {
            int j=A.size();
            int k=0;
            while((k!=j)&&pq.top()<(b.top()+a[k]))
                {
                    pq.pop();
                    pq.push(b.top()+a[k]);
                    k++;
                    
                }
            b.pop();    
        }
     vector<int> ret;
     while(pq.size())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
        
 }
