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
    int n, t, sm = 0, d = 0, t1, t2, t3;
    string s1, s2;
    cin >> n >> t;
    cin >> s1 >> s2;
    bool flag[100002] = {0};
    rp(i, n) {
        if(s1[i] != s2[i]){
            flag[i] = true;
            d++;
        }
    }
    sm = n - d;
    if(((d&1) && t < d / 2 + 1) || (!(d&1) && t < d / 2)) {
        cout << "-1" << endl;
        return 0;
    }
    if(t >= d) {
        t3 = d;
        t1 = t2 = 0;
        t = t - d;
    }
    else{
        t1 = t2 = (2 * d - 2 * t) / 2;
        t3 = d - 2 * t1;
        t = 0;
    }
    rp(i, n) {
        if(flag[i]) {
            if(t3){
                int a = s1[i], b = s2[i];
                a -= 'a';
                b -= 'a';
                if(a > b)   swap(a, b);
                int ch = (b + 1) % 26;
                if(ch == a) ch = ch + 1;
                cout << char(ch + 'a');
                t3--;
            }
            else if(t1 >= t2)  {
                t1--;
                cout << s1[i];
            }
            else if(t1 < t2){
                cout << s2[i];
                t2--;
            }
        }
        else{
            if(t) {
                int a = s1[i];
                cout << char((a + 1) % 26 + 'a');
                t--;
            }
            else{
                cout << s1[i];
            }
        }
    }
    cout << endl;
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}