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
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[10002], ca[10002]= {0};
        rp(i, n){
            cin >> a[i + 1];
        }
        fre(i, 1, n){
            ca[i] += ca[i-1] + a[i];
        }
        ll yc, mc, dc, yb, mb, db;
        cin >> yb >> mb >> db;
        cin >> yc >> mc >> dc;
        if(yc == yb){
            if(mc == mb){
                cout << dc - db + 1<< endl;
            }
            else{
                ll ans = a[mb] - db + 1 + dc + ca[mc - 1] - ca[mb];
                cout << ans <<  endl;
            }
        }
        else{
            ll ans = ca[n] - ca[mb] + a[mb] - db + 1;
            if(yb % 4 == 0) ans += 1;
            ans += ca[mc - 1] + dc;
            ans += (yc - yb - 1) * ca[n];
            // do leap years adjustment
            ll ct = 0;
            fre(i, yb + 1, yc - 1){
                if(i % 4 == 0)  ct ++;
            }
            ans += ct;
            cout << ans << endl;
        }
    }
    return 0;
}