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
bool visited[10002];
vector<int> adj[10002];
bool dfs(int u, int p){
    visited[u] = true;
    for(int to : adj[u]){
        if(to == p) continue;
        if(!visited[to])    dfs(to, u);
        else    return true;
    }
    return false;
}
int main(){
    FAST
    int n, m;
    cin >> n >> m;
    rp(i, m){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool edge_vio = false;
    if(m + 1 != n){
        edge_vio = true;
    }
    bool cycle = false, not_connected = false;
    for(int i = 1;i <= n; i++){
        if(!visited[i]){
            if(i > 1){
                not_connected = true;
                break;
            }
            cycle = dfs(i, -1);
        }   
    }
    if(edge_vio || not_connected || cycle){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}