vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> r;
    if(B>A.size())
        return r;
    map<int,int> count;
    for(int i=0;i<B;i++)
        {
            count[A[i]]++;
        }
    r.push_back(count.size());
    for(int i=B;i<A.size();i++)
        {
            if(count.find())
        }
}
