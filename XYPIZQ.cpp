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
        ll n, ty, x, y, z;
        cin >> n >> ty >> x >> y >> z;
        ll num = 0, den = 2 * n + 1;
        if(ty == 1){
            if(x < z){
                num = 2 * n - y;
            }
            else if(x > z){
                num = 2 * n - y + 2;
            }
            else{
                if(y < z)   num = y + 1;
                else if(y > z)  num = y - 1;
            }
        }
        else if(ty == 2){
            num = 2 * n - 2 * y + 1;
        }
        else if(ty == 3){
            if(x < z){
                num = 2 * n - y + 2;
            }
            else if(x > z){
                num = 2 * n - y;
            }
            else{
                if(y < z)   num = y + 1;
                else if(y > z)  num = y - 1;
            }
        }
        else{
            num = 2 * n - 2 * y + 1;
        }
        ll gcd = __gcd(num, den);
        cout << num / gcd << " " << den / gcd << endl;
    }
    return 0;
}