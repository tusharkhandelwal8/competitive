#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}

int main(){
 int p,q;
 cin >> p >> q;
  long long ans = (p*binpow(q,MOD-2))%MOD;
    cout << ans <<endl;
}
