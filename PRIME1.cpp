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

bool segflag[100012];
bool flag[1000012];
vector<int> primes;
int64 a, b;
void sieve(){
    flag[0] = 1;
    flag[1] = 1;
    for(int64 i = 2;i < 1000002; i++){
        if(!flag[i]){
            primes.pb(i);
            for(int64 j = i * i; j <= 1000002 ;j += i){
                flag[j] = 1;
            }
        }
    }
}
void seg_sieve(){
    memst(segflag, 1);
    rp(i, primes.size()){
        int64 pr = primes[i];
        if(pr > sqrt(b))  break;
        int64 j = a / pr * pr;
        if(j < a)   j += pr;
        if(j == pr) j += pr;
        for(; j <= b ;j += pr){
            segflag[j - a] = false;
        }
    }
}
int main(){
    FAST
    //Do awesome things here
    sieve();
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        seg_sieve();
        fre(i, a, b){
            if(segflag[i - a] && i != 1){
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}