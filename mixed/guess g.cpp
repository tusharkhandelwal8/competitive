#include <cstdio>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long  qua,midi,mid;
    
    long long l = 1, ri = n,cut=0,cutl,cutr,flag=0;
    while (1) {
         if(!cut)
         {   if(flag==1)
        { flag=0;
          midi=(l+ri+1)/2;
          cout << midi << endl;
          fflush(stdout);
          string bonus;
          cin >> bonus;
          if(bonus=="G")
            l=midi+1;
           else if(bonus=="L")
            ri=midi -1;
           else
            exit(0);
        }
             mid = (l + ri + 1) / 2;
            qua=(l+ri+3)/4;
        //1
        cout << qua << endl;
        fflush(stdout);
        string r,re,res,resp;
        cin >> r;
        if( r=="E")
            exit(0);
        //2 
        cout << mid << endl;
        fflush(stdout);
        cin >> re;
        if( re=="E")
            exit(0);
        // 3rd
        cout << mid << endl;
        fflush(stdout);
        cin >> res;
        if( res=="E")
            exit(0);
        //4th
        cout << qua << endl;
        fflush(stdout);
        cin >> resp;
        if( resp=="E")
            exit(0);
        //cutoff
        
        if(re=="G"&&res=="G"&&resp=="L")
        {
            flag=1;
            l=mid+1;
        }
        else  if(re=="G"&&res=="G"&&resp=="G")
        {
            l=mid+1;
        }
        else if(re=="L"&&res=="L")
        {
            ri=mid-1;
        }
        else if((r=="G"&&re=="G"&&res=="L"&&resp=="L")||(r=="L"&&re=="L"&&res=="G"&&resp=="G"))
        {
            l=qua+1;
            ri=mid-1;
        }
       else if((r=="G"&&re=="G"&&res=="L"&&resp=="G")||(r=="G"&&re=="L"&&res=="G"&&resp=="G"))
        {
            l=qua+1;
        }
        else if((r=="L"&&re=="L"&&res=="G"&&resp=="L")||(r=="L"&&re=="G"&&res=="L"&&resp=="L"))
        {
            ri=mid-1;
        }
        else if((r=="L"&&re=="G"&&res=="L"&&resp=="G")||(r=="G"&&re=="L"&&res=="G"&&resp=="L"))
        {
            cut=1;
            cutl=qua-1;
            cutr=mid+1;
            
        }
        
         }
         else
         {
              
         mid=(ri+cutr)/2;;
        
        qua = l + (cutl-l)/2;
        cout << qua << endl;
        fflush(stdout);
        string r,re,res,resp;
        cin >> r;
        if( r=="E")
            exit(0);
        //2 
        cout << mid << endl;
        fflush(stdout);
        cin >> re;
        if( re=="E")
            exit(0);
        // 3rd
        cout << mid << endl;
        fflush(stdout);
        cin >> res;
        if( res=="E")
            exit(0);
        //4th
        cout << qua << endl;
        fflush(stdout);
        cin >> resp;
        if( resp=="E")
            exit(0);
        //cutoff
        int flag=0;
        if(re=="G"&&res=="G"&&resp=="L")
        {
            flag=1;
            l=mid+1;
            cut=0;
        }
        else  if(re=="G"&&res=="G"&&resp=="G")
        {
            l=mid+1;
            cut=0;
        }
        else if(re=="L"&&res=="L")
        {
            ri=cutl-1;
            cut=0;
        }
        else if((r=="G"&&re=="G"&&res=="L"&&resp=="L")||(r=="L"&&re=="L"&&res=="G"&&resp=="G"))
        {
            l=qua+1;
            ri=mid-1;
        
        }
       else if((r=="G"&&re=="G"&&res=="L"&&resp=="G")||(r=="G"&&re=="L"&&res=="G"&&resp=="G"))
        {
            l=qua+1;
        }
        else if((r=="L"&&re=="L"&&res=="G"&&resp=="L")||(r=="L"&&re=="G"&&res=="L"&&resp=="L"))
        {
            ri=mid-1;
            
        }
        else if((r=="L"&&re=="G"&&res=="L"&&resp=="G")||(r=="G"&&re=="L"&&res=="G"&&resp=="L"))
        {
            cut=1;
            cutl=qua-1;
            cutr=mid+1;
            
        }
        
    }
          
             
           
            
         }


}
