/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int flag[100002];
vector<ll> primes;
vector<ll> pfr[10002];
vector<int> adj[100002];

struct node{
    ordered_set ar;
    node(){        
    }
};
node pr[1300];
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
            pr[idx[pfr[c[i]][j]]].ar.insert(start[i]);
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
                pr[idx[pfr[val][i]]].ar.erase(pr[idx[pfr[val][i]]].ar.find(ind));
            }
            rp(i, pfr[y].size()){
                pr[idx[pfr[y][i]]].ar.insert(ind);
            }
        }
        else{
            int ql = start[x], qr = fin[x];
            int v1 = (pr[idx[y]].ar).order_of_key(qr + 1);
            int v2 = (pr[idx[y]].ar).order_of_key(ql);
            ll ans = v1 - v2;
            ans = (ans * (ans - 1) ) / 2;
            cout << ans << endl;
        }
    }
    return 0;
}