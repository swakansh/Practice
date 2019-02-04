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
    unsigned ll n, d;
    cin >> n >> d;
    int dig = 0;
    unsigned ll nc = n, ten = 1;
    bool n9 = false, nn9 = false;
    while(nc){
        if(nc % 10 != 9) {
            n9 = true;
            if(nc >= 10) nn9 = true;
        }
        nc /= 10;
        dig ++;
        ten *= 10;
    }
    if(d == 0 || !n9) {
        cout << n << endl;
        return 0;
    }
    unsigned ll num, ans = 0;
    ten /= 10;
    frd(i, dig - 1, 0) {
        num = n - n % ten - 1;
        if(num >= n - d && num <= n){
            break;
        }
        ten /= 10;
    }
    if(num % 10 != 9 || (n9 && !nn9))   cout << n << endl;
    else cout << num << endl;
    return 0;
}