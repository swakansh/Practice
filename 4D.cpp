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
int n,w,h;
int dp[5002];
int pos[5002];
vector<pair<pair<int,int>,int > > env,envc;
bool cmpw(pair<pair<int,int>,int>  a,pair<pair<int,int>,int > b){
    return a.f.f<b.f.f;
}
bool cmph(pair<pair<int,int>,int>  a,pair<pair<int,int>,int > b){
    return a.f.s<b.f.s;
}
bool cmp(pair<pair<int,int>,int>  a,pair<pair<int,int>,int > b){
    return a.f.f<b.f.f||(a.f.f==b.f.f&&a.f.s<b.f.s);
}
int main(){
    FAST
    cin>>n>>w>>h;
    rp(i,n){
        int a,b;
        cin>>a>>b;
        env.pb({{a,b},i+1});
    }
    sort(env.begin(),env.end(),cmpw);
    int ind1=-1,ind2=-1;
    rp(i,n){
        if(env[i].f.f>w){
            ind1=i;
            break;
        }
    }
    if(ind1==-1){
        cout<<"0"<<endl;
        return 0;
    }
    sort(env.begin()+ind1,env.end(),cmph);
    fr(i,ind1,n){
        if(env[i].f.s>h){
            ind2=i;
            break;
        }
    }
    if(ind2==-1){
        cout<<"0"<<endl;
        return 0;
    }
    fr(i,ind2,n)    envc.pb(env[i]);
    sort(envc.begin(),envc.end(),cmp);
    int dpmx=1,dpind=0;
    dp[0]=1;
    fr(i,1,envc.size()){
        int mx = -1,ind;
        rp(j,i){
            if(envc[j].f.f<envc[i].f.f&&envc[j].f.s<envc[i].f.s){
                if(1+dp[j]>mx){
                    mx=1+dp[j];
                    ind=j;
                }
            }
        }
        if(mx==-1){
            dp[i]=1;
            pos[i]=i;
        }
        else{
            dp[i]=mx;
            pos[i]=ind;
        }
        if(dpmx<dp[i]){
            dpmx=dp[i];
            dpind=i;
        }
    }
    cout<<dpmx<<endl;
    vector<int> aux;
    while(pos[dpind]!=dpind){
        aux.pb(envc[dpind].s);
        dpind=pos[dpind];
    }
    aux.pb(envc[dpind].s);
    frd(i,aux.size()-1,0)   cout<<aux[i]<<" ";
    cout<<endl;
    return 0;
}