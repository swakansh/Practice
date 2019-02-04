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
#define mod 998244353
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
vector<int> adj[300002];
int asg[300002];
int col[12];
ll po[300002];
bool bad = true;
void dfs(int u, int c){
    asg[u] = c;
    col[c]++;
    rp(i, adj[u].size()){
        if(asg[adj[u][i]] == -1) dfs(adj[u][i], 1-c);
        if((asg[u] ^ asg[adj[u][i]]) == 0)  bad = true;
    }
}
int main(){
    FAST
    int t;
    cin >> t;
    po[0] = 1;
    fr(i, 1, 300002){
        po[i] = (po[i-1] * 2) % mod;
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        ll ans = 1;
        rp(i, n+1){
            asg[i] = -1;
            adj[i].clear();
        }
        memset(col, 0, sizeof col);
        rp(i, m){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        fr(i, 1, n+1){
            if(asg[i] != -1)    continue;
            bad = false;
            dfs(i, 0);
            if(bad){
                cout << 0 << endl;
                break;
            }
            else{
                ans = (ans * (po[col[0]] + po[col[1]])  % mod) % mod;
                col[0] = 0;
                col[1] = 0;
            }
        }
        if(!bad) cout << ans << endl;
    }
    return 0;
}