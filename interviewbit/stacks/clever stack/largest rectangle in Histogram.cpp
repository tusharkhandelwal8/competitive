int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;
    s.push(0);
    int ans=A[0];
    int curr;
    for(int i=1;i<A.size();i++)
        {
            if(A[i]>A[s.top()])
                {
                    ans=max(ans,A[i]);
                    s.push(i);
                }
            else
                {
                    while((s.size()>1)&&(A[i]<=A[s.top()]))
                        {
                            curr=(A[s.top()]);
                            s.pop();
                            curr=curr*(i-s.top()-1);
                            ans=max(ans,curr);
                        
                        }
                        if(s.size()==1&&(A[i]<=A[s.top()]))
                            {
                                 curr=(i)*A[s.top()];
                                 ans=max(ans,curr);
                                 s.pop();
                            }
                        s.push(i);
                    
                }
        }
        
        while(s.size()>1)
            {   
                curr=(A[s.top()]);
                s.pop();
                curr=curr*(A.size()-s.top()-1);
                ans=max(ans,curr);
            
            }  
            curr=A.size()*A[s.top()];
            ans=max(ans,curr);

        return ans;
    
}
