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
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
vector<int> adj[300002];
vector<int> ans;
bool vis[300002]={0};
void dfs(int i, int p, int flag){
    if(vis[i])  return;
    ans.pb(i);
    vis[i] = true;
    rp(j, adj[i].size()){
        if(i == 1 && adj[i][j] != flag) continue;
        if(adj[i][j] == p)  continue;
        dfs(adj[i][j], i, flag);
    }
}
int main(){
    FAST
    int n;
    cin >> n;
    vector<pair<int,int> > ar;
    rp(i, n){
        int u, v;
        cin >> u >> v;
        ar.pb({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int val = ar[0].f, flag;
    if(ar[val - 1].f == ar[0].s || ar[val - 1].s == ar[0].s){
        flag = val;
    }
    else{
        flag = ar[0].s;
    }
    // cout << flag << endl;
    dfs(1, -1, flag);
    rp(i, ans.size()){
        cout << ans[i] << " " ;
    }
    cout << endl;
    return 0;
}