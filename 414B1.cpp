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
#define MOD 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
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
ll dp[2002][2002];
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,1,n){
        dp[1][i]=1;
    }
    FOR(i,1,k-1){
        FOR(j,1,n){
            for(int k=j;k<=n;k+=j){
                dp[i+1][k]=(dp[i+1][k]+dp[i][j]) % MOD;
            }
        }
    }
    ll ans = 0;
    FOR(i,1,n){
        ans = ( ans + dp[k][i] ) %  MOD;
    }
    cout<<ans<<endl;
    return 0;
}