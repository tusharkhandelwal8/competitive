vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    multiset<int> s;
    vector<int> ans;
    if(B>A.size())
        return ans;
    s.insert(A[0]);
    for(int i=1;i<B;i++)
        {
            s.insert(A[i]);
        }
        auto pb=s.end();
            pb--;
            ans.push_back(*pb);
    for(int i=B;i<A.size();i++)
        {
            s.erase(s.find(A[i-B]));
            s.insert(A[i]);
            pb=s.end();
            pb--;
            ans.push_back(*pb);
            
            
        }
        return ans;
}
