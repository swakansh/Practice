/* Author - linpaws07 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
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
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
ll mod_expo(__int128 a, __int128 e, __int128 md){
    ll pro = 1;
    while(e){
        if(e&1){
            pro = (pro * a) % md;
            e--;
        }
        else{
            a = (a * a) % md;
            e /= 2;
        }
    }
    return pro;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll md = abs(a-b);
        if(md==0)   md = mod;
        __int128 ad = mod_expo(a,n,md);
        __int128 bd = mod_expo(b,n,md);
        ll cd = (ad + bd) % md;
        ll ans = __gcd(cd,abs(a-b));
        cout<<ans % mod<<endl;
    }
    return 0;
}