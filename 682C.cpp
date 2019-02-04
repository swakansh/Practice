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
const int inf = 1<<30;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
int n,ar[100002],dp[100002];
vector<pair<ll,ll> > adj[100002];
ll ans,mi=inf;
int dfs(int i,int par,ll dist,ll mini){
    if(mini>dist)   mini=dist;
    dp[i]=1;
    rp(j,adj[i].size()){
        if(par!=adj[i][j].f){
            dp[i] += dfs(adj[i][j].f,i,dist+adj[i][j].s,mini);
        }
    }
    if(dist-mini>ar[i]){
        ans += dp[i];
        return 0;
    }
    return dp[i];
}
int main(){
    FAST
    cin>>n;
    fre(i,1,n){
        cin>>ar[i];
    }
    fre(i,1,n-1){
        ll a,b;
        cin>>a>>b;
        adj[i+1].pb({a,b});
        adj[a].pb({i+1,b});
    }
    dfs(1,-1,0,mi);
    cout<<ans<<endl;
    return 0;
}