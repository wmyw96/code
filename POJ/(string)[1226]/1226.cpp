#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
   
const int MAX_N = 200001, SUP = 1000000;
struct ls{
    int a, b, c;
    void mp(int aa, int bb, int cc){a = aa, b = bb, c = cc;}
};
ls s[MAX_N],ss[MAX_N];
int rk[MAX_N], a[MAX_N], b[MAX_N], sa[MAX_N], h[MAX_N], mk[MAX_N];
int cnt[MAX_N], H[MAX_N], len[MAX_N], hh[MAX_N], lll[MAX_N];
char st[MAX_N];
int n, N, K, ansn;
   
int build(int w){
    if (w > n) return n + 1;
    for (int i = 1; i <= n; ++i)
        s[i].mp(rk[i], rk[i + w], i);
       
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) ++cnt[s[i].b];
    for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i) ss[cnt[s[i].b]--] = s[i];
       
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) ++cnt[ss[i].a];
    for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i) s[cnt[ss[i].a]--] = ss[i];  
       
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        rk[s[i].c] = rk[s[i - 1].c] + (s[i].a != s[i-1].a || s[i].b != s[i-1].b),
        ret = max(ret, rk[s[i].c]);
           
    return ret;
}
   
int ck(int w){
    for (int i = 1; i <= N; i++) hh[i] = 0;
    int cnt = 1, now = 0;
    int i = 0;
    for (i = 1; i <= n && mk[sa[i]] != 0; ++i){
        if (h[i] >= w){
		   int j = mk[sa[i]];
		   
           if (hh[j] != cnt) now++, hh[j] = cnt;
           if (now >= K) return 1;
        }
        else{
             cnt++;
			 now = (len[sa[i]] >= w);
			 if (len[sa[i]] >= w) hh[mk[sa[i]]] = cnt;
			 if (now >= K) return 1;
        }
    }
    return 0;
}

int main(){
    int Ti;
    scanf("%d", &Ti);
    while (Ti--){
	      scanf("%d", &N);
          K = N;
          n = 0;
          
          memset(rk, 0, sizeof rk);
          memset(a, 0, sizeof a);
          memset(mk, 0, sizeof mk);
          memset(H, 0, sizeof H);
          memset(sa, 0, sizeof sa);
          memset(len, 0, sizeof len);
          memset(h, 0, sizeof h);
          memset(lll, 0, sizeof lll);

          int l = 0, r = 0;
          for (int i = 1; i <= N; ++i){
              scanf("%s", &st);
              int ll = strlen(st);
              for (int j = 1; j <= ll; ++j)
                  a[j + n] = st[j - 1],
                  H[a[j + n]] = 1,
                  mk[j + n] = i,
                  len[j + n] = ll - j + 1;
              lll[i] = ll;
              r = max(r, ll + 1);
              n += ll + 1;
              a[n] = 300 + i;
              H[a[n]] = 1;
          }
          int T_T = N;
          for (int i = 1; i < n; ++i)
              if (mk[n - i]) 
                 a[i + n] = a[n - i], 
                 mk[i + n] = mk[n - i], 
                 len[i + n] = lll[mk[n - i]] - len[n - i] + 1; 
                 else a[i + n] = 300 + (++T_T);
          n = n * 2 - 1;
          
          for (int i = 1; i <= 1000; ++i) H[i] += H[i - 1];
          for (int i = 1; i <= n; ++i) rk[i] = H[a[i]];
          for (int i = 1; i <= n && build(i) < n; i <<= 1);
          for (int i = 1; i <= n; ++i) sa[rk[i]] = i;
          for (int i = 1, j = 0; i <= n; ++i){
              if (rk[i] == 1) continue;
              for (j = max(0, j - 1); j <= n && a[i + j] == a[sa[rk[i] - 1] + j];) ++j;
              h[rk[i]] = j;
           }
           while (l + 1 < r){
                 int mid = (l + r) / 2;
                 if (ck(mid)) l = mid; else r = mid;
           }
           printf("%d\n", l); 
    }
    return 0;
}
