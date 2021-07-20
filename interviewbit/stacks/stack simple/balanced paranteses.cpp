int Solution::solve(string A) {
    stack<char> s;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]=='(')
                s.push(A[i]);
            else
                {
                    if(s.size()==0)
                        return 0;
                    else
                        s.pop();
                }
        }
        if(s.size()==0)
            return 1;
        else
            return 0;
}
