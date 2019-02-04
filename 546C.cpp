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
vector<int> s1,s2;
int op=0;
void solve(){
    while(op<10000&&s1.size()&&s2.size()){
        if(s1[0]>s2[0]){
            s1.pb(s2[0]);
            s1.pb(s1[0]);
            s2.erase(s2.begin());
            s1.erase(s1.begin());
        }
        else{
            s2.pb(s1[0]);
            s2.pb(s2[0]);
            s1.erase(s1.begin());
            s2.erase(s2.begin());
        }
        op++;
    }
}
int main(){
    FAST
    int n,k1,k2,a;
    cin>>n;
    cin>>k1;
    rp(i,k1){
        cin>>a;
        s1.pb(a);
    }
    cin>>k2;
    rp(i,k2){
        cin>>a;
        s2.pb(a);
    }
    solve();
    if(op>=10000)  cout<<"-1"<<endl;
    else{
        int pl;
        if(s1.size())   pl=1;
        else    pl=2;
        cout<<op<<" "<<pl<<endl;
    }
    return 0;
}