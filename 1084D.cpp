/* Author - linpaws07 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
#define mod 1000000007
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
const ll inf = (ll)1<<39;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
int wt[300002];
bool vis[300002];
vector<pair<ll,ll> > adj[300002];
ll dp[300002][2];
void dfs(int u, int p){
    cout << "called for : " << u << endl;
    if(vis[u])  return;
    vis[u] = 1;
    rp(i, adj[u].size()){
        dp[u][0] = -inf;
        dp[u][1] = -inf;
        if(wt[u] - adj[u][i].s >= 0){
            dfs(adj[u][i].f, u);
            dp[u][0] = max(dp[u][0], wt[i] - adj[u][i].s);
            dp[u][1] = max(dp[u][1], wt[i] - adj[u][i].s + dp[adj[u][i].f][0]);
        }
        cout << "for " << u << " ans " << max(dp[u][0], dp[u][1]) << endl;
    }
}
int main(){
    FAST
    int n;
    cin >> n;
    fre(i, 1, n){
        cin >> wt[i];
    }
    rp(i, n - 1){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    fre(i, 1, n){
        if(!vis[i]){
            dfs(i, -1);
            cout << "back" << endl;
        }
    }
    ll ans = -inf;
    int ind;
    fre(i, 1, n){
        if(ans < max(dp[i][0], dp[i][1])){
            ans = max(dp[i][0], dp[i][1]);
            ind = i;
        }
    }
    cout << "ind: " << ind << endl;
    cout << ans << endl;
    return 0;
}