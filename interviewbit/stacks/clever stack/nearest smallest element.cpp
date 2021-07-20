vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    s.push(A[0]);
    vector<int> ans;
    ans.push_back(-1);
    for(int i=2;i<A.size();i++)
        {
                while(s.size()&&s.top()>=A[i])
                {
                     s.pop();
                }
                if(s.size()==0)
                    {
                        ans.push_back(-1);
                        s.push(A[i]);
                    }
                else
                    {
                        ans.push_back(s.top());
                        s.push(A[i]);
                    }
        }
        return ans;
}
