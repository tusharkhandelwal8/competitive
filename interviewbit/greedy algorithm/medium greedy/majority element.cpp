int Solution::majorityElement(const vector<int> &A) {
    
    int ans=A.size()/2;
    
    map<int,int> m;
    for(int i=0;i<A.size();i++)
        {
            m[A[i]]++;
        }
    for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->second>(ans))
                return i->first;
            
        }
}
