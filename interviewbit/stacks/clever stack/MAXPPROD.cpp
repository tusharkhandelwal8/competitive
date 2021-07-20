int Solution::maxSpecialProduct(vector<int> &A) {
    long long ans=0;
    long long mod=1000000007;
    if(A.size()<3)
        return 0; 
    stack<long long > s;
    s.push(0);
    long long  left[A.size()]={0};
    left[0]=0;
    for(int i=1;i<A.size();i++)
        {
            while(s.size()&&(A[i]>=A[s.top()]))
                s.pop();
 
             if(s.size())
                left[i]=s.top();
              else
                left[i]=0;
 
               s.push(i);      
        }
    while(s.size())
        s.pop();   
    long long right[A.size()]={0};
    right[A.size()-1]=0;
    s.push(A.size()-1);
    for(int i=A.size()-2;i>=0;i--)
        {
            while(s.size()&&(A[i]>=A[s.top()]))
                s.pop();
 
             if(s.size())
                right[i]=s.top();
              else
                right[i]=0;
 
               s.push(i);      
        }
      for(int i=0;i<A.size();i++)
        {
 
                    long long curr=(left[i]*right[i]);
                    ans=max(ans,curr);
                
        }
        ans=(ans)%mod;
        int ch=ans;
        return ch;  
 
 
}
