int Solution::solve(vector<int> &A, int B) {
    int count=0;
    int curr=0;
    unordered_map<int,int> a;
    for(int i=0;i<A.size();i++)
        {
            curr=curr^A[i];
            if(curr==B)
                count++;
            if(a.find(curr^B)!=a.end())
                {
                   // if(((j->first)^(curr))==B)
                        count=count+(a.find(curr^B)->second);
                }
              a[curr]++;  
        }
        return count;
}
