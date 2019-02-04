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
    ll r;
    ll lazy;
    node(){
        lazy = r = 0;
    }
};
 
node sg1[4 * N], sg2[4 * N], sg3[4 * N];
 
void shift(node * sg, ll ind, int l, int r){
    if(sg[ind].lazy){
        int mid = (l + r) / 2;
        sg[ind * 2].lazy = !sg[ind * 2].lazy;
        sg[ind * 2 + 1].lazy = !sg[ind * 2 + 1].lazy;
        sg[ind * 2].r = (mid - l + 1) - sg[ind * 2].r;
        sg[ind * 2 + 1].r = (r - mid) - sg[ind * 2 + 1].r;;
    }
    sg[ind].lazy = 0;
}
 
void update_tree(node * sg, ll l, ll r, ll ql, ll qr, ll ind){
    if(ql > r || qr < l)    return;
    if(ql <= l && r <= qr){
        sg[ind].r = (r - l + 1) - sg[ind].r;
        sg[ind].lazy = !sg[ind].lazy;
        return;
    }
    shift(sg, ind, l, r);
    ll mid = (l + r) / 2;
    update_tree(sg, l, mid, ql, qr, ind * 2);
    update_tree(sg, mid + 1, r, ql, qr, ind * 2 + 1);
    sg[ind].r = sg[ind * 2].r + sg[ind * 2 + 1].r;
}
 
ll query_tree(node * sg, ll l, ll r, ll ql, ll qr, ll ind){
    if(ql > r || qr < l)    return 0;
    if(ql <= l && r <= qr){
        return sg[ind].r;
    }
    shift(sg, ind, l, r);
    ll mid = (l + r) / 2;
    ll lf = query_tree(sg, l, mid, ql, qr, ind * 2);
    ll rg = query_tree(sg, mid + 1, r, ql, qr, ind * 2 + 1);
    return lf+rg;
}
 
int main(){
    FAST
    ll t;
    cin >> t;
    while(t--){
        memset(sg1, 0, sizeof sg1);
        memset(sg2, 0, sizeof sg2);
        memset(sg3, 0, sizeof sg3);
        ll nx, ny, nz;
        ll q;
        cin >> nx >> ny >> nz >> q;
        while(q--){
            ll t, x, y;
            cin >> t >> x >> y;
            if(t == 0){
                update_tree(sg1, 0, nx - 1, x, y, 1);
            }
            else if(t == 1){
                update_tree(sg2, 0, ny - 1, x, y, 1);
            }
            else if(t == 2){
                update_tree(sg3, 0, nz - 1, x, y, 1);
            }
            else{
                ll z, x1, y1, z1;
                cin >> z >> x1 >> y1 >> z1;
                ll x11 = query_tree(sg1, 0, nx - 1, x, x1, 1);
                ll x22 = query_tree(sg2, 0, ny - 1, y, y1, 1);
                ll x33 = query_tree(sg3, 0, nz - 1, z, z1, 1);
                ll s1 = x1 - x + 1;
                ll s2 = y1 - y + 1;
                ll s3 = z1 - z + 1;
                ll ans = 0;
                ans = x11 * ( s2 * s3) + (x22 * ((s1 - x11) * s3 - (x11 * s3)));
                ans = ans + x33 * (s1 * s2 - x11 * (s2 - x22) - x22 * (s1 - x11) - (x11 * (s2 - x22) + x22 * (s1 - x11)));
                cout << ans << endl;
            }
        }
    }
    return 0;
} 