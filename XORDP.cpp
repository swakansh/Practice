/* 
    Author - linpaws07
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MID ((li +  ri) / 2)
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

ll ar[102];
ll dp[102][256][102];
ll fact[10000001]; 
void pre() { 
    fact[0] = 1; 
    for (int i = 1; i <= 10000000 ; i++) { 
        fact[i] = (fact[i - 1] * i) % mod; 
    } 
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    pre();
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n; i++){
        cin >> ar[i];
    }
    dp[0][0][0] = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 0; j <= 255; j++) {
            for(int l = 1; l <= n; l++) {
                if(i < l)   break;
                dp[i][j][l] = (dp[i - 1][j][l] + dp[i - 1][j ^ ar[i]][l - 1]) % mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cout << dp[n][k][i] << " " << fact[i] << endl;
        ans = (ans + (fact[i] * dp[n][k][i]) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
