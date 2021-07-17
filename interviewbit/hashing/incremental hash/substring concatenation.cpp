
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
   unordered_map<string,int> um,check;
   for(int i=0;i<B.size();i++)
    {
        um[B[i]]++;
    }
    int len=(B[0].size())*(B.size());
    vector<int> ans;
    
   // if(len>A.size())
  //      return ans;
        
    for(int i=0;i<A.size()-len+1;i++)
        {   int flag=1;
            check=um;
            for(int j=i;j<i+len;j=j+B[0].size())
                {
                    string curr;
                    for(int k=j;k<j+B[0].size();k++)
                        {
                            curr+=A[k];
                        }
                    if(check.find(curr)==check.end()||(check[curr]==0))
                        {   
                            flag=0;
                            break;
                        }
                    else
                        {
                            check[curr]--;
                        }
                        
                }
            if(flag)
                ans.push_back(i);
           
        }
        
 
        return ans;
}
