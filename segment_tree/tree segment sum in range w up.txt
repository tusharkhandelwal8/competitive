#include <bits/stdc++.h>
using namespace std;
#define max 1000000;
    void ct(int* arr,int* segtree,int start,int end,int pos)
        {   
            if(start==end)
                {segtree[pos]=arr[start];
                return;    
                }
            int mid=(start+end)/2;
            ct(arr,segtree,start,mid,2*pos+1);
            ct(arr,segtree,mid+1,end,2*pos+2);
            segtree[pos]= segtree[2*pos+1]+segtree[2*pos+2];
                
                
                
        }
    int query(int* segtree,int qlow,int qhigh,int low,int high,int ind)
        {
            if(qlow<=low&&qhigh>=high)
                return segtree[ind];
            else if(qlow>high||qhigh<low)
                return 0;
            int mid=(low+high)/2;
            return query(segtree,qlow,qhigh,low,mid,2*ind+1)+query(segtree,qlow,qhigh,mid+1,high,2*ind+2);
        }
    void update(int* arr,int* segtree,int ind,int ne,int node,int left,int right)
        {   segtree[node]+=ne-arr[ind];
            if(left==right)
                return;
            int mid=(left+right)/2;
            if(mid>=ind)
                {
                    update(arr,segtree,ind,ne,2*node+1,left,mid);
                    
                }
            else
                {
                    update(arr,segtree,ind,ne,2*node+2,mid+1,right);
                    
                }
            
            arr[ind]=ne;
        }
int main() {
	// your code goes here
  int arr[8] ={1,2,4,8,16,32,64,128};
  int len=sizeof(arr)/sizeof(arr[0]);
  int segtree[4*len-1];
    ct(arr,segtree,0,7,0);
  int len1=sizeof(segtree)/sizeof(segtree[0]);  
  for(int i=0;i<len1;i++)
        cout << segtree[i] << " ";
        cout << endl;
       cout << query(segtree,1,4,0,7,0);
       cout << endl;
	    update(arr,segtree,1,32,0,0,7);
	    cout << query(segtree,1,4,0,7,0);
	    cout << endl;
	    update(arr,segtree,2,32,0,0,7);
	    cout << query(segtree,2,4,0,7,0);
	    cout << endl;
	    update(arr,segtree,3,32,0,0,7);
	return 0;
}
