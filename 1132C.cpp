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
typedef long int ii;
typedef unsigned long int uii;
typedef long long int ll;
typedef unsigned long long int ull;
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
inline void check(ll & a){ a %= mod; if(a < 0) a += mod; }
auto start = high_resolution_clock::now();
inline void measure();

pii insct(int l1, int r1, int l2, int r2){
    if(l2 > r1 || l1 > r2)  return {-1, -1};
    else{
        return {max(l1, l2), min(r1, r2)};
    } 
}
int main(){
    FAST
    //Do awesome things here
    int n, q, cnt = 0;
    cin >> n >> q;
    vector<pii> vec;
    int arr[5002], one[5002], two[5002];
    rp(i, q){
        int l, r;
        cin >> l >> r;
        vec.pb({l, r});
        arr[l]++;
        arr[r + 1]--;
    }
    one[0] = 0;
    two[0] = 0;
    fr(i, 1, 5002){
        arr[i] += arr[i - 1];
        if(arr[i])  cnt++;
    }
    one[1] = (arr[1] == 1 ? 1 : 0);
    two[1] = (arr[1] == 2 ? 1 : 0);
    fr(i, 2, 5002){
        if(arr[i] == 1)
            one[i] = 1 + one[i - 1];
        else
            one[i] = one[i - 1];
        if(arr[i] == 2)
            two[i] = 1 + two[i - 1];
        else
            two[i] = two[i - 1];
    }
    int ans = -1;
    rp(i, vec.size()){
        fr(j, i + 1, vec.size()){
            int l1 = vec[i].f, r1 = vec[i].s, l2 = vec[j].f, r2 = vec[j].s;
            pii com = insct(l1, r1, l2, r2);
            int ctwo = 0;
            if(com.f != -1)
                ctwo = two[com.s] - two[com.f - 1];
            int rem = cnt - (one[r1] - one[l1 - 1]) - (one[r2] - one[l2 - 1]) - ctwo;
            ans = max(ans, rem);
        }
    }
    cout << ans << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}