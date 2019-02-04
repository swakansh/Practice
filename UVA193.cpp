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

vector<int> adj[102];
int col[102] = {0};
vector<int> mans, black;
int ans, colored;
bool visited[102] = {0};
int n, k;

bool can_color_black(int u){
    for(int a : adj[u]){
        if(col[a] == 0) return false;
    }
    return true;
}

void dfs(int u){
    if(colored == n) {
        if(ans < int(black.size())){
            ans = black.size();
            mans.clear();
            mans.resize(black.size());
            copy(black.begin(), black.end(), mans.begin());
        }
        return;
    }
    if(col[u] == -1){
        // not colored
        col[u] = 1;
        colored++;
        for(int a : adj[u]){
            dfs(a);
        }
        col[u] = -1;
        colored--;
        if(can_color_black(u)){
            col[u] = 0;
            colored++;
            black.pb(u);
            for(int a : adj[u]){
                dfs(a);
            }    
            black.pop_back();
            col[u] = -1;
            colored--;
        }
    }
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--) {
        colored = 0;
        ans = -1;
        cin >> n >> k;
        rp(i, 102){
            adj[i].clear();
            col[i] = -1;
        }
        rp(i, k){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        cout << ans << endl;
        rp(i, mans.size()){
            cout << mans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}