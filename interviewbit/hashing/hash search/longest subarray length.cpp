int Solution::solve(vector<int> &A) {
    unordered_map<int,int> um;
    int ans=0,curr=0;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]==0)
                A[i]=-1;
        }
    for(int i=0;i<A.size();i++)
        {
            curr+=A[i];
            if(curr==1)
                ans=i+1;
            else if(um.find(curr-1)!=um.end())
                {
                    ans=max(ans,i-um[curr-1]);
                }
            
            if(um.find(curr)==um.end())
                {
                    um[curr]=i;
                }    
        }
        
        return ans;
}
