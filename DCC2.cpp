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
bool dp[52][52][52];
int solveit(string a, string b) {    
    int l1 = a.length();
    if(l1 != b.length())    return false;
    if(a.compare(b) == 0)  return true;
    rp(i, l1){  
        rp(j, l1){  
           dp[i][j][0] = (a[i] == b[j]);  
        }  
    }   
    fr(k, 1, l1) {
        rp(i, l1 - k){ 
            rp(j, l1 - k){  
                dp[i][j][k] = false;  
                rp(p, k){ 
                    if ((dp[i][j][p] && dp[i+p+1][j+p+1][k-p-1]) || (dp[i][j+k-p][p] && dp[i+p+1][j][k-p-1])) {  
                        dp[i][j][k] = true;  
                        break;  
                    }  
                }  
            }  
        }  
    }  
    return dp[0][0][l1-1];  
}  

int main(){
    FAST
    //Do awesome things here
    string s1, s2;
    cin >> s1 >> s2;
    if(solveit(s1, s2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}