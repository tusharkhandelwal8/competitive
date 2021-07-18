vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    set<vector<int>> aa;
   for(int i=0;i<A.size()-3;i++)
    {
        for(int j=i+1;j<A.size()-2;j++)
            {
                int curr=A[i]+A[j];
                int target=B-curr;
                int l=j+1,m=A.size()-1;
                while(l<m)
                    {
                        if(A[m]+A[l]==target)
                            {
                                vector<int> si={A[i],A[j],A[l],A[m]};
                                aa.insert(si);
                                l++,m--;
                                
                            }
                        else if(target>A[m]+A[l])
                            l++;
                        else
                            m--;
                    }
            }
    }
        vector<vector<int>> bb(aa.begin(),aa.end());
        
        return bb;
}
