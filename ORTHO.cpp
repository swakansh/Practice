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
int mp[4012][4012];
int main(){
    FAST
    int n;
    cin >> n;
    vector<pi> po;
    vector<pi> xyd;
    rp(i, n){
        int x, y;
        cin >> x >> y;
        po.pb({x, y});
    }
    // unordered_map<pi, int> mp;
    rp(i, po.size()){
        fr(j, i + 1, po.size()){
            xyd.pb({po[i].f - po[j].f, po[i].s - po[j].s});
        }
    }
    rp(i, xyd.size()){
        int na = xyd[i].f + xyd[i].s;
        int nb = xyd[i].s;
        int gcd = __gcd(abs(na), abs(nb));
        na /= gcd;
        nb /= gcd;
        mp[na][nb]++;
    }
    int ans = 0;
    rp(i, xyd.size()){
        int na = xyd[i].f - xyd[i].s;
        int nb = xyd[i].s;
        int gcd = __gcd(abs(na), abs(nb));
        na /= gcd;
        nb /= gcd;
        assert (na < 4012 && nb < 4012);
        ans += mp[na][nb];
    }
    cout << ans << endl;
    return 0;
}