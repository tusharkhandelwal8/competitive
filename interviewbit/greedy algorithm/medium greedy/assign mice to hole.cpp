int Solution::mice(vector<int> &A, vector<int> &B) {
    int ans;
    if(A.size()==0)
        return 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ans=abs(B[0]-A[0]);
    for(int i=1;i<A.size();i++)
        {
            ans=max(ans,abs(B[i]-A[i]));
        }   
        return ans;
}
