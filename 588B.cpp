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
vector<ll> mul,pr(1000002,1),primes;
ll n;
void sieve(){
    pr[0]=0;
    pr[1]=0;
    fr(i,2,1000002){
        if(pr[i]){
            for(ll j=i;j*i<1000002;j++){
                pr[i*j]=0;
            }
            primes.pb(i);
        }
    }
}
void multiple(){
    fre(i,1,sqrt(n)){
        if(n%i==0){
            mul.pb(i);
            if(i*i!=n)
                mul.pb(n/i);
        }
    }
}
bool check(ll val){
    rp(i,primes.size()){
        if(val%(primes[i]*primes[i])==0)    return false;
    }
    return true;
}
int main(){
    FAST
    cin>>n;
    sieve();
    multiple();
    sort(mul.begin(),mul.end());
    ll ans;
    frd(i,mul.size()-1,0){
        if(check(mul[i])){
            ans=mul[i];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}