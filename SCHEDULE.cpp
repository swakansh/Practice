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
string str;
int n,k;
bool check(int ti){
    int l = str.length(),ct=1,st=0,chng=0;
    for(int i=1;i<l;i++){
        if(str[i]==str[i-1]) ct++;
        else{
            if(ct>ti)   chng+=ct/(ti+1);
            ct=1;
        }
    }
    chng+=ct/(ti+1);
    if(chng<=k)   return true;
    return false;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>str;
        int chng1=0,chng2=0;
        int st1=0,st2=1;
        REP(i,str.length()){
            if(str[i]-'0'!=st1) chng1++;
            if(str[i]-'0'!=st2) chng2++;
            st1=(st1+1)%2;
            st2=(st2+1)%2;
        }
        chng1=min(chng1,chng2);
        if(chng1<=k){
            cout<<"1"<<endl;
            continue;
        }
        int low = 2, high = n;
        int ans;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}