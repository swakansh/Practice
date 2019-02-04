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
const ll inf = (ll)1<<62;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
int c[102],p[102][102];
ll dp[102][102][102];
int main(){
    FAST
    int n,m,k;
    cin>>n>>m>>k;
    fr(i,0,n){
        cin>>c[i];
    }
    fr(i,0,n){
        fr(j,0,m){
            cin>>p[i][j];
        }
    }
    fre(i,1,m){
        fr(j,1,100)
            dp[j][0][i]=inf;
    }
    fre(i,1,n){
        fre(j,1,k){
            fre(l,1,m){
                if(j>i)
                    dp[i][j][l]=inf;
                else{
                    if(c[i-1]!=0&&l!=c[i-1]){
                        dp[i][j][l]=inf;
                    }
                    else if(c[i-1]!=0&&c[i-1]==l){
                        dp[i][j][l]=inf;
                        fre(o,1,m){
                            dp[i][j][l] = min(dp[i][j][l],(l==o?dp[i-1][j][o]:dp[i-1][j-1][o]));
                        } 
                    }
                    else if(c[i-1]==0){
                        dp[i][j][l]=inf;
                        fre(o,1,m){
                            dp[i][j][l] = min(dp[i][j][l],(l==o?dp[i-1][j][o]:dp[i-1][j-1][o])+p[i-1][l-1]);
                        }
                    }
                }
            }
        }
    }
    ll ans = inf;
    fre(i,1,m){
        ans = min(ans, dp[n][k][i]);
    }
    if(ans==inf)    cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}