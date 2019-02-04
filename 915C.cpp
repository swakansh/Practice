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
string a,b;
int dig[10];
bool solve(int i,string ans){
    if(i==b.length()){
        cout<<ans<<endl;
        return true;
    }
    if(dig[b[i]-'0']){
        dig[b[i]-'0']--;
        if(solve(i+1,ans+b[i])) return true;
        dig[b[i]-'0']++;
    }
    int pos=b[i]-'0'-1;
    while(pos>=0&&!dig[pos]){
        pos--;
    }
    if(pos<0)   return false;
    cout<<ans;
    cout<<pos;
    dig[pos]--;
    frd(i,9,0){
        while(dig[i]--)   cout<<i;
    }
    cout<<endl;
    return true;
}
int main(){
    FAST
    cin>>a>>b;
    if(a.length()<b.length()){
        sort(a.rbegin(),a.rend());
        cout<<a<<endl;
    }
    else{
        rp(i,a.length()){
            dig[a[i]-'0']++;
        }
        solve(0,"");
    }
    return 0;
}