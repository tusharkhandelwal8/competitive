vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> ans=A;
    int count=0;
    int sz=A.size();
    int n=sz;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++)
        {
            pos[A[i]]=i;
        }
    for(int i=0;i<n;i++)
        {
            if(ans[i]!=sz)
                {
                    count++;
                    ans[pos[sz]]=ans[i];
                    pos[ans[i]]=pos[sz];
                    ans[i]=sz;
                    
                }
                sz--;
            if(count==B)
                break;
        }
        return ans;
    
}
