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
void gi(int &x) {char ch = getchar(); x = 0; while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();}

int cnt[12];
vector<int> adj[10002];

void dfs(int u, int p, int asg, vector<int> & dfsv){
    dfsv.pb(u);
    cnt[asg]++;
    rp(i, adj[u].size()) {
        if(adj[u][i] == p) continue;
        dfs(adj[u][i], u, 1 - asg, dfsv);
    }
}

int main(){
    int t;
    gi(t);
    while(t--){
        vector<int> dfsv;
        int n;
        cnt[0] = cnt[1] = 0;
        gi(n);
        rp(i, n - 1) {
            int u, v;
            gi(u);
            gi(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, -1, 0, dfsv);
        if(cnt[0] == cnt[1]){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
        for(int i = 0; i < dfsv.size(); i += 2)  cout << dfsv[i] << " ";
        cout << endl;
        for(int i = 1; i < dfsv.size(); i += 2)  cout << dfsv[i] << " ";
        cout << endl;
        rp(i, n + 1){
            adj[i].clear();
        }
        dfsv.clear();
    }
    return 0;
}