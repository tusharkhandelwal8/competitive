int Solution::evalRPN(vector<string> &A) {
    stack<int> a;
    for(int i=0;i<A.size();i++)
        {
            if((A[i]=="-"||A[i]=="*"||A[i]=="/"||A[i]=="+"))
                {
                    int a1=a.top();
                    a.pop();
                    int a2=a.top();
                    a.pop();
                    if(A[i]=="+")
                        a1=a1+a2;
                    else if(A[i]=="-")
                        a1=a1-a2;
                    else if(A[i]=="/")
                        a1=a1/a2;
                    else
                        a1=a1*a2;
                    
                    a.push(a1);    
                    
                        
                }
            else
                {
                        int pb=stoi(A[i]);
                        a.push(pb);
                }
                
        }
        return a.top();
}
