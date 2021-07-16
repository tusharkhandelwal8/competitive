int Solution::solve(vector<int> &A, int B) {
    int count=0;
    unordered_map<int,int> um;
    for(int i=0;i<A.size();i++)
        {
            int curr=B^A[i];
          if(um.find(curr)!=um.end())
            count+=um[curr];
            um[A[i]]++;
        }
        return count;
}
