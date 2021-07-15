void sq(vector<string> curr,vector<vector<string>> &ans,int A,int cr,unordered_map<int,int> um,string s)
    {
        if(cr==A+1)
            {
                ans.push_back(curr);
                return;
            }
        vector<int> valid(A+1);
        for(int i=1;i<=A;i++)
            {
                if(um[i]!=0)
                    {
                        valid[um[i]]=1;
                        if(um[i]-(cr-i)>=1)
                            valid[um[i]-(cr-i)]=1;
                        if(cr-i+um[i]<=A)
                            valid[um[i]+cr-i]=1;
                            
                    }
                    
            }
        
        for(int i=1;i<=A;i++)
            {
                if(!valid[i])
                    {   
                        s[i-1]='Q';
                        curr.push_back(s);
                        s[i-1]='.';
                        um[cr]=i;
                        sq(curr,ans,A,cr+1,um,s);
                        um[cr]=0;
                        curr.pop_back();
                    }
            }
    }
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string>> ans;
    string s;
    for(int i=0;i<A;i++)
        s+='.';
    vector<string> curr;
    unordered_map<int,int> um;
    sq(curr,ans,A,1,um,s);
    return ans;
}
