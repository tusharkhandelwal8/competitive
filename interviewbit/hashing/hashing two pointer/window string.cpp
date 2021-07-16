string Solution::minWindow(string A, string B) {
    vector<int> um(250),cc(250),dd(250);
    vector<deque<int>> vec(250);
    deque<int> s;
    for(int i=0;i<B.size();i++)
        {
            um[B[i]]++;
        }
        int st=A.size()*5,end=A.size()*10;
    for(int i=0;i<A.size();i++)
        {
            if(um[A[i]]>=0)
                {
                    if(um[A[i]]>cc[A[i]])
                        {
                            cc[A[i]]++;
                            vec[A[i]].push_back(i);
                            dd[A[i]]++;
                            s.push_back(i);
                        }
                    else
                        {
                             vec[A[i]].push_back(i);
                            s.push_back(i);
                            dd[A[i]]++;
                            vec[A[i]].pop_front();
                        }
                    if(um==cc)
                        {    while(dd[A[s.front()]]>cc[A[s.front()]])
                                    {
                                       dd[A[s.front()]]--;
                                        s.pop_front();
                                        
                                    }
                            int csize= s.back()-s.front();
                            if(csize<end-st)
                                {
                                    st=s.front();
                                    end= s.back();
                                }
                        }
                        
                        
                }
        }
        string ans;
        if(st==5*A.size())
            return ans;
            
        for(int i=st;i<=end;i++)
            ans+=A[i];
        
        return ans;    
    
}
