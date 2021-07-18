int Solution::solve(vector<int> &A) {
    unordered_map<int,int> um;
    int ans=A.size()+1,ret=-1;
    for(int i=0;i<A.size();i++)
        {
            if(um[A[i]]&&(ans>um[A[i]]))
                ret=A[i];
            um[A[i]]=i+1;
        }
        return ret;
}
