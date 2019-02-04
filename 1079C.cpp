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
    int n;
    cin >> n;
    int ar[100002];
    rp(i, n){
        cin >> ar[i];
    }
    vector<int> ans;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(ar[0] == ar[1])  ans.pb(3);
    if(ar[0] > ar[1])   ans.pb(5);
    if(ar[0] < ar[1])    ans.pb(1);
    rp(i, n-1){
        if(ar[i] < ar[i + 1] && ans[i] == 5){
            cout << -1 << endl;
            return 0;
        }
        if(ar[i] > ar[i + 1] && ans[i] == 1){
            cout << -1 << endl;
            return 0;
        }
        int val;
        if(ar[i] > ar[i+1]){
            val = ans[i] - 1;
            if(i < n - 2) {
                if(ar[i + 1] < ar[i+2]) val = 1;
            }
        }
        else if(ar[i] < ar[i+1]){
            val = ans[i] + 1;
            if(i < n - 2) {
                if(ar[i+1] > ar[i+2]) val = 5;
            }
        }
        else{
            val = ((ans[i] == 3) ? 2 : 3);
            if(i < n - 2) {
                if(ar[i + 1] < ar[i + 2])   val = (ans[i] == 1 ? 2 : 1);
                else if(ar[i+1] > ar[i+2])  val = (ans[i] == 5 ? 4 : 5);
            }
        }
        // cout << val << endl;
        ans.pb(val);
    }
    rp(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}