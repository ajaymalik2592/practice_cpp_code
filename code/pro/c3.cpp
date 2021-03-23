# include<bits/stdc++.h>
 
using namespace std;
 
const int N = 5000 + 77;
const long long inf = 2e18;
int T;
int n , z , a[N];
long long ans , ps[N];
inline void Test() {
   ans = inf;
   scanf("%d %d" , & n , & z);
   for(int i = 1;i <= n;++ i)
      scanf("%d" , a + i);
   sort(a + 1 , a + 1 + n);
   for(int i = 1;i <= n;++ i)
      ps[i] = ps[i - 1] + a[i];
   for(int k = 0;k <= z;++ k) {
      int f = z - k;
      long long tot = ps[n] - ps[n - k];
      for(int i = f;i <= n - k;++ i)
         ans = min(ans , tot + ps[i] - ps[i - f] + max(0 , (n - k - i)) * 1ll * a[i]);
   }
   for(int k = 0;k <= z;++ k) {
      int f = z - k;
      int t = a[k];
      long long tot = ps[k] + (n - k) * 1ll * t;
      for(int i = k + 1;i + f - 1 <= n;++ i) {
         int le = i , ri = i + f - 1;
         ans = min(ans , (n - ri) * 1ll * (a[ri] - t) + tot + ps[ri] - ps[le - 1] - f * 1ll * t);
      }
   }
   printf("%lld\n" , ans);
}
int main() {
 
   scanf("%d" , & T);
   while(T --)
      Test();
   return 0;
}