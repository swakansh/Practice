/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();

bool pr[100002] = {0};
vector<int> prd[100002], mult[100002];
int main(){
    FAST
    //Do awesome things here
    for(int i = 2; i < 100002; i++){
        if(!pr[i]){
            prd[i].pb(i);
            for(int j = 2 * i; j < 100002; j += i){
                pr[j] = 1;
                prd[j].pb(i);
                mult[i].pb(j);
            }
        }
    }
    int n;
    cin >> n;
    int ar[100012], hsh[100012] = {0}, dp[100012] = {0};
    rp(i, n){
        cin >> ar[i];
        hsh[ar[i]] = 1;
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    rp(i, n){
        dp[ar[i]] =  max(1, dp[ar[i]]);
        rp(j, prd[ar[i]].size()){
            int prime = prd[ar[i]][j];
            int ind = upper_bound(mult[prime].begin(), mult[prime].end(), ar[i]) - mult[prime].begin();
            fr(k, ind, mult[prime].size()){
                if(hsh[mult[prime][k]]){
                    dp[mult[prime][k]] = max(dp[mult[prime][k]], dp[ar[i]] + 1);
                    break;
                }
            }
        }
    }
    int mx = -1;
    rp(i, 100002){
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}