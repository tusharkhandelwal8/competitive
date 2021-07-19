int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    vector<int> c(A.size());
    for(int i=0;i<A.size();i++)
        {
            c[i]=A[i]-B[i];
        }
    int count=0;
    for(int i=0;i<c.size();i++ )
        {
            count+=c[i];
        }
    if(count<0)
        return -1;
    
    int curr=0,start=0;
    for(int i=0;i<A.size();i++)
        {
            curr=curr+c[i];
            while(curr<0&&start!=i)
                {
                    curr=curr-c[start];
                    start++;
                }
            if(curr<0&&start==i)
                {
                    curr=0;
                    start=i+1;
                }
        }
        return start;
     
    
        
        
}
