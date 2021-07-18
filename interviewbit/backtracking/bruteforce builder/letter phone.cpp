void ac(string pb,string A,vector<string> mp,vector<string> &ans,int curr)
    {
        if(curr==A.size())
            {
                ans.push_back(pb);
                return;
            }
        for(int i=0;i<mp[A[curr]-'0'].size();i++)
            {   string pass=pb;
                char temp=mp[A[curr]-'0'][i];
                pass+=temp;
                ac(pass,A,mp,ans,curr+1);
            }
    }
vector<string> Solution::letterCombinations(string A) {
    vector<string> mp;
    mp.push_back("0");
    mp.push_back("1");
    char prev='a'-1;
    for(int i=2;i<=9;i++)
        {
            string curr;
            prev++;
            curr+=prev;
            prev++;
            curr+=prev;
            prev++;
            curr+=prev;
            if(i==7||i==9)
                {
             prev++;
            curr+=prev;
                }
            mp.push_back(curr);
        }
    vector<string> ans;
    string pb;
    ac(pb,A,mp,ans,0);
    return ans;
    
}
