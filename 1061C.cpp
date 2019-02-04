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
int ar[100002];
ll dp[1000002];
int main(){
    FAST
    int n, mx = 0;
    cin>>n;
    rp(i,n){
        cin>>ar[i];
        mx=max(mx,ar[i]);
    }
    dp[0]=1;
    fr(i,0,n){
        vector<int> mul;
        for(int j=1;j*j<=ar[i];j++){
            if(ar[i]%j==0){
                mul.pb(j);
                if(j*j!=ar[i]){
                    mul.pb(ar[i]/j);
                }
            }
        }
        sort(mul.rbegin(),mul.rend());
        rp(j,mul.size()){
            dp[mul[j]]=(dp[mul[j]]+dp[mul[j]-1]) % mod;
        }
    }
    ll ans = 0;
    fre(i,1,n){
        ans = (ans + dp[i]) % mod;
    }
    cout<<ans<<endl;
    return 0;
}