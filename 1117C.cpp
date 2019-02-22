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

int n;
int64 x1, yl, x2, y2;
string s;
bool check(int64 mid){
    int64 u = 0, r = 0;
    rp(i, n){
        if(s[i] == 'U') r++;
        if(s[i] == 'L') u--;
        if(s[i] == 'R') u++;
        if(s[i] == 'D') r--;
    }
    int64 u1 = 0, r1 = 0;
    rp(i, mid % n){
        if(s[i] == 'U') r1++;
        if(s[i] == 'L') u1--;
        if(s[i] == 'R') u1++;
        if(s[i] == 'D') r1--;
    }
    int64 cyc = mid / n;
    int64 x3 = x1 + u * cyc + u1;
    int64 y3 = yl + r * cyc + r1;
    if(abs(x3 - x2) + abs(y3 - y2) <= mid){
        return true;
    }
    return false;
}
int main(){
    FAST
    //Do awesome things here
    cin >> x1 >> yl >> x2 >> y2;
    cin >> n;
    cin >> s;
    int64 low = 1, high = 1000000000000000, ans = -1;
    while(low <= high){
        int64 mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}