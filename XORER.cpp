/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();

string s;
int64 dp[10000002][2];
int64 dp1[10000002][2];
int main(){
    FAST
    //Do awesome things here
    int t;
    cin >> t;
    while(t--){
        int n;
        int64 a1 = 0, a2 = 0;
        cin >> n;
        cin >> s;
        dp[0][0] = (s[0] == '1' ? 0 : 1);
        dp[0][1] = (s[0] == '1' ? 1 : 0);
        fr(i, 1, n){
            if(s[i] == '0'){
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
            else{
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = dp[i - 1][1];
            }
        }
        dp1[n - 1][0] = (s[n - 1] == '1' ? 0 : 1);
        dp1[n - 1][1] = (s[n - 1] == '1' ? 1 : 0);
        frd(i, n - 2, 0){
            if(s[i] == '0'){
                dp1[i][0] = dp1[i + 1][0] + 1;
                dp1[i][1] = dp1[i + 1][1];
            }
            else{
                dp1[i][1] = dp1[i + 1][0] + 1;
                dp1[i][0] = dp1[i + 1][1];
            }
        }
        int64 ans = 0, mx = -1;
        rp(i, n){
            ans = (ans + dp[i][1]) % mod;
        }
        rp(i, n - 1){
            int64 sub1 = 0, sub2 = 0;
            sub1 = (sub1 + dp[i][0]) % mod;
            sub2 = (sub2 + dp[i][1]) % mod;
            int64 xor_zero = ((dp[i][0] * dp1[i + 1][0]) % mod + (dp[i][1] * dp1[i + 1][1]) % mod) % mod;
            int64 xor_one = ((dp[i][0] * dp1[i + 1][1]) % mod + (dp[i][1] * dp1[i + 1][0]) % mod) % mod;
            sub1 = (sub1 + xor_zero) % mod;
            sub2 = (sub2 + xor_one) % mod;
            int64 cans = (((ans + sub1) % mod - sub2) % mod + mod) % mod;
            mx = max(cans, mx);
        }
        int64 cans = (((ans + dp[n - 1][0]) % mod - dp[n - 1][1]) % mod + mod) % mod;
        mx = max(mx, cans);
        cout << mx << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}