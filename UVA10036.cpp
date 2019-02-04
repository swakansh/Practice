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
int n, k;
int ar[10002];
int dp[10002][102];

bool solve(int i, int sum){
    if(i == n - 1)    return ((ar[n - 1] + sum) % k == 0 || ((sum - ar[n-1]) % k + k ) % k == 0);
    if(dp[i][sum] != -1)    return dp[i][sum];
    bool ans = solve(i + 1, (sum + ar[i]) % k);
    if(!ans)    ans = solve(i + 1, ((sum - ar[i]) % k + k ) % k);
    dp[i][sum] = ans;
    return ans;
}

int main(){
    FAST
    int t;
    cin>> t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        rp(i, n){
            cin >> ar[i];
        }
        bool ans = solve(0, 0);
        if(ans) cout << "Divisible" << endl;
        else   cout << "Not divisible" << endl;
    }
    return 0;
}