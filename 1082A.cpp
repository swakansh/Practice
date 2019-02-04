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
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        if(x==y){
            cout<<0<<endl;
            continue;
        }
        if(x<y){
            if((y-x)%d==0){
                    cout<<(y-x)/d<<endl;
            }
            else{
                int st1 = (x-1)/d+((x-1)%d?1:0);
                if((y-1)%d==0){
                    st1+=(y-1)/d;
                }
                else{
                    st1=-1;
                }
                int st2 = (n-x)/d+((n-x)%d?1:0);
                if((n-y)%d==0){
                    st2+=(n-y)/d;
                }
                else{
                    st2=-1;
                }
                if(st1==-1&&st2==-1)    cout<<-1<<endl;
                else if(st1==-1&&st2!=-1)   cout<<st2<<endl;
                else if(st1!=-1&&st2==-1)   cout<<st1<<endl;
                else    cout<<min(st1,st2)<<endl;
            }
        }
        else{
            if((x-y)%d==0){
                    cout<<(x-y)/d<<endl;
            }
            else{
                int st1 = (x-1)/d+((x-1)%d?1:0);
                if((y-1)%d==0){
                    st1+=(y-1)/d;
                }
                else{
                    st1=-1;
                }
                int st2 = (n-x)/d+((n-x)%d?1:0);
                if((n-y)%d==0){
                    st2+=(n-y)/d;
                }
                else{
                    st2=-1;
                }
                if(st1==-1&&st2==-1)    cout<<-1<<endl;
                else if(st1==-1&&st2!=-1)   cout<<st2<<endl;
                else if(st1!=-1&&st2==-1)   cout<<st1<<endl;
                else    cout<<min(st1,st2)<<endl;
            }
        }
    }
    return 0;
}