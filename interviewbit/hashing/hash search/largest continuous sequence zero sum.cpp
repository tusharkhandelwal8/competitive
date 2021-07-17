vector<int> Solution::lszero(vector<int> &A) {
    
   
    unordered_map<int,int> um;
    int ml=0;
    int im=-1,jm=-1;
    int curr=0;
    
    for(int i=0;i<A.size();i++)
        {    curr+=A[i];
            if(curr==0)
                {
                    ml=i+1;
                    im=-1;
                    jm=i+1;
                }
            else if(um.find(curr)==um.end())
                um[curr]=i;
            else
                {
                    int f=um.find(curr)->second;
                    if(i-f>ml)
                        {
                            ml=i-f;
                            im=f;
                            jm=i+1;
                        }
                }
        
            
        }
    vector<int> ret;

    
    
    for(int i=im+1;i<jm;i++)
        {
            
                            ret.push_back(A[i]);
                        
                      //  return ret;
                
        }
        
    return ret;    
}
