/* Author - linpaws07 */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 100002
#define ll long long int
#define pb push_back
#define f first
#define s second
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

struct node{
    ll mul, add, sum;
    node(){
        mul = 1;
        add = 0;
        sum = 0;
    }
};

node sg[4 * N];

void shift(int ind, int l, int r, int mid){
    if(sg[ind].mul != 1 || sg[ind].add){
        sg[ind * 2].mul = (sg[ind * 2].mul * sg[ind].mul ) % mod;
        sg[ind * 2].add = (sg[ind * 2].add * sg[ind].mul ) % mod;
        sg[ind * 2 + 1].mul = (sg[ind * 2 + 1].mul * sg[ind].mul ) % mod;
        sg[ind * 2 + 1].add = (sg[ind * 2 + 1].add * sg[ind].mul ) % mod;
        sg[ind * 2].add = (sg[ind * 2].add + sg[ind].add ) % mod;
        sg[ind * 2 + 1].add = (sg[ind * 2 + 1].add + sg[ind].add ) % mod;
        sg[ind * 2].sum = ((sg[ind * 2].sum * sg[ind].mul) % mod + ((mid - l + 1) * sg[ind].add) % mod) % mod;
        sg[ind * 2 + 1].sum = ((sg[ind * 2 + 1].sum * sg[ind].mul) % mod + ((r - mid) * sg[ind].add) % mod) % mod;
    }
    sg[ind].mul = 1;
    sg[ind].add = 0;
}

void build(int l, int r, int ind, ll * ar){
    if(l == r){
        sg[ind].sum = ar[l];
        sg[ind].add = 0;
        sg[ind].mul = 1;
        return; 
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2, ar);
    build(mid + 1, r, ind * 2 + 1, ar);
    sg[ind].sum = (sg[ind * 2].sum + sg[ind * 2 + 1].sum) % mod;
}

void update(int ql, int qr, int l, int r, int ind, int op, ll v){
    if(qr < l || ql > r)    return;
    if(ql <= l && qr >= r){
        if(op == 2){
            sg[ind].sum = (sg[ind].sum * v ) % mod;
            sg[ind].mul = (sg[ind].mul * v) % mod;
            sg[ind].add = (sg[ind].add * v) % mod;
        }
        else if(op == 1){
            sg[ind].sum = (sg[ind].sum + ((r - l + 1 ) * v) % mod ) % mod;
            sg[ind].add = (sg[ind].add + v) % mod;
        }
        return;
    }
    int mid = (l + r) / 2;
    shift(ind, l, r, mid);
    update(ql, qr, l, mid, ind * 2, op, v);
    update(ql, qr, mid + 1, r, ind * 2 + 1, op, v);
    sg[ind].sum = (sg[ind * 2].sum + sg[ind * 2 + 1].sum) % mod;
}

ll query(int ql, int qr, int l, int r, int ind){
    if(qr < l || ql > r)    return 0;
    if(ql <= l && qr >= r){
        return sg[ind].sum;
    }
    int mid = (l + r) / 2;
    shift(ind, l, r, mid);
    ll lf = query(ql, qr, l , mid, ind * 2);
    ll rg = query(ql, qr, mid + 1, r, ind * 2 + 1);
    return (lf + rg) % mod;
}

ll ar[N];
int main(){
    FAST
    int n, q;
    cin >> n >> q;
    rp(i, n){
        cin >> ar[i];
    }
    build(0, n-1, 1, ar);
    rp(i, q){
        int t;
        cin >> t;
        if(t == 1){
            int x, y, v;
            cin >> x >> y >> v;
            x--, y--;
            update(x, y, 0, n-1, 1, 1, v);
        }
        else if(t == 2){
            int x, y, v;
            cin >> x >> y >> v;
            x--, y--;
            update(x, y, 0, n-1, 1, 2, v);
        }
        else if(t == 3){
            int x, y, v;
            cin >> x >> y >> v;
            x--, y--;
            update(x, y, 0, n-1, 1, 2, 0);
            update(x, y, 0, n-1, 1, 1, v);
        }
        else{
            int x, y;
            cin >> x >> y;
            x--, y--;
            ll ans = query(x, y, 0, n-1, 1);
            cout << ans << endl;
        }
    }
    return 0;
}