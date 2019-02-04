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
ll dp[5002][5002];
ll p[5002];
int main(){
    FAST
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,1,n){
        cin>>p[i];
    }
    FOR(i,1,n){
        p[i]=p[i-1]+p[i];
    }
    FOR(i,1,n){
        FOR(j,1,k){
            if(m*j>i){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j];
                dp[i][j]=max(dp[i][j],dp[i-m][j-1]+(p[i]-p[i-m]));
            }   
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}