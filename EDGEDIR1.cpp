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
vector<pair<int,int> > adj[100002];
vector<pair<int,int> > edge(100002);
int off = 100002;
int flag[200004]={0},degree[100002]={0};
int n,m;
bool check(){
    fre(i,1,n){
        if(degree[i]%2) return false;
    }
}
bool backtrack(int i){
    if(i==m+1){
        if(check()) return true;
        return false;
    }
    flag[i]=0;
    degree[edge[i].s]+=1;
    if(backtrack(i+1))  return true;
    degree[edge[i].s]-=1;
    flag[i]=1;
    degree[edge[i].f]+=1;
    if(backtrack(i+1))  return true;
    degree[edge[i].f]-=1;
    return false;
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        rp(i,m){
            int a,b;
            cin>>a>>b;
            // adj[a].pb({b,i+1});
            // adj[b].pb({a,i+1});
            edge[i+1].f=a;
            edge[i+1].s=b;
        }
        if(m&1){
            cout<<"-1"<<endl;
            continue;
        }
        backtrack(1);
        fre(i,1,m){
            cout<<flag[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}