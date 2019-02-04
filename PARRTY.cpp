/* 
    Author - linpaws07
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MID ((li +  ri) / 2)
#define ll long long int
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define pl pair<ll, ll>
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

int s[233333], root[233333];

void gi(int &x) {char ch = getchar(); x = 0; while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();}

//begin persistent segment tree
const int sz = 5000000;
int a[sz], l[sz], r[sz], N, tn;
int add(int x, int p, int s = tn) {
  int u = ++N; a[u] = a[x] + 1; l[u] = l[x]; r[u] = r[x];
  if (s == 1) return u;
  else if (p < (s >> 1)) l[u] = add(l[x], p, s >> 1);
  else r[u] = add(r[x], p - (s >> 1), s >> 1);
  return u;
}

int sum(int x, int p, int s = tn) {
  if (s == 1) return a[x];
  else if (p < (s >> 1)) return sum(l[x], p, s >> 1);
  else return a[l[x]] + sum(r[x], p - (s >> 1), s >> 1);
}
//end persistent segment tree

int query(int l1, int r1, int l2, int r2) {
  return sum(root[r1], r2) + sum(root[l1 - 1], l2 - 1) - sum(root[l1 - 1], r2) - sum(root[r1], l2 - 1);
}

bool cmpa(pair<int, int> a, pair<int, int> b){
    return a.f < b.f || (a.f == b.f && a.s < b.s);
}

int main(){
    // FAST
    int t;
    gi(t);
    while(t--){
        N = 0;
        int n, m, i, j;
        gi(n);
        gi(m);
        for (tn = 1; tn <= n; tn <<= 1);
        vector<pi> mo;
        vector<pi> mo_one;
        rp(i, m){
            int l, r;
            gi(l);
            gi(r);
            if(l > r)   swap(l, r);
            mo.pb({l, r});
            mo_one.pb({l, i});
            mo_one.pb({r, i});
        }
        sort(mo_one.begin(),mo_one.end());
        sort(mo.begin(), mo.end(), cmpa);
        for (i = 1, j = 0; i <= n; i++) {
            root[i] = root[i - 1];
            for (; j < m && mo[j].f <= i; j++)
            root[i] = add(root[i], mo[j].s);
        }
        int S = 130;
        int q;
        cin >> q;
        fre(k1, 1, q){
            vector<pi> iv;
            int k;
            gi(k);
            rp(j, k){
                int l, r;
                gi(l);
                gi(r);
                iv.pb({l, r});
            }
            sort(iv.begin(), iv.end());
            if(iv.size() <= S){
                bool flag = false;
                int ans = 0;
                for (i = 0; i < k; i++){
                    for (j = i; j < k; j++){
                        ans = query(iv[i].f, iv[i].s, iv[j].f, iv[j].s);
                        if(ans >= 1){
                            flag = true;
                            break;
                        }
                    }
                    if(flag)    break;
                }
                if(flag)    cout << "NO" << endl;
                else    cout << "YES" << endl;
            }
            else{
                vector<int> flag(200002, 0);
                bool flag_two = false;
                for(int i = 0, j = 0; j < iv.size(); j++){
                    for(;i < mo_one.size() && mo_one[i].f < iv[j].f; i++);
                    for(;i < mo_one.size() && mo_one[i].f <= iv[j].s; i++){
                        if(flag[mo_one[i].s]){
                            flag_two = true;
                            break;
                        }
                        flag[mo_one[i].s]++;
                    }
                    if(flag_two)   break;
                }
                if(flag_two)    cout << "NO" << endl;
                else    cout << "YES" << endl;
            }
        }
    }
    return 0;
}