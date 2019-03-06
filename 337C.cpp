/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000009
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
typedef long int ii;
typedef unsigned long int uii;
typedef long long int ll;
typedef unsigned long long int ull;
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
inline void check(ll & a){ a %= mod; if(a < 0) a += mod; }
auto start = high_resolution_clock::now();
inline void measure();

ll mod_expo(ll a, int b){
    ll pro = 1;
    while(b){
        if(b & 1){
            pro = (pro * a) % mod;
            b--;
        }
        else{
            a = (a * a) % mod;
            b /= 2;
        }
    }
    return pro;
}
int main(){
    FAST
    //Do awesome things here
    int n, m, k;
    cin >> n >> m >> k;
    int q = n / k;
    int r = n % k;
    int mc = m;
    mc -= (q * (k - 1)) + r;
    if(mc <= 0){
        cout << m << endl;
    }
    else{
        ll ans = (((mod_expo(2, mc + 1) - 2) % mod + mod) % mod * k) % mod;
        int rem = ((q - mc) * (k - 1)) % mod;
        ans = ((ans + r) % mod + rem) % mod;
        cout << ans << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}