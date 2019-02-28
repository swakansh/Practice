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

int light[2002];
int64 fact[1002], invfact[1002], pow2[1002];
void check(int64 & a){
    a %= mod;
    if(a < 0)   a += mod;
}
int64 modexpo(int64 a, int e){
    int64 pro = 1;
    while(e){
        if(e & 1){
            e -= 1;
            pro = (pro * a);
            check(pro);
        }
        else{
            e /= 2;
            a = (a * a);
            check(a);
        }
    }
    return pro;
}
void util(){
    fact[0] = 1;
    fr(i, 1, 1002){
        fact[i] = (fact[i - 1] * i);
        check(fact[i]);
    }
    invfact[1001] = modexpo(fact[1001], mod - 2);
    frd(i, 1000, 0){
        invfact[i] = invfact[i + 1] * (i + 1);
        check(invfact[i]);
    }
    pow2[0] = 1;
    fr(i, 1, 1002){
        pow2[i] = (pow2[i - 1] * 2);
        check(pow2[i]); 
    }
}
int main(){
    FAST
    //Do awesome things here
    int n, m;
    cin >> n >> m;
    util();
    rp(i, m){
        int p;
        cin >> p;
        light[p] = 1;
    }
    int ct = 0;
    vector<int> ls;
    fre(i, 1, n){
        if(light[i] == 0){
            ct++;
        }
        else{
            if(ct == 0 && i == 1 || ct != 0) ls.pb(ct);
            ct = 0;
        }
    }
    ls.pb(ct);
    int sum = accumulate(ls.begin(), ls.end(), 0);
    int64 num = fact[sum];
    int len = ls.size();
    rp(i, len){
        num = (num * invfact[ls[i]]) % mod;
        if(i != 0 && i != len - 1){
            num = (num * pow2[ls[i] - 1]);
            check(num);
        }
    }
    cout << num << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}