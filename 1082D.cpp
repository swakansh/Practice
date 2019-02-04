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
int a[502];
vector<int> d2,d1;
int main(){
    FAST
    int n,sum=0;
    cin>>n;
    rp(i,n){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>1){
            d2.pb(i);
        }
        else{
            a[i]=0;
            d1.pb(i);
        }
    }
    if(sum<2*n-2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES "<<(d2.size()-1)+min(2,(int)d1.size())<<endl;
        cout<<n-1<<endl;
        if(d1.size()){
            cout<<d1.back()+1<<" "<<d2[0]+1<<endl;
            a[d2[0]]--;
            d1.pop_back();
        }
        fr(i,1,d2.size()){
            cout<<d2[i-1]+1<<" "<<d2[i]+1<<endl;
            a[d2[i-1]]--;
            a[d2[i]]--;
        }
        if(d1.size()){
            cout<<d1.back()+1<<" "<<d2[d2.size()-1]+1<<endl;
            a[d2[d2.size()-1]]--;
            d1.pop_back();
        }
        rp(i,n){
            while(a[i]&&d1.size()){
                cout<<d1.back()+1<<" "<<i+1<<endl;
                a[i]--;
                d1.pop_back();
            }
        }
    }
    return 0;
}