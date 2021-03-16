#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
int findp(int *person,int x)
    {
        if(person[x]!=x)
        {
            person[x]=findp(person,person[x]);
        }
        return person[x];
    }
 void uni(int a,int b,int *rank,int* person)   
    {
        if(rank[a]>rank[b])
        {
                person[b]=a;
                rank[a]=rank[a]+rank[b];
        }
        else
        {
                person[a]=b;
                rank[b]=rank[a]+rank[b];
        }
    }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    
    int n,q;
    cin >> n >>q;
    int person[n+1],rank[n+1];
    for(int i=1;i<n+1;i++)
    {
        person[i]=i;
        rank[i]=1;
    }
    for(int j=0;j<q;j++)
    {
        char c;
        cin >> c;
        if(c=='Q')
            {
                int a;
                cin >> a;
                cout << rank[findp(person,a)] << endl;
            }
        else
            {
                int x,y;
                cin >> x >> y;
                    
                      int parx= findp(person,x);
                      int pary= findp(person,y);
                      if(parx!=pary)
                      {
                          uni(parx,pary,rank,person);
                      }
            }

    }
      
    return 0;
}
