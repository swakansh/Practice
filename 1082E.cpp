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
int n,c,mx=0;
int ar[500012],cnt[500012];
vector<int> last(500012,-1);
int get_count(int i1,int i2){
    return cnt[i2]-cnt[i1];
}
int getmax(vector<int> & seg){
    int ans = -inf, cans = 0;
    fr(i,0,seg.size()){
        cans = max(0,cans+seg[i]);
        ans = max(ans,cans);  
    }   
    return ans;
}
int main(){
    FAST
    cin>>n>>c;
    fr(i,0,n){
        cin>>ar[i];
        mx = max(mx,ar[i]);
        cnt[i+1] = cnt[i] + (ar[i]==c);
    }
    vector<vector<int> > seg(mx+1);
    fr(i,0,n){
        seg[ar[i]].pb(-get_count(last[ar[i]]+1,i));
        last[ar[i]]=i;
        seg[ar[i]].pb(1);
    }
    fre(i,0,mx){
        seg[i].pb(-get_count(last[i]+1,n));
    }
    int ans = 0;
    fre(i,0,mx){
        if(i == c) continue;
        ans = max(ans,getmax(seg[i]));
    }
    cout<<get_count(0,n)+ans<<endl;
    return 0;
}