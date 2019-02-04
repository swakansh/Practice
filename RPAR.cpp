/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 10007
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


struct parabola{
    ll a, b, c;
    parabola(){
        a = b = c = 0;
    }
};

struct node{
    ll h;
    ll sum;
    ll ssum;
    bool lazy;
    parabola p;
    node(){
        sum = ssum = 0;
        h = 0;
        lazy = 0;
    }
};

node * sg = NULL;

void shift(int l, int r, int m, int ind){
    if(sg[ind].lazy){
        sg[ind * 2].lazy = 1;
        sg[ind * 2].h = (((sg[ind * 2].h + (sg[ind].p.a * (sg[ind * 2].ssum)) % mod) % mod + (sg[ind].p.b * sg[ind * 2].sum) % mod) % mod + (sg[ind].p.c * (m - l + 1)) % mod) % mod;
        sg[ind * 2].p.a = (sg[ind * 2].p.a + sg[ind].p.a) % mod;
        sg[ind * 2].p.b = (sg[ind * 2].p.b + sg[ind].p.b) % mod;
        sg[ind * 2].p.c = (sg[ind * 2].p.c + sg[ind].p.c) % mod;
        sg[ind * 2 + 1].lazy = 1;
        sg[ind * 2 + 1].h = (((sg[ind * 2 + 1].h + (sg[ind].p.a * (sg[ind * 2 + 1].ssum)) % mod) % mod + (sg[ind].p.b * sg[ind * 2 + 1].sum) % mod) % mod + (sg[ind].p.c * (r - m)) % mod) % mod;
        sg[ind * 2 + 1].p.a = (sg[ind * 2 + 1].p.a + sg[ind].p.a) % mod;
        sg[ind * 2 + 1].p.b = (sg[ind * 2 + 1].p.b + sg[ind].p.b) % mod;
        sg[ind * 2 + 1].p.c = (sg[ind * 2 + 1].p.c + sg[ind].p.c) % mod;
    }
    sg[ind].lazy = 0;
    sg[ind].p.a = sg[ind].p.b = sg[ind].p.c = 0;
}

void build_tree(ll l, ll r, int ind){
    if(l == r){
        sg[ind].h = 0;
        sg[ind].sum = l;
        sg[ind].ssum = (l * l) % mod;
        sg[ind].lazy = 0;
        sg[ind].p.a = sg[ind].p.b = sg[ind].p.c = 0;
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, ind * 2);
    build_tree(m + 1, r, ind * 2 + 1);
    sg[ind].sum = (sg[ind * 2].sum + sg[ind * 2 + 1].sum) % mod;
    sg[ind].ssum = (sg[ind * 2].ssum + sg[ind * 2 + 1].ssum) % mod;
    sg[ind].h = (sg[ind * 2].h + sg[ind * 2 + 1].h) % mod;
}

void update_tree(int ql, int qr, int l, int r, int ind, parabola p){
    if(ql > r || qr < l)    return;
    if(ql <= l && qr >= r){
        sg[ind].p.a = (sg[ind].p.a + p.a) % mod;
        sg[ind].p.b = (sg[ind].p.b + p.b) % mod;
        sg[ind].p.c = (sg[ind].p.c + p.c) % mod;
        sg[ind].lazy = 1;
        sg[ind].h = (((sg[ind].h + (p.a * (sg[ind].ssum)) % mod) % mod + (p.b * sg[ind].sum) % mod) % mod + (p.c * (r - l + 1)) % mod) % mod;
        return;
    }
    int m = (l + r) / 2;
    shift(l, r, m, ind);
    update_tree(ql, qr, l, m, ind * 2, p);
    update_tree(ql, qr, m + 1, r, ind * 2 + 1, p);
    sg[ind].h = (sg[ind * 2].h + sg[ind * 2 + 1].h) % mod;
}

ll query_tree(int ql, int qr, int l, int r, int ind){
    if(ql > r || qr < l)    return 0;
    if(ql <= l && qr >= r){
        return sg[ind].h;
    }
    int m = (l + r) / 2;
    shift(l, r, m, ind);
    ll lf = query_tree(ql, qr, l, m, ind * 2);
    ll rg = query_tree(ql, qr, m + 1, r, ind * 2 + 1);
    return (lf + rg) % mod;
}

void debug(int l, int r, int ind){
    if(l == r) {
        cout << l << ":" << r << endl;
        cout << sg[ind].sum << " " << sg[ind].ssum << " " << sg[ind].h << endl;
        return;
    }
    int m = (l + r) / 2;
    debug(l, m, ind * 2);
    debug(m + 1, r, ind * 2 + 1);
    cout << l << ":" << r << endl;
    cout << sg[ind].sum << " " << sg[ind].ssum << " " << sg[ind].h << endl;
}

int main(){
    FAST
    int n, q;
    cin >> n >> q;
    sg = new node[4 * n];
    build_tree(0, n - 1, 1);
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 0){
            parabola p;
            cin >> p.a >> p.b >> p.c;
            update_tree(l, r, 0, n - 1, 1, p);
            // debug(0, n - 1, 1);
        }
        else{
            cout << query_tree(l, r, 0, n - 1, 1) << endl;
        }
    }
    return 0;
}