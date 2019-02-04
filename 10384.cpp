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
vector<bool> pr(20000002,1);
vector<int> prime;
void sieve(){
    pr[0]=pr[1]=0;
    pr[2]=pr[3]=1;
    ll p;
    for(int i=4;i<20000002;i+=2)
        pr[i]=0;
    for(int i=3;i<20000002;i+=2){
        if(pr[i]){
            for(ll j=i;j*i<20000002;j++){
                pr[i*j]=0;
            }
            if(pr[i-2]){
                prime.pb(i-2);
            }
        }
        if(prime.size()>100000) return;
    }
}
int main(){
    FAST
    int n;
    sieve();
    while(cin>>n){
        cout<<"("<<prime[n-1]<<", "<<prime[n-1]+2<<")"<<endl;
    }
    return 0;
}