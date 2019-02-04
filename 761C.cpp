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
vector<string> sar;
vector<int> ind;
int n,m;
bool check(string str){
    int s=0,d=0,g=0;
    fr(i,0,str.length()){
        if(str[i]>='a'&&str[i]<='z')    s=1;
        if(str[i]>='0'&&str[i]<='9')    d=1;
        if(str[i]=='#'||str[i]=='*'||str[i]=='&')   g=1;
    }
    if(s&&d&&g) return true;
    return false;
}
ll solve(){
    string pass="";
    fr(i,0,n){
        pass+=sar[i][ind[i]];
    }
    if(check(pass)){
        return 0;
    }
    else{
        ll mi = inf;
        fr(i,0,n){
            int x = ind[i];
            ind[i] = (x+1)%m;
            mi = min(mi, solve());
            ind[i] = (x-1+m)%m;
            mi = min(mi,solve());
            ind[i]=x;
        }
        return 1+mi;
    }
}
int main(){
    FAST
    cin>>n>>m;
    fr(i,0,n){
        string str;
        cin>>str;
        sar.pb(str);
        ind.pb(0);
    }
    cout<<solve()<<endl;
    return 0;
}