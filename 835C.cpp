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
int dp[104][104][12];
ll t;
int x1,y111,x2,y2;
void solve(){
    fr(i,1,104){
        fr(j,1,104){
            fr(k,0,12){
                dp[i][j][k]+=dp[i][j-1][k];
            }
        }
    }
    fr(j,1,104){
        fr(i,1,104){
            fr(k,0,12){
                dp[i][j][k]+=dp[i-1][j][k];
            }
        }
    }
}
int main(){
    FAST
    int n,q,c;
    cin>>n>>q>>c;
    rp(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        dp[a][b][c]+=1;
    }
    solve();
    rp(i,q){
        cin>>t>>x1>>y111>>x2>>y2;
        int s[12]={0};
        ll ans=0;
        fr(j,0,12){
            s[j] = dp[x2][y2][j]-dp[x1-1][y2][j]-dp[x2][y111-1][j]+dp[x1-1][y111-1][j];
            ans += s[j] * ((j + t) % (c+1));
        }
        cout<<ans<<endl;
    }
    return 0;
}