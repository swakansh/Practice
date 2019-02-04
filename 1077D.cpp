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
int hs[200002], ar[200002];
bool check(int m, int k){
    int sum = 0;
    rp(i, 200001){
        sum += hs[i] / m;
        if(sum >= k)    return true;
    }
    return false;
}
int main(){
    FAST
    int n, k;
    cin >> n >> k;
    rp(i, n){
        cin >> ar[i];
        hs[ar[i]]++;
    }
    int low = 1, high = n, ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    int ct = 0;
    rp(i, 200001){
        rp(j, hs[i] / ans){
            cout << i << " ";
            ct++;
            if(ct >= k) break;
        }
        if(ct >= k) break;
    }
    cout << endl;
    return 0;
}