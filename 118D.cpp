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
#define MOD 100000000
#define ll long long int
#define pb push_back
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
ll dp[204][102][2];
int main(){
    FAST
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    FOR(i,1,n1+n2){
        FOR(j,0,n1){
            if(i>=j){
                FOR(k,1,k1){
                    if(i-k>=0&&j-k>=0)  dp[i][j][0]=( dp[i][j][0] + dp[i-k][j-k][1] ) % MOD;
                    else    break;
                }
                FOR(k,1,k2){
                    if(i-k>=0&&i-j-k>=0)  dp[i][j][1]=( dp[i][j][1] + dp[i-k][j][0] ) % MOD;
                    else    break;
                }
            }
            else    break;
        }
    }
    ll ans = ( dp[n1+n2][n1][0] + dp[n1+n2][n1][1] ) % MOD;
    cout<<ans<<endl;
    return 0;
}