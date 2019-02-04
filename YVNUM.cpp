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
ll mod_expo(ll a, ll b){
    ll pro = 1;
    while(b){
        if(b&1){
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
ll calc(string num) { 
    ll res = 0; 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') % mod;   
    return res; 
}
ll modp[100002];
ll modx[100002];
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        modp[0] = 1;
        modp[1] = mod_expo(10,str.length());
        fre(i,2,str.length()){
            modp[i] = (modp[i-1] * modp[1] ) % mod; 
        }
        ll k1 = mod_expo(10,str.length()-1);
        ll xm = calc(str);
        ll k = str.length();
        modx[k--] = xm;
        fr(i, 0, str.length() - 1){
            int d = str[i]-'0';
            xm = (((xm - (d * k1) % mod) + mod ) % mod * 10 + d ) % mod;
            modx[k--] = xm;
        }
        ll ans = 0;
        k = str.length();
        frd(i, k, 1){
            ans = (ans + (modp[i-1] * modx[i]) % mod ) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}