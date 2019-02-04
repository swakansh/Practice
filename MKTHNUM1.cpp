/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 300002
#define MID ((li + ri) / 2)
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
int sum[8 * N];
int nind = 0;

int create_leaf(int x){
    int p = ++nind;
    sum[p] = x;
    return p;
}

int create_parent(int li, int ri){
    int p = ++nind;
    l[p] = li;
    r[p] = ri;
    sum[p] = sum[li] + sum[ri];
    return p;
}

int build_tree(int li, int ri){
    if(li == ri)    return create_leaf(0);
    return create_parent(build_tree(li, MID), build_tree(MID + 1, ri));
}

int query_tree(int end, int st, int li, int ri, int k){
    if(li == ri)    return li;
    int cnt = sum[l[end]] - sum[l[st]];
    if(cnt >= k)
        return query_tree(l[end], l[st], li, MID, k);
    else
        return query_tree(r[end], r[st], MID + 1, ri, k - cnt);
}

int update_tree(int prev, int li, int ri, int ind){
    if(li == ri && li == ind){
        return create_leaf(1);
    }
    if(ind <= MID)   return create_parent(update_tree(l[prev], li , MID, ind), r[prev]);
    else    return create_parent(l[prev], update_tree(r[prev], MID + 1, ri, ind));
}

int main(){
    FAST
    int q;
    cin >> n >> q;
    vector<int> v;
    rp(i, n){
        cin >> ar[i + 1];
        v.pb(ar[i + 1]);
    }
    sort(v.begin(), v.end());
    rp(i, n){
        ar[i + 1] = lower_bound(v.begin(), v.end(), ar[i + 1]) - v.begin() + 1;
    }
    tree_root[0] = build_tree(1, v.size());
    fr(i, 1, n + 1){
        tree_root[i] = update_tree(tree_root[i - 1], 1, v.size(), ar[i]);
    }
    int xr = 0;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int k =  query_tree(tree_root[b], tree_root[a - 1], 1, v.size(), c);    
        cout << v[k - 1] << endl;
    }
    return 0;
}