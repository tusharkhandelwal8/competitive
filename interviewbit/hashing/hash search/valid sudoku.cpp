int Solution::isValidSudoku(const vector<string> &A) {
    set<char> sr[9],sc[9],sb[9];
    for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                {
                    
                    if(A[i][j]=='0'||A[i].size()>9)
                        return 0;
                if(A[i][j]!='.')
                {
                    if(sr[i].find(A[i][j])!=sr[i].end())
                        return 0;
                    else
                        sr[i].insert(A[i][j]);
                    
                    if(sc[j].find(A[i][j])!=sc[j].end())
                        return 0;
                    else
                        sc[j].insert(A[i][j]);
                    
                     int k=(i/3)*3+ j/3;
                     if(sb[k].find(A[i][j])!=sb[k].end())
                        return 0;
                    else
                        sb[k].insert(A[i][j]); 
                }        
                }
        }
        return 1;
    
}
