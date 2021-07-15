void all_per(vector<int> B,vector<int> curr,vector<vector<int>> &ret,int n)
    {
        for(int i=0;i<B.size();i++)
            {
                curr.push_back(B[i]);
                if(curr.size()==n)
                    {
                        ret.push_back(curr);
                        return;
                    }
                else
                    {
                        vector<int> c;
                        for(int j=0;j<B.size();j++)
                            {
                                if(j!=i)
                                    c.push_back(B[j]);
                                
                                 
                            }
                             all_per(c,curr,ret,n);  
                    }
                curr.pop_back();
            }
    }
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> B=A;
    sort(B.begin(),B.end());
    vector<vector<int>> ret;
    vector<int> curr;
    int size=A.size();
    all_per(B,curr,ret,size);
    return ret;
    
}
