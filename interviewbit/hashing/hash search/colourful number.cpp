int Solution::colorful(int A) {
    vector<int> b;
    while(A)
        {
            b.push_back(A%10);
            A=A/10;
        }
    int flag=1;    
    unordered_map<int,int> um;
    for(int i=0;i<b.size();i++)
        {   long long curr=1;
            for(int j=i;j<b.size();j++)
                {
                    
                    curr=curr*b[j];
                    if(um.find(curr)==um.end())
                        um[curr]=1;
                    else
                        flag=0;
                        
                }
        }
    if(flag)
        return 1;
    else
        return 0;
}
