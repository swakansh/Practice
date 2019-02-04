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
void split(int n, int k){
    if(k == 0)  return;
    if(k == 1){
        cout << n << " ";
        return;
    }
    if(k == n){
        rp(i, n){
            cout << 1 << " ";
        }
        return;
    }
    if(k <= n/2){
        cout << n / 2 << " ";
        split(n/2, k - 1);
    }
    else if(k > n/2){
        split(n/2, n/2);
        split(n/2, k - n/2);
    }
}
int main(){
    FAST
    int n, k;
    cin >> n >> k;
    int one = ones(n);
    if(k < one || k > n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        int dif = 0;
        int pro = 1, ct = 0;
        while(n){
            if(n&1){
                if(k==0){
                    cout << pro << " ";
                }
                else{
                    ct++;
                    dif = k - (one - ct);
                    if(dif >= pro){
                        split(pro, pro);
                        k -= pro;
                    }
                    else
                    {
                        split(pro, dif);
                        k = 0;
                        dif = 0;
                    }
                }
            }
            n >>= 1;
            pro *= 2;
        }
    }
    return 0;
}