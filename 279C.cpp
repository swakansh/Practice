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
int n,m;
int ar[100002];
vector<pair<int,int> > op;
int main(){
    FAST
    cin>>n>>m;
    rp(i,n){
        cin>>ar[i];
    }
    bool f=1;
    int i,j;
    for(i=0,j=1;i<n&&j<n;){
        if(f){
            while(j<n&&ar[j]>=ar[j-1])  j++;
            f=!f;
        }
        else{
            while(j<n&&ar[j]<=ar[j-1]){
                j++;
            }
            op.pb({i,j-1});
            i=j-1;
            while(i>1&&ar[i]==ar[i-1])  i--;
            f=!f;
        }
    }
    op.pb({i,j});
    while(m--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        pair<int,int> p;
        p.f=l;
        p.s=r;
        int ind = lower_bound(op.begin(),op.end(),p)-op.begin();
        if(ind>=op.size()||op[ind].f!=l)    ind--;
        if(op[ind].s>=r)    cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
    return 0;
}