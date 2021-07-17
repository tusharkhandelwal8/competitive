vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,set<int>> um;
    vector<int> ret(A.size());
   
    for(int i=0;i<A.size();i++)
        {   
            if(um.find(A[i])!=um.end())
                {
                    ret[um.find(A[i])->second]++;
                    if(um.find(A[i]+1)!=um.end())
                        {
                            um[A[i]+1]=min(um[A[i]],um[A[i]+1]);
                        }
                    
                    
                }
           
                   um[A[i]]=i;
                   ret[i]=A[i];
               
           
           
        }
        return ret;
}
