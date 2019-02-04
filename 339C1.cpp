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
int dp[1002]={0},m,s[2]={0};
string str;
bool solve(int i){
    if(i==m+1)  return true;
    fre(j,1,10){
        if(j!=dp[i-1]&&str[j-1]=='1'&&j+s[i%2]>s[(i+1)%2]){
            dp[i]=j;
            s[i%2]+=j;
            bool ans = solve(i+1);
            if(ans) return true;
            s[i%2]-=j;
        }
    }
    return false;
}
int main(){
    FAST
    cin>>str;
    cin>>m;
    bool ans = solve(1);
    if(ans){
        cout<<"YES"<<endl;
        fre(i,1,m){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}