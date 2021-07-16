vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,pair<int,int>> um;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
        {
            for(int j=i+1;j<A.size();j++)
                {
                   int sum=A[i]+A[j];
                   if(um.find(sum)==um.end())
                    {
                        um[sum]={i,j};
                    }
                    else
                    {
                        pair<int,int> p1=um[sum];
                        int k=p1.first;
                        int l=p1.second;
                        if(i!=k&&i!=l&&j!=k&&j!=l)
                            {
                                if(ans.size()==0)
                                    ans={k,l,i,j};
                                else
                                    {
                                        vector<int> curr={k,l,i,j};
                                        if(ans>curr)
                                            ans=curr;
                                    }
                            }
                    }
                }
        }
     
        return ans;
}
