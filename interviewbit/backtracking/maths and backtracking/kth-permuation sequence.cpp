string Solution::getPermutation(int A, int B) {
    vector<int> ret;
    for(int i=1;i<=A;i++)
        ret.push_back(i);
    
    int curr=0;
    do {
      curr++;
      if(curr==B)
        break;
    } while (next_permutation(ret.begin(), ret.end()));
    string ans;
    for(int i=0;i<ret.size();i++)
        {
         string add= to_string(ret[i]);
         ans+=add;
        }
        return ans;
    
}
    
