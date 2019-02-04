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
int main(){
    FAST
    string str;
    int ct=0,m,p,q;
    cin>>str;
    cin>>m;
    bool flag=false;
    str=" "+str;
    fr(i,1,str.length()){
        if(str[i]=='1') ct++;
    }
    fr(i,1,str.length()){
        fre(j,i+1,min(10,2*i-1)){
            if(str[i]=='1'&&str[j]=='1'){
                p=i,q=j;
                flag=true;
                break;
            }
        }
        if(flag)    break;
    }
    if(flag){
        //Wrong
    }
    else{
        if(m>ct){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            fr(i,1,str.length()){
                if(str[i]=='1'){
                    cout<<i<<" ";
                    m--;
                }
                if(!m)  break;
            }
            cout<<endl;
        }
    }
    return 0;
}