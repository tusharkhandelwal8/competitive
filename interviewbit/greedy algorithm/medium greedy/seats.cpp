int Solution::seats(string A) {
    int mod=10000003;
    int curr,index=0,count=0;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]=='x')
           {
               count++;
            //   index+=i;
               
           }
        }
        if(count==0)
            return 0;
        int lol=(count+1)/2;
        count=0;
        for(int i=0;i<A.size();i++)
            {
                if(A[i]=='x')
                    count++;
                
                if(count==lol)
                    {
                        lol=i;
                        break;
                    }
                    
            }
      
      
   int  ans=0;
   int left=lol-1,right=lol+1;
   
    for(int i=lol-1;i>=0;i--)  
        {
            if(A[i]=='x')
               {
                   ans=(ans+left-i)%mod;
                   left--;
               }
        }
   
    for(int i=lol+1;i<A.size();i++)
        {
            if(A[i]=='x')
                {
                    ans=(ans+i-right)%mod;
                    right++;
                }
        }
    ans=(ans)%mod;
 //   ans1=(ans1)%mod;
    return ans;
    
    
}
