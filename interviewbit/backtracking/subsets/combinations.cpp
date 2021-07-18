void alls(vector<int> curr,vector<int> &b,vector<vector<int>> &ans,int ind,int B)
    {
       // ans.push_back(curr);
        
        if(curr.size()==B)
            {
                if(s.find(curr)==s.end())
               { ans.push_back(curr);
                s.insert(curr);}
                return;
            }
        
        for(int i=ind;i<b.size();i++)
        { 
               curr.push_back(b[i]);
                 alls(curr,b,ans,i+1,B);
               
                 curr.pop_back();
                   
            
        }
        return;
    }
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> b;
    for(int i=1;i<=A;i++)
        b.push_back(i);
    
     vector<vector<int>> ans;
    vector<int> curr;
    int csum=0;
    alls(curr,b,ans,0,B);
    return ans;    
        
}
