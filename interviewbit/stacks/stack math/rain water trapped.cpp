int Solution::trap(const vector<int> &A) {
    int ans=0;
    if(A.size()<=2)
        return ans;
        
  stack<int> s,c;
  for(int i=0;i<A.size();i++)
    {   int count=1;
        while(s.size())
            {
                if(s.top()>A[i])
                {
                    break;
                    
                }
                else if(s.top()==A[i])
                    {
                        count+=c.top();
                        c.pop();
                        s.pop();
                        break;
                    }
                else
                    {
                        if(s.size()>=2)
                           {
                           
                            int temp=c.top();
                            int val=s.top();
                            c.pop();
                            s.pop();
                             ans+= temp*(min(A[i],s.top())-val);
                            if(A[i]>s.top())
                            c.top()=c.top()+temp;
                            else
                            count+=temp;
                            
                            }
                        else    
                            {
                                s.pop();
                                c.pop();
                            }    
                          
                      }
            }
            s.push(A[i]);
            c.push(count);   
            
     }
         
    return ans;
}
