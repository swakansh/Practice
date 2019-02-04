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
int ar[10000002];
vector<int> prime(10000002);
vector<int> ap,bp;
int mx=-1;
void sieve(){
    prime[0]=1;
    prime[1]=1;
    int i;
    for(i=2;i*i<=mx;i++){
        if(!prime[i]){
            int ct=0;
            for(int j=i*2;j<=mx;j+=i){
                prime[j]=1;
                if(ar[j])   ct+=ar[j];
            }
            ap.pb(i);
            if(ar[i])   ct+=ar[i];
            bp.pb(ct);
        }
    }
    for(int j=i;j<=mx;j++){
        int ct=0;
        if(!prime[j]){
            for(int k=j*2;k<=mx;k+=j){
                if(ar[k])   ct+=ar[k];
            }
            ap.pb(j);
            if(ar[j])   ct+=ar[j];
            bp.pb(ct);
        }
    }
}
int main(){
    FAST
    int n,a;
    cin>>n;
    rp(i,n){
        cin>>a;
        mx=max(mx,a);
        ar[a]++;
    }
    sieve();
    bp.pb(0);
    fre(i,1,bp.size()-1){
        bp[i]+=bp[i-1];
    }
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        r=min(r,mx);
        int ind1 = lower_bound(ap.begin(),ap.end(),l)-ap.begin();
        int ind2 = lower_bound(ap.begin(),ap.end(),r)-ap.begin();
        if(ind2>=ap.size()||ap[ind2]>r)  ind2--;
        if(ind1>ind2){
            cout<<0<<endl;
            continue;
        }
        else
            cout<<bp[ind2]-(ind1>0?bp[ind1-1]:0)<<endl;
    }
    return 0;
}