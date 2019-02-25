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


int solveEven(const string& s) {
    if (s.length() % 2 == 1) {
        return 2;
    }
    string lf = s.substr(0, s.length() / 2);
    string rg = s.substr(s.length() / 2, s.length() / 2);
    if (lf != rg) return 1;
    return solveEven(lf);
}
int main(){
    FAST
    //Do awesome things here
    string s, s1, s2;
    set<char> a;
    cin >> s;
    int l = s.length();
    rp(i, l / 2){
        a.insert(s[i]);
        s1 += s[i];
    }
    fr(i, l / 2 + l % 2, l){
        s2 += s[i];
    }
    if(s.length() < 3){
        cout << "Impossible" << endl;
        return 0;
    }
    if(a.size() == 1){
        cout << "Impossible" << endl;
    }
    else{
        if(l & 1){
            cout << 2 << endl;
        }   
        else{
            cout << solveEven(s) << endl;
        }
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}