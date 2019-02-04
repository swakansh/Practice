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
ll a[200002], b[200002];
int main(){
    FAST
    int n;
    cin >> n;
    rp(i, n/2){
        cin >> b[i];
    }
    a[0] = 0;
    a[n-1] = b[0];
    fr(i, 1, n/2){
        ll j = a[i-1];
        ll dif = b[i] - j;
        if(dif <= a[n-i]){
            a[i] = j;
            a[n-i-1] = dif; 
        }
        else{
            //cout << dif  << a[n-i] << endl;
            j += dif - a[n-i];
            dif -= dif - a[n-i];
            //cout << j << dif << endl;
            a[i] = j;
            a[n-i-1] = dif;
        }
    }
    rp(i,n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}