/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();
#define N 200002
int64 a[N], b[N], n, q;

//Persistent segment tree for B
int64 v[8 * N * 20], l[8 * N * 20], r[8 * N * 20], node = 1, root[8 * N * 20], cr = 0;
int new_leaf(int val){
    int p = node++;
    l[p] = r[p] = 0;
    v[p] = val;
    return p;
}
int new_parent(int lf, int rg){
    int p = node++;
    l[p] = lf;
    r[p] = rg;
    v[p] = v[lf] + v[rg];
    return p;
}
int build_tree(int lf = 0, int rg = n - 1){
    if(lf == rg)    return new_leaf(b[lf]);
    int mid = (lf + rg) / 2;
    return new_parent(build_tree(lf, mid), build_tree(mid + 1, rg));
} 
int update_tree(int p, int ind, int v, int lf = 0, int rg = n - 1){
    if(lf == rg)    return new_leaf(v);
    int mid = (lf + rg) / 2;
    if(ind <= mid)  return new_parent(update_tree(l[p], ind, v, lf, mid), r[p]);
    else    return new_parent(l[p], update_tree(r[p], ind, v, mid + 1, rg));
}
int64 query_tree(int p, int ql, int qr, int lf = 0, int rg = n - 1){
    if(qr < lf || ql > rg)  return 0;
    if(ql <= lf && qr >= rg)    return v[p];
    int mid = (lf + rg) / 2;
    return query_tree(l[p], ql, qr, lf, mid) + query_tree(r[p], ql, qr, mid + 1, rg);
}

//Normal segtree for A with support for lazy propagation
class sg{
    public:
    int64 sum;
    bool lazy;
    int bv, x, ql;
    sg(){
        lazy = 0;
        sum = 0;
        bv = -1, x = 0;
    }
    sg(int v){
        sum = 0;
        lazy = 0;
        bv = -1, x = 0;
    }
} st[4 * N];

void propagate(int p, int lf, int rg){
    if(st[p].lazy){
        st[p * 2].lazy = st[p].lazy;
        st[p * 2 + 1].lazy = st[p].lazy;
        int mid = (lf + rg) / 2;
        st[p * 2].sum = query_tree(root[st[p].bv], st[p].x + (lf - st[p].ql), (mid - st[p].ql) + st[p].x);
        st[p * 2 + 1].sum = query_tree(root[st[p].bv], st[p].x + (mid + 1 - st[p].ql), (rg - st[p].ql) + st[p].x);
        st[p * 2].bv = st[p * 2 + 1].bv = st[p].bv;
        st[p * 2].x = st[p * 2 + 1].x = st[p].x;
        st[p * 2].ql = st[p * 2 + 1].ql = st[p].ql;
    }
    st[p].lazy = false;
    st[p].bv = st[p].x = 0;
}

void a_build_tree(int p, int lf = 0, int rg = n - 1){
    if(lf == rg){
        st[p].sum = a[lf];
        return;
    }
    int mid = (lf + rg) / 2;
    a_build_tree(p * 2, lf , mid);
    a_build_tree(p * 2 + 1, mid + 1, rg);
    st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
}

int64 a_query_tree(int p, int ql, int qr, int lf = 0, int rg = n - 1){
    if(qr < lf || ql > rg)  return 0;
    if(ql <= lf && qr >= rg)    return st[p].sum;
    propagate(p, lf, rg);
    int mid = (lf + rg) / 2;
    return a_query_tree(p * 2, ql, qr, lf, mid) + a_query_tree(p * 2 + 1, ql, qr, mid + 1, rg); 
}

void a_update_tree(int p, int ql, int qr, int x, int lf = 0, int rg = n - 1){
    if(qr < lf || ql > rg)  return;
    if(ql <= lf && qr >= rg){
        st[p].sum = query_tree(root[cr], x + (lf - ql), x + (rg - ql));
        st[p].lazy = 1;
        st[p].bv = cr;
        st[p].x = x;
        st[p].ql = ql;
        return;
    }
    propagate(p, lf, rg);
    int mid = (lf + rg) / 2;
    a_update_tree(p * 2, ql, qr, x, lf, mid);
    a_update_tree(p * 2 + 1, ql, qr, x, mid + 1, rg);
    st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
}

int main(){
    FAST
    //Do awesome things here
    cin >> n >> q;
    rp(i, n){
        cin >> a[i];
    }
    rp(i, n){
        cin >> b[i];
    }
    root[0] = build_tree();
    a_build_tree(1);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int z, y;
            cin >> z >> y;
            root[cr + 1] = update_tree(root[cr], z - 1, y);
            cr++;
        }
        else if(t == 2){
            int lf, rg, x;
            cin >> lf >> rg >> x;
            a_update_tree(1, lf - 1, rg - 1, x - 1);
        }
        else{
            int lf, rg;
            cin >> lf >> rg;
            int64 ans = a_query_tree(1, lf - 1, rg - 1);
            cout << ans << endl;
        }
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}