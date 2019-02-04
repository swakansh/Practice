/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
int flag[100002];
vector<ll> primes;
vector<ll> pfr[10002];
vector<int> adj[100002];
struct node{
    vector<int> ar;
    node(){
        ar.resize(100002, 0);        
    }
};
node pr[1300];

void update_bit(int wh, int in, int val){
    for(int i = in ; i < 100002; i += (i & (-i))){
        pr[wh].ar[i] += val;
    }
}

ll query_bit(int wh, int ql, int qr){
    ll a1 = 0, a2 = 0;
    for(int i = ql - 1; i > 0 ; i -= (i & (-i))){
        a1 += pr[wh].ar[i];
    }
    for(int i = qr; i > 0 ; i -= (i & (-i))){
        a2 += pr[wh].ar[i];
    }
    return (a2 - a1);
}

vector<int> c(100002), start(100002), fin(100002),disc(100002), idx(10002);

int cnt;

void dfs(int u, int p){
    start[u] = cnt;
    disc[cnt] = u;
    for(int to : adj[u]){
        if(to == p) continue;
        cnt++;
        dfs(to, u);
    }
    fin[u] = cnt;
}

int main(){
    FAST    
    auto sieve_lambda = [](){
        rp(i, 10002){
            flag[i] = 1;
        }
        flag[0] = 0;
        flag[1] = 0;
        for(ll i = 2; i <= 10000; i++){
            if(flag[i]){
                primes.pb(i);
                pfr[i].pb(i);
                for(ll j = 2; j * i <= 10000; j++){
                    flag[j * i] = 0;
                    pfr[j * i].pb(i);
                }
            }
        }
    };
    sieve_lambda();
    rp(i, primes.size()){
        idx[primes[i]] = i + 1;
    }
    int n;
    cin >> n;
    fre(i, 1, n){
        cin >> c[i];
    }
    rp(i, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cnt = 1;
    dfs(1, -1);
    int q;
    cin >> q;
    fre(i, 1, n){
        int ind = start[i];
        rp(j, pfr[c[i]].size()){
            update_bit(idx[pfr[c[i]][j]], ind, 1);
        }
    }
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            int ind = start[x];
            int val = c[x];
            c[x] = y;
            rp(i, pfr[val].size()){
                update_bit(idx[pfr[val][i]], ind, -1);
            }
            rp(i, pfr[y].size()){
                update_bit(idx[pfr[y][i]], ind, 1);
            }
        }
        else{
            int ql = start[x], qr = fin[x];
            ll ans = query_bit(idx[y], ql, qr);
            ans = (ans * (ans - 1) ) / 2;
            cout << ans << endl;
        }
    }
    return 0;
}