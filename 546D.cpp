/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define pl pair<ll, ll>
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
auto start = high_resolution_clock::now();
inline void measure(){ 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << duration.count() << endl;
}
int pre[5000002];
int flag[5000002];
int pdiv[5000002];
int main(){
    FAST
    int t;
    scanf("%d", &t);
    rp(i, 5000002){
        flag[i] = 1;
    }
    flag[0] = flag[1] = 0;
    fr(i, 2, 5000002){
        if(flag[i]){
            pdiv[i] = i;
            for(ll j=i;j*i<5000002;j++){
                flag[j*i] = 0;
                pdiv[j*i] = i;
            }
        }
    }
    pre[0] = 0;
    pre[1] = 0;
    pre[2] = 1;
    fr(i, 3, 5000002){
        int pd = (pdiv[i] == 0 ? i : pdiv[i]);
        pre[i] = 1 + pre[i / pd];
    }
    fr(i, 1, 5000002){
        pre[i] = pre[i] + pre[i - 1];
    }
    // measure();
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", pre[a] - pre[b]);
    }
    return 0;
}