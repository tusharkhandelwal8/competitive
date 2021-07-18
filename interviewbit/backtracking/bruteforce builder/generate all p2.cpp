void mp(vector<string> curr,string A, vector<vector<string>> &ans,int ind)
    {
        if(ind==A.size())
            {   
                ans.push_back(curr);
                return;
            }
        string push;    
        for(int i=ind;i<A.size();i++)
            {
                push+=A[i];
                int flag=1;
                for(int j=0;j<push.size()/2;j++)
                    {
                        if(push[j]!=push[push.size()-1-j])
                            flag=0;
                    }
                if(flag)
                    {   
                        vector<string> cur=curr;
                        cur.push_back(push);
                        
                        mp(cur,A,ans,i+1);
                    }
            }
    }
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string>> ans;
    vector<string> curr;
    mp(curr,A,ans,0);
    return ans;
}
