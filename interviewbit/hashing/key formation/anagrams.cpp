vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> ret;
        unordered_map<string,vector<int>> um;
        for(int i=0;i<A.size();i++)
            {
                string curr=A[i];
                sort(curr.begin(),curr.end());
                um[curr].push_back(i+1);
            }
        for(auto i=um.begin();i!=um.end();i++)
            {
                ret.push_back(i->second);
            }
        for(int i=0;i<ret.size();i++)
            {
                sort(ret[i].begin(),ret[i].end());
            }
                            sort(ret.begin(),ret.end());
                            return ret;

}
