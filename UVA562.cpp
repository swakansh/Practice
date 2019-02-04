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
int dp[102][500002];
int ar[105], n , total;

int solve(int ind, int sum){
    if(ind == n)    return abs(sum - (total - sum));
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int ans = min(solve(ind + 1, sum), solve(ind + 1, sum + ar[ind]));
    dp[ind][sum] = ans;
    return ans;
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        memset(dp, 255, sizeof dp);
        total = 0;
        cin >> n;
        rp(i, n){
            cin >> ar[i];
            total += ar[i];
        }
        cout << solve(0, 0) << endl;
    }
    return 0;
}