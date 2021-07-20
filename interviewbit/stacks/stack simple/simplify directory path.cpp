string Solution::simplifyPath(string A) {
    string ans;
    stack<char> s;
    int curr=0;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]=='/')
                {
                    if(s.size()==0||s.top()!='/')
                        s.push('/');
                }
            else if(A[i]!='.')
                {
                    s.push(A[i]);
                }
            else
                {
                    if(i!=A.size()-1&&A[i+1]=='.')
                        {   
                            i++;
                            if(s.size()>1)
                                s.pop();
                            while(s.size()&&(s.top()!='/'))
                                {
                                    s.pop();
                                }    
                        }
                }
        }
        if(s.top()=='/')
            s.pop();
            
    while(s.size())
        {   
            
            ans+=s.top();
            s.pop();
        }
        if(ans.size()==0)
        ans+='/';
        reverse(ans.begin(),ans.end());
        return ans;
}
