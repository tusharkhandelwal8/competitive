int Solution::braces(string A) {
    stack<char> s;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]=='(')
                s.push('(');
            else if(A[i]==')')
                {
                    if(s.top()=='('||(i>=2&&(A[i-2]=='(')))
                        {
                            return 1;
                        }
                    else
                        {
                            while(s.top()!='(')
                                s.pop();
                            
                            s.pop();    
                        }
                }
            else
                s.push(A[i]);
        }
    return 0;
}
