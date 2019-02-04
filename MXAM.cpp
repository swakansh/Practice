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
#define N 100002
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
bool check(int * ar,int n,int mid,int k){
    int left[N]={0};
    int right[N]={0};
    FOR(i,1,mid){
        left[ar[i]]++;
    }
    FOR(i,mid,n){
        right[ar[i]]++;
    }
    REP(i,N){
        left[i+1]+=left[i]/k;
        left[i]=left[i]%k;
        right[i+1]+=right[i]/k;
        right[i]=right[i]%k;
    }
    FORD(i,N-1,0){
        if(left[i]<right[i]){
            return 1;
        }
        else if(left[i]>right[i]){
            return 0;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ar[N];
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        int low=1,high=n;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            bool a = check(ar,n,mid,k);
            if(a){
                ans = mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}