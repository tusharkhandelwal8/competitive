int Solution::solve(string A) {
    int co=0;
    unordered_map<int,int> um;
    for(int i=0;i<A.size();i++)
        {
            um[A[i]]++;
        }
    for(auto i=um.begin();i!=um.end();i++)
        {
            if(i->second%2==1)
                co++;
        }
    if(co>1)
        return 0;
    return 1;    
}
