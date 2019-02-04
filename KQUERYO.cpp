/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 300002
#define m ((li + ri) / 2)
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

//solving using persistent segtree

int ar[N], n, tree_root[8 * N];
int l[8 * N], r[8 * N];
vector<int> da[8 * N];
int nind = 0;

int create_leaf(int val){
    int p = ++nind;
    da[p].pb(val);
    return p;
}

int create_parent(int li, int ri){
    int p = ++nind;
    l[p] = li;
    r[p] = ri;
    da[p].resize(da[li].size() + da[ri].size());
    merge(da[li].begin(), da[li].end(), da[ri].begin(), da[ri].end(), da[p].begin());
    return p;
}

int build_tree(int li, int ri){
    if(li == ri)  return create_leaf(ar[li]);
    return create_parent(build_tree(li, m), build_tree(m + 1, ri));
}

int query_tree(int p, int ql, int qr, int li, int ri, int k){
    if(ql > ri || qr < li)  return 0;
    if(ql <= li && qr >= ri){
        return da[p].size() - (upper_bound(da[p].begin(), da[p].end(), k) - da[p].begin());
    }
    return query_tree(l[p], ql, qr, li, m, k) + query_tree(r[p], ql, qr, m + 1, ri, k);
}

int main(){
    FAST
    cin >> n;
    rp(i, n){
        cin >> ar[i];
    }
    tree_root[0] = build_tree(0, n - 1);
    int q, xr = 0;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        a ^= xr;
        b ^= xr;
        c ^= xr;
        if(a < 1)   a = 1;
        if(b > n)   b = n;
        if(a > b){
            xr = 0;
            cout << xr << endl;
            continue;
        }
        a--, b--;
        xr = query_tree(tree_root[0], a, b, 0, n - 1, c);
        cout << xr << endl;
    }
    return 0;
}