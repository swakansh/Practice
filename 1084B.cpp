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
int main(){
    FAST
    ll n, s, sum = 0;
    ll ar[1002];
    cin >> n >> s;
    rp(i, n){
        cin >> ar[i];
        sum += ar[i];
    }
    if(sum < s){
        cout << "-1" << endl;
    }
    else{
        sort(ar, ar + n);
        ll mi = ar[0], ex = 0;
        rp(i, n){
            ex += ar[i] - mi;
        }
        while(s > 0){
            if(ex >= s){
                break;
            }
            else{
                s -= ex;
                int q = s / n;
                if(q == 0){
                    mi-=1;
                    break;
                }
                mi -= q;
                ex = n * q;
            }
        }
        cout << mi << endl;
    }
    return 0;
}