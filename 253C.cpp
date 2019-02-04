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

int a[102];
int n;
pii solve(int r, int c1, int c2) {
    //solve when both are in same row i.e r
    //Now they both are in same row
    int dif = 0;
    int a1 = inf, cc = c1;
    int rc = r;
    // either you have an optimal answer by going down
    while(rc < n) {
        rc++;
        cc = min(cc, a[rc - 1]);
        dif++;
        a1 = min(a1, dif * 2 + abs(cc - c2));
    }
    int a2 = inf;
    cc = c1, dif = 0;
    rc = r;
    // or you have an optimal answer by going up
    while(rc > 1) {
        rc--;
        dif++;
        cc = min(cc, a[rc - 1]);
        a2 = min(a2, dif * 2 + abs(cc - c2));
    }
    return {a1, a2};
}
int main(){
    FAST
    //Do awesome things here
    freopen ("output.txt", "w", stdout);
    freopen("input.txt", "r" , stdin);
    cin >> n;
    rp(i, n) {
        cin >> a[i];
        a[i] = a[i] + 1;
    }
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans1 = 0, ans2 = inf, ans = inf;
    if(r1 != r2) {
        if(r1 < r2){
            ans1 = (r2 - r1);
            int rc = r1;
            while(rc < r2) {
                rc++;
                c1 = min(c1, a[rc - 1]);
            }
            pii p = solve(rc, c1, c2);
            ans = min(ans, ans1 + min(abs(c1 - c2), min(p.f, p.s)));
            rc = r1;
            int steps = 0;
            while(rc > 1){
                rc--;
                steps++;
                c1 = min(c1, a[rc - 1]);
                ans2 = steps * 2 + ans1;
                pii p = solve(r2, c1, c2);
                ans = min(ans, ans2 + min(abs(c1 - c2), min(p.f, p.s)));
            }
            cout << ans << endl;
        }
        else if(r1 > r2){
            ans1 = (r1 - r2);
            int rc = r1;
            while(rc > r2) {
                rc--;
                c1 = min(c1, a[rc - 1]);
            }
            pii p = solve(rc, c1, c2);
            ans = min(ans, ans1 + min(abs(c1 - c2),min(p.f, p.s)));
            rc = r1;
            int steps = 0;
            while(rc < n){
                rc++;
                steps++;
                c1 = min(c1, a[rc - 1]);
                ans2 = steps * 2 + ans1;
                pii p = solve(r2, c1, c2);
                ans = min(ans, ans2 + min(abs(c1 - c2), min(p.f, p.s)));
            }
            cout << ans << endl;
        }
    }
    else{
        pii p = solve(r1, c1, c2);
        int ans = min(abs(c1 - c2), min(p.f, p.s));
        cout << ans << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}