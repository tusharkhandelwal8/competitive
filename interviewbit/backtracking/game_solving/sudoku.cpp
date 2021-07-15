void ss(vector<vector<char>> curr,vector<vector<char>> &A,int x,int y)
    {
        if(x==9)
            {
                A=curr;
                return;
            }
        else if(curr[x][y]!='.')
            {
                        if(y==8)
                           ss(curr,A,x+1,0);
                        else
                             ss(curr,A,x,y+1);
            }
        else
        {
        int valid[10]={0} ;
        for(int i=0;i<9;i++)
            {
                if(curr[x][i]!='.')
                    valid[curr[x][i]-'0']=1;
                
                if(curr[i][y]!='.')
                    valid[curr[i][y]-'0']=1;
                    
            }
            int xx=(x/3)*3;
            int yy=(y/3)*3;
        for(int i=xx;i<xx+3;i++)
            {
             for(int j=yy;j<yy+3;j++)
                {
                    if(curr[i][j]!='.')
                    valid[curr[i][j]-'0']=1;
                
                if(curr[i][y]!='.')
                    valid[curr[i][j]-'0']=1;
                }
            }
            
            for(int i=1;i<=9;i++)
                {
                    if(!valid[i])
                        {   
                            char pb=i+'0';
                            curr[x][y]=pb;
                        if(y==8)
                           ss(curr,A,x+1,0);
                        else
                             ss(curr,A,x,y+1);
                        }
                }    
        }
    }        
void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   vector<vector<char>> curr;
    curr=A;
   ss(curr,A,0,0);
   
        
    
}
