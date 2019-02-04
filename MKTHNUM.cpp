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
vector<int> da[8 * N];
int mi[8 * N];
int ma[8 * N];
int nind = 0;

int create_leaf(int val){
    int p = ++nind;
    da[p].pb(val);
    mi[p] = val;
    ma[p] = val;
    return p;
}

int create_parent(int li, int ri){
    int p = ++nind;
    l[p] = li;
    r[p] = ri;
    da[p].resize(da[li].size() + da[ri].size());
    merge(da[li].begin(), da[li].end(), da[ri].begin(), da[ri].end(), da[p].begin());
    mi[p] = min(mi[li], mi[ri]);
    ma[p] = max(ma[li], ma[ri]);
    return p;
}

int build_tree(int li, int ri){
    if(li == ri)  return create_leaf(ar[li]);
    return create_parent(build_tree(li, MID), build_tree(MID + 1, ri));
}

int query_tree(int p, int ql, int qr, int li, int ri, int k){
    if(ql > ri || qr < li)  return 0;
    if(ql <= li && qr >= ri){
        return da[p].size() - (upper_bound(da[p].begin(), da[p].end(), k) - da[p].begin());
    }
    return query_tree(l[p], ql, qr, li, MID, k) + query_tree(r[p], ql, qr, MID + 1, ri, k);
}

pi query_min_max(int p, int ql, int qr, int li, int ri){
    if(ql > ri || qr < li)  return {INT_MAX, INT_MIN};
    if(ql <= li && qr >= ri){
        return {mi[p], ma[p]};
    }
    pi lf = query_min_max(l[p], ql, qr, li, MID);
    pi rg = query_min_max(r[p], ql, qr, MID + 1, ri);
    return {min(lf.f, rg.f), max(lf.s, rg.s)};
}

int main(){
    FAST
    int q;
    cin >> n >> q;
    rp(i, n){
        cin >> ar[i];
    }
    tree_root[0] = build_tree(0, n - 1);
    int xr = 0;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if(c > (b - a + 1)){
            cout << -1 << endl;
            continue;
        }
        pi p = query_min_max(tree_root[0], a, b, 0, n - 1);
        ll low = p.f;
        ll high = p.s;
        // cout << low << " " << high << endl;
        c = (b - a + 1) - c;
        ll ans = -1;
        while(low <= high){
            ll mid = (low + high) / 2;
            xr = query_tree(tree_root[0], a, b, 0, n - 1, mid);
            if(xr <= c){
                ans = mid;
                high = mid - 1;
            }
            else if(xr > c){
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}