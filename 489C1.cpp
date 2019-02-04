//Author - linpaws07
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
bool can_place(int m,int s){
    return s>=0&&s<=9*m;
}
int main(){
    int m,s;
    cin>>m>>s;
    if(s==0){
        if(m==1){
            cout<<"0 0"<<endl;
        }
        else{
            cout<<"-1 -1"<<endl;
        }
        return 0;
    }
    string str;
    int sc=s;
    for(int i=0;i<m;i++){
        for(int d=0;d<10;d++){
            if((i>0||d>0||(m==1&&d==0))&&can_place(m-i-1,s-d)){
                str+=char(d+'0');
                s-=d;
                break;
            }
        }
    }
    string maxs;
    s=sc;
    for(int i=0;i<m;i++){
        for(int d=9;d>=0;d--){
            if((i>0||d>0||(m==1&&d==0))&&can_place(m-i-1,s-d)){
                maxs+=char(d+'0');
                s-=d;
                break;
            }
        }
    }
    if(str.length()==0||maxs.length()==0){
        cout<<"-1 -1"<<endl;
    }
    else{
        cout<<str<<" "<<maxs<<endl;
    }
    return 0;
}