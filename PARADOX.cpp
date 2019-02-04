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

vector<pair<int, bool > > adj[102];
int fr[102];
int stmt;

bool dfs(int i, int * agn, bool asn){
    fr[i] = stmt;
    if(agn[i] == -1){
        agn[i] = asn;
        return dfs(adj[i][0].f, agn, (asn ? (asn & adj[i][0].s) : (!adj[i][0].s)));
    }
    else{
        if(agn[i] != asn)   return false;
    }
    return true;
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t){
        fre(i, 0, t){
            adj[i].clear();
        }
        rp(i, t){
            int u;
            string v;
            cin >> u >> v;
            adj[i + 1].pb({u, v[0]=='t'});
        }
        bool flag = false;
        int assign[102];
        memset(assign, 255, sizeof assign);
        fre(i, 1, t){
            if(assign[i] != -1)   continue;
            stmt = i;
            bool ans = dfs(i, assign, true);
            if(!ans){
                fre(j, 1, t){
                    if(fr[j] == i)  assign[j] = -1;
                }
                ans = dfs(i, assign, false);
                if(!ans){
                    flag = true;
                    cout << "PARADOX" << endl;
                    break;
                }
            }
        }
        if(!flag){
            cout << "NOT PARADOX" << endl;
        }
        cin >> t;
    }
    return 0;
}