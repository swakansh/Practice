/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (ll)1e18 + 5
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
inline ll check(ll & a){ a %= mod; if(a < 0) a += mod; }
auto start = high_resolution_clock::now();
inline void measure();

double dist(int ax, int ay, int bx, int by){
    ll dx = ax - bx;
    ll dy = ay - by;
    return sqrt((ll)(dx * dx) + (ll)(dy * dy));
}
double a[100002], b[100002], c[100002];
int main(){
    FAST
    //Do awesome things here
    int ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int m;
    cin >> m;
    double t = 0;
    fre(i, 1, m){
        int x, y;
        cin >> x >> y;
        double d = dist(tx, ty, x, y);
        t += 2 * d;
        a[i] = dist(ax, ay, x, y) - d;
        b[i] = c[i] = dist(bx, by, x, y) - d;
    }
    b[0] = c[m + 1] = inf;
    fre(i, 1, m)    b[i] = min(b[i], b[i - 1]);
    frd(i, m, 1)    c[i] = min(c[i], c[i + 1]);    
    double ans = t + c[1];
    fre(i, 1, m){
        ans = min(ans, t + min(0.0, min(b[i - 1], c[i + 1])) + a[i]);    
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}