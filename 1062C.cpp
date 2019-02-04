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
ll mod_expo(ll a, int b){
    ll pro = 1;
    while(b){
        if(b & 1){
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
int main(){
    FAST
    int n, q;
    char ch;
    int ar1[100002], ar2[100002];
    cin >> n >> q;
    fre(i, 1, n){
        cin >> ch;
        ar1[i] = ch - '0';
        ar2[i] = 1- (ch - '0');
    }
    fre(i, 1, n){
        ar1[i] += ar1[i-1];
        ar2[i] += ar2[i-1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int c1 = ar1[r] - ar1[l - 1];
        int c0 = ar2[r] - ar2[l - 1];
        ll a1 = mod_expo(2, c1), a2 = mod_expo(2, c0);
        a1 -= 1;
        a1 = a1 % mod;
        cout << (a1 * a2 ) % mod << endl;
    }
    return 0;
}