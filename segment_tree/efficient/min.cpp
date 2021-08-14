#include<bits/stdc++.h>
using namespace std;
 const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1],t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p /= 2; ) t[p] = min(t[p * 2] , t[p * 2 + 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = INT_MIN;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
} 

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(4,-10);
  printf("%d\n", query(4, 5)); // query [a,b)  starts from index 0 to n-1
  return 0;
}

