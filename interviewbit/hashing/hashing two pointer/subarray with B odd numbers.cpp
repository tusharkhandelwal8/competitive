int Solution::solve(vector<int> &A, int B) {
    long long count=0;
    vector<int> s;
    for(int i=0;i<A.size();i++)
        {
            if(A[i]%2==1)
            s.push_back(i);
        }
        if(B==0)
            {   long long curr=0;;
                for(int i=0;i<A.size();i++)
                    {
                        if(A[i]%2==0)
                            curr++;
                        else
                            {
                                count+=(curr*(curr+1))/2;
                                curr=0;
                            }
                    }
                count+=(curr*(curr+1))/2;
                return count;
              //  cout << count << endl;
            }
        else if(B==1)
            {
                long long evenb=0,odd=0,evenf=0;
                   long long curr=0;;
                for(int i=0;i<A.size();i++)
                    {
                        if(A[i]%2==0)
                           {
                               if(odd==1)
                                evenb++;
                                else
                                evenf++;
                               
                           }
                        else
                            {
                                if(odd==1)
                                {
                                    count+=(evenb+evenf+1);
                                    evenf=evenb;
                                    evenb=0;
                                    
                                } 
                                else
                                    odd++;
                                    
                            }
                    }
                    if(odd)
                    count+=(evenb+evenf+1);
               // cout << count << endl;
               return count;
                
            }
            else
            {
                if(s.size()<B)
                    return 0;
                else if(s.size()==B)
                {   
                    return ((s[0]+1)*(A.size()-s[s.size()-1])) ;
                }
                else
                {
                    long long front=0,last=A.size();
                    for(int i=B-1;i<s.size();i++)
                        {
                            if(i==B-1)
                                {
                                    count+=((1+s[0]-front)*(s[i+1]-s[i]));
                                }
                            else if(i==s.size()-1)
                                {
                                    count+=((s[i-B+1]-s[i-B])*(last-s[i]));
                                }
                            else
                                {
                                    count+=((s[i-B+1]-s[i-B])*(s[i+1]-s[i]));
                                }
                        }
                        return count;
                    
                }
            }
            return count;
    
}
