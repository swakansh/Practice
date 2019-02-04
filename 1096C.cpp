/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod  998244353
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
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int ang;
        cin >> ang;
        int a1 = 180 - ang;
        int a2 = 360 - 2 * a1;
        int g1 = __gcd(360, a1);
        g1 = 360 / g1;
        int g2 = __gcd(360, a2);
        g2 = 360 / g2;
        int an = max(g1, g2);
        g1 = min(g1, g2);
        g2 = an;
        if((g1 - 2) * 180 / g1 >= ang){
            cout << g1 << endl;
        }
        else if((g2 - 2) * 180 / g2 >= ang){
            cout << g2 << endl;
        }
        else{
            cout << "-1" << endl;
        }
        // cout << a1 << " " << a2 << endl;
        // cout << min(g1, g2) << endl;
    }
    return 0;
}