/* Author - linpaws07 */
#include<bits/stdc++.h>
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
const ll inf = 1e15;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

vector<int> g[100002];
ll s[100002];
ll a[100002];
bool dfs(int u, int p, ll sum){
    if(s[u] == -1){
        ll mi = inf;
        for(auto to : g[u]){
            if(to == p) continue;
            mi = min(mi, s[to]);   
        }
        if(mi == inf){
            a[u] = 0;
            return true;
        }
        if(mi < sum)    return false;
        a[u] = mi - sum;                
        for(auto to : g[u]){
            if(to == p) continue;
            bool ans = dfs(to, u, sum + a[u]);
            if(!ans)    return false;
        }
        return true;
    }
    else{
        a[u] = s[u] - sum;
        for(auto to : g[u]){
            if(to == p) continue;
            bool ans = dfs(to, u, sum + a[u]);
            if(!ans)    return false;
        }
        return true;
    }
}
int main(){
    FAST
    int n;
    cin >> n;
    fre(i, 2, n){
        int p;
        cin >> p;
        g[i].pb(p);
        g[p].pb(i);
    }
    fre(i, 1, n){
        cin >> s[i];
    }
    bool ans = dfs(1, -1, 0);
    if(ans){
        ll sum = 0;
        fre(i, 1, n)
            sum += a[i];
        cout << sum << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}