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
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n>31){
            cout<<"YES "<<n-1<<endl;
        }
        else if(n<3&&k==3){
            cout<<"NO"<<endl;
        }
        else{
            ll tot = ((1ll << (2*n)) - 1 )/3;
            ll l = 1,r = min(tot,(ll)3),inc = 3;
            bool flag=true;
            n--;
            while(l<=tot&&l<=k){
                if(l<=k&&r>=k){
                    cout<<"YES "<<n<<endl;
                    flag=false;
                    break;
                }
                if(n>0)n--;
                inc=inc*2+1;
                l=r+1;
                r=min(tot,l+inc-1);
            }
            if(flag){
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}