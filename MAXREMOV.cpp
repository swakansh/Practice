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

int main(){
    FAST
    //Do awesome things here
    int t;
    cin >> t;
    while(t--){
        int pos[2][100002] = {0};
        int n, k;
        cin >> n >> k;
        vector<pii> vec;
        rp(i, n){
            int l, r;
            cin >> l >> r;
            pos[0][l]++;
            pos[0][r + 1]--;
            vec.pb({l, r});
        }
        fr(i, 1, 100001){
            pos[0][i] += pos[0][i - 1];
        }
        fr(i, 0, 100001){
            if(pos[0][i] == k) pos[0][i] = 1;
            else if(pos[0][i] == k + 1) pos[1][i] = 1, pos[0][i] = 0;
            else  pos[0][i] = 0;
        }
        fr(i, 1, 100001){
            pos[0][i] += pos[0][i - 1];
            pos[1][i] += pos[1][i - 1];
        }
        int ans = -1;
        rp(i, n){
            int l = vec[i].f, r = vec[i].s;
            int ctk =  pos[0][100000] - pos[0][r] + pos[0][l - 1];
            int ctk1 = pos[1][r] - pos[1][l - 1];
            ans = max(ans, ctk + ctk1);
        }
        cout << ans << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}