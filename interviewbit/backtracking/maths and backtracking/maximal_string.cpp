void fm(string curr,int count,int mc,string &ans)
    {
        if(count>=mc)
            return;
        
        for(int i=0;i<curr.size()-1;i++)
            {
               for(int j=i+1;j<curr.size();j++)
               {
                char temp=curr[i];
                curr[i]=curr[j];
                curr[j]=temp;
                count++;
                
                if(curr>ans)
                    ans=curr;
                    
                if(mc>count)
                fm(curr,count,mc,ans);
                
                count--;
                temp=curr[i];
                curr[i]=curr[j];
                curr[j]=temp;
               }
                
            }
    }
string Solution::solve(string A, int B) {
    string ans=A;
    string curr=A;
    fm(curr,0,B,ans);
    return ans;
}
