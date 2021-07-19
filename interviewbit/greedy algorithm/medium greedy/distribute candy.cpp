int Solution::candy(vector<int> &A) {
    int count=0;
    int prev=0;
    vector<int> ans(A.size());
    ans[0]=1;
    for(int i=1;i<A.size();i++)
        {   
            if(A[i]==A[i-1])
                {   
                    
                    if(prev!=0)
                    {
                    count+=((prev)*(prev-1))/2 -1;
                    ans[i-prev]=max(prev,ans[i-prev]);
                    ans[i-1]=1;
                    prev=0;
                    }
                    ans[i]=1;
                    
                }
            else if(A[i]>A[i-1])
                {   if(prev!=0)
                    {
                    count+=((prev)*(prev-1))/2 -1;
                    ans[i-prev]=max(prev,ans[i-prev]);
                    ans[i-1]=1;
                    prev=0;
                    }
                    ans[i]=1+ans[i-1];
                    
                }
            else
                {
                    if(prev==0)
                        prev=2;
                     else
                        prev++;
                }
            
            if(i==A.size()-1&&prev!=0)
                {
                     count+=((prev)*(prev-1))/2 -1;
                    ans[i-prev+1]=max(prev,ans[i-prev+1]);
                    ans[i]=1;
                    prev=0;
                }
                
                
        }
    for(int i=0;i<A.size();i++)
        {
            count+=ans[i];
        }
        return count;
}
