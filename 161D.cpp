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
vector<int> adj[50002];
int dp[50002][502];
ll kapart=0;
int n,k;
void dfs(int i,int p){
    dp[i][0]=1;
    fr(j,0,adj[i].size()){
        if(adj[i][j]!=p){
            dfs(adj[i][j],i);
            int aux[502]={0};
            rp(l,502){
                kapart += dp[i][k-l-1]*dp[adj[i][j]][l];
                aux[l+1] += dp[adj[i][j]][l];
            }
            rp(l,502){
                dp[i][l]+=aux[l];
            }
        }
    }
    return;
}
int main(){
    FAST
    cin>>n>>k;
    rp(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    cout<<kapart<<endl;
    return 0;
}