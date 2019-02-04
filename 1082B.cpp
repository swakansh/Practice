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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ar[100002],cnt=0;
    for(int i=0;i<s.length();i++){
        ar[i]=(s[i]=='G'?1:0);
        if(ar[i])   cnt++;
    }
    if(cnt==n) {
        cout<<n<<endl;
        return 0;
    }
    else if(cnt==0){
        cout<<0<<endl;
        return 0;
    }
    vector<int> cmp;
    if(ar[0]==0)    cmp.pb(0);
    else if(ar[0]&&!ar[1])  cmp.pb(1);
    for(int i=1;i<n;i++){
        if(ar[i]){   
            ar[i]+=ar[i-1];
            if(i+1<n&&ar[i+1]==0){
                cmp.pb(ar[i]);
            }
            else if(i+1==n){
                cmp.pb(ar[i]);
            }
        }
        else{
            cmp.pb(0);
        }
    }
    ll mx=-1,ind;
    for(int i=0;i<cmp.size();i++){
        ll csum=0;
        if(cmp[i]==0){
            if(i==0||i==cmp.size()-1){
                if(i==0)csum=cmp[1];
                else csum=cmp[cmp.size()-2];
            }
            else{
                csum=cmp[i-1]+cmp[i+1];
            }
            if(csum>mx){
                mx=csum;
                ind=i;
            }
        }
    }
    bool flag=false;
    for(int i=0;i<ind-1;i++){
        if(cmp[i]){  flag=true;break;}
    }
    for(int i=ind+2;i<cmp.size();i++){
        if(cmp[i]){  flag=true;break;}
    }
    if(flag){
        cout<<mx+1<<endl;
    }
    else{
        cout<<mx<<endl;
    }
    return 0;
}