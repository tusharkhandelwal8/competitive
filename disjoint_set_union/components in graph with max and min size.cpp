#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
int findp(int *par,int a)
{
    if(par[a]!=a)
    {
        par[a]=findp(par,par[a]);
    }
    return par[a];
}
void uni(int *rank,int *par,int c,int d)
{  if(rank[c]>rank[d])
        {
            par[d]=c;
            rank[c]=rank[c]+rank[d];

        }
     else
        {
            par[c]=d;
            rank[d]=rank[c]+rank[d];

        }

}
vector<int> componentsInGraph(vector<vector<int>> gb) {
    /*
     * Write your code here.
     */
     int a=gb.size();
     int par[2*a+1],rank[2*a+1];
     for(int j=0;j<=2*a;j++)
     {
         par[j]=j;
         rank[j]=1;
     }

     for(int i=0;i<a;i++)
     {
         int par1=findp(par,gb[i][0]);
        int par2=findp(par,gb[i][1]);
        if(par1!=par2)
        uni(rank,par,par1,par2);
     }
     int max=2,min=2*a,curr;
     for(int k=1;k<2*a+1;k++)
     {
         if(rank[k]>max&&par[k]==k)
            max=rank[k];
         if(rank[k]<min&&rank[k]!=1&&par[k]==k)
            min=rank[k];   
     }
     
vector<int> ret;
ret.push_back(min);
ret.push_back(max);
return ret;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
