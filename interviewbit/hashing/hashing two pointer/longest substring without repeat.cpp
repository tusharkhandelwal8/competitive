int Solution::lengthOfLongestSubstring(string A) {
    deque<char> dq;
    unordered_map<char,int> s;
int ret=1;
    for(int i=0;i<A.size();i++)
        {
            if(s.find(A[i])!=s.end())
                {
                    while(dq.front()!=A[i])
                        {
                            s.erase(dq.front());
                            dq.pop_front();
                        }
                        dq.pop_front();
                        s.erase(A[i]);
                        s[A[i]]=1;
                        dq.push_back(A[i]);
                        
                        
                }
            else
                {
                    dq.push_back(A[i]);
                    s[A[i]]=1;
                }
                
                int curr=dq.size();
                ret=max(ret,curr);
                
        }
        return ret;
}
