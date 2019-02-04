/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 100002
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

struct node{
    bool lazy;
    bool slazy;
    ll val, val1;
    ll sum;
    ll ssum;
    node(){
        sum = 0;
        ssum = 0;
        lazy = slazy = false;
        val = 0, val1 = 0;
    }
};

int ar[N];

void shift(int ind, int l, int r, int m, node * sg){
    if(sg[ind].slazy){
        sg[ind * 2].slazy = 1;
        sg[ind * 2].sum = (m - l + 1) * sg[ind].val;
        sg[ind * 2].ssum = (m - l + 1) * sg[ind].val * sg[ind].val;
        sg[ind * 2].val = sg[ind].val;
        sg[ind * 2].lazy = 0;
        sg[ind * 2].val1 = 0;
        sg[ind * 2 + 1].slazy = 1;
        sg[ind * 2 + 1].sum = (r - m) * sg[ind].val;
        sg[ind * 2 + 1].ssum = (r - m) * sg[ind].val * sg[ind].val;
        sg[ind * 2 + 1].val = sg[ind].val;
        sg[ind * 2 + 1].lazy = 0;
        sg[ind * 2 + 1].val1 = 0;
    }
    sg[ind].val = 0;
    sg[ind].slazy = 0;
    if(sg[ind].lazy){
        sg[ind * 2].lazy = 1;
        sg[ind * 2].ssum = sg[ind * 2].ssum + (m - l + 1) * sg[ind].val1 * sg[ind].val1 + 2 * sg[ind].val1 * (sg[ind * 2].sum);
        sg[ind * 2].sum = sg[ind * 2].sum + (m - l + 1) * sg[ind].val1;
        sg[ind * 2].val1 += sg[ind].val1;
        sg[ind * 2 + 1].lazy = 1;
        sg[ind * 2 + 1].ssum = sg[ind * 2 + 1].ssum + (r - m) * sg[ind].val1 * sg[ind].val1 + 2 * sg[ind].val1 * (sg[ind * 2 + 1].sum);
        sg[ind * 2 + 1].sum = sg[ind * 2 + 1].sum + (r - m) * sg[ind].val1;
        sg[ind * 2 + 1].val1 += sg[ind].val1;
    }
    sg[ind].val1 = 0;
    sg[ind].lazy = 0;
}

void build_tree(int l, int r, int ind, node * sg){
    if(l == r){
        sg[ind].sum = ar[l], sg[ind].ssum = ar[l] * ar[l];
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, ind * 2, sg);
    build_tree(m + 1, r, ind * 2 + 1, sg);
    sg[ind].sum = sg[ind * 2].sum + sg[ind * 2 + 1].sum;
    sg[ind].ssum = sg[ind * 2].ssum + sg[ind * 2 + 1].ssum; 
}

void update_tree(int ql, int qr, int l, int r, int ind, node * sg, int up, int val){
    if(ql > r || qr < l)    return;
    if(ql <= l && qr >= r){
        if(up == 0){
            sg[ind].slazy = 1;
            sg[ind].val = val;
            sg[ind].val1 = 0;
            sg[ind].sum = (r - l + 1) * val;
            sg[ind].ssum = (r - l + 1) * val * val;
            sg[ind].lazy = 0;
        }
        else{
            sg[ind].lazy = 1;
            sg[ind].val1 += val;
            sg[ind].ssum = sg[ind].ssum + (r - l + 1) * val * val + 2 * val * (sg[ind].sum);
            sg[ind].sum = sg[ind].sum + (r - l + 1) * val;
        }
        return;
    }
    int m = (l + r) / 2;
    shift(ind, l, r, m, sg);
    update_tree(ql, qr, l, m, ind * 2, sg, up, val);
    update_tree(ql, qr, m + 1, r, ind * 2 + 1, sg, up, val);
    sg[ind].sum = sg[ind * 2].sum + sg[ind * 2 + 1].sum;
    sg[ind].ssum = sg[ind * 2].ssum + sg[ind * 2 + 1].ssum;
}

ll query_tree(int ql, int qr, int l, int r, int ind, node * sg){
    if(ql > r || qr < l)    return 0;
    if(ql <= l && qr >= r){
        return sg[ind].ssum;
    }
    int m = (l + r) / 2;
    shift(ind, l, r, m, sg);
    ll lf = query_tree(ql, qr, l, m, ind * 2, sg);
    ll rg = query_tree(ql, qr, m + 1, r, ind * 2 + 1, sg);
    return lf + rg;
}

int main(){
    FAST
    int t;
    cin >> t;
    fre(i, 1, t){
        cout << "Case " << i << ":" << endl;
        int n, q;
        cin >> n >> q;
        node * sg = new node[4 * n];
        rp(i, n){
            cin >> ar[i];
        }
        build_tree(0, n - 1, 1, sg);
        while(q--){
            int t;
            cin >> t;
            if(t == 0){
                int l, r, x;
                cin >> l >> r >> x;
                update_tree(--l, --r, 0, n - 1, 1, sg, t, x);
            }
            else if(t == 1){
                int l, r, x;
                cin >> l >> r >> x;
                update_tree(--l, --r, 0, n - 1, 1, sg, t, x);
            }
            else{
                int l, r;
                cin >> l >> r;
                cout << query_tree(--l, --r, 0, n - 1, 1, sg) << endl;
            }
        }
    }    
    return 0;
}