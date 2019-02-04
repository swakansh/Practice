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

int n,c,ch,o=1000;
int low,high, ans = -1;
bool burn = false;
void probe_it(int dif){
    int prev = low,next = min(high,low+dif-1);
    while(1){
        cout<<1<<" "<<next<<endl;
        o-=1;
        fflush(stdout);
        cin>>ch;
        if(ch==0){
            prev = next + 1;
            next = min(n,prev + dif-1);
        }
        else{
            low = prev;
            high = min(n,next);
            burn=true;
            break;
        }
    }
    n=high;
}

int main(){
    FAST
    cin>>n>>c;
    low=1,high=n;
    probe_it(1000);
    if(burn){
        cout<<2<<endl;
        fflush(stdout);
        o-=c;
        burn=false;
    }
    probe_it(10);
    if(burn){
        cout<<2<<endl;
        fflush(stdout);
        o-=c;
        burn=false;
    }
    probe_it(2);
    if(burn){
        cout<<2<<endl;
        fflush(stdout);
        o-=c;
        burn=false;
    }
    cout<<1<<" "<<low<<endl;
    fflush(stdout);
    o-=1;
    cin>>ch;
    if(ch==0){
        cout<<3<<" "<<high<<endl;
    }
    else{
        cout<<3<<" "<<low<<endl;
    }
    return 0;
}