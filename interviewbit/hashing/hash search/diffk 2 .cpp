int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int,int> a;
    for(int i=0;i<A.size();i++)
        {
            a[A[i]+B]++;
            
        }
    for(int j=0;j<A.size();j++)
        {
            if(B==0)
                {
                    if(a.find(A[j])->second>1)
                        return 1;
                }
            else
                {
                    if(a.find(A[j])!=a.end())
                        return 1;
                }
        }
        return 0;
}
