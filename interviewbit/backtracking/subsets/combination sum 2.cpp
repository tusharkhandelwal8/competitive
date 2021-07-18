void alls(vector<int> curr,int csum,vector<int> &b,vector<vector<int>> &ans,int ind,int B,set<vector<int>> &s)
    {
       // ans.push_back(curr);
        
        if(csum==B)
            {
                if(s.find(curr)==s.end())
               { ans.push_back(curr);
                s.insert(curr);}
                return;
            }
        
        for(int i=ind;i<b.size();i++)
        { 
              if(csum+b[i]<=B)
              { curr.push_back(b[i]);
                 alls(curr,csum+b[i],b,ans,i+1,B,s);
               
                 curr.pop_back();
              }     
            
        }
        return;
    }
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     vector<int> b=A;
    sort(b.begin(),b.end());
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> curr;
    int csum=0;
    alls(curr,csum,b,ans,0,B,s);
    return ans;
}
