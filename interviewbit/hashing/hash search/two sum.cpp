vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> um;
    vector<int> ret;
    for(int i=0;i<A.size();i++)
        {
            if(um.find(B-A[i])!=um.end())
                {
                    ret.push_back(um.find(B-A[i])->second+1);
                    ret.push_back(i+1);
                    return ret;
                }
            else    
                {
                    if(um.find(A[i])==um.end())
                    um[A[i]]=i;
                    
                }
        }
        return ret;
}
