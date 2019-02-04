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
ll ar[52],tar[12];
int main(){
    FAST
    int n,t;
    cin>>n>>t;
    while(n!=0&&t!=0){
        rp(i,n){
            cin>>ar[i];
        }    
        rp(i,t){
            cin>>tar[i];
        }
        vector<ll> lar;
        ll lcm = 1;
        fr(i,0,n){
            lcm = 1;
            lcm = (ar[i] * lcm)/(__gcd(lcm, ar[i]));
            fr(j,i+1,n){
                lcm = (ar[j] * lcm)/(__gcd(lcm, ar[j]));
                fr(k,j+1,n){
                    lcm = (ar[k] * lcm)/(__gcd(lcm, ar[k]));
                    fr(l,k+1,n){
                        lcm = (ar[l] * lcm)/(__gcd(lcm, ar[l]));
                        lar.pb(lcm);
                    }
                }
            }
        }
        rp(i,t){
            ll ans , mi = inf, ma = -inf;
            rp(j,lar.size()){
                mi = min(mi, lar[j] * (tar[i] / lar[j]) + ((tar[i] % lar[j])!=0?lar[j]:0));
                ma = max(ma, lar[j] * (tar[i] / lar[j]));
            }
            cout<<ma<<" "<<mi<<endl;
        }
        cin>>n>>t;
    }
    return 0;
}