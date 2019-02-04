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
int ar[50002];
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        int n,ch;
        cin>>n;
        int rem = n%4;
        int que = n/4;
        if(rem){
            que--;
            rem += 4;
        }
        int off=0;
        while(que){
            int xar[5];
            fre(i,1,4){
                int r1 = ((i+1)%4==0?4:(i+1)%4);
                int r2 = ((i+2)%4==0?4:(i+2)%4);
                cout<<1<<" "<<off+i<<" "<<off+r1<<" "<<off+r2<<endl;
                fflush(stdout);
                cin>>ch;
                if(ch==-1)  return 0;
                xar[i]=ch;
            }
            ar[off+3] = xar[1]^xar[2]^xar[3];
            ar[off+4] = xar[2]^xar[3]^xar[4];
            ar[off+1] = xar[3]^xar[4]^xar[1];
            ar[off+2] = xar[4]^xar[1]^xar[2];
            off+=4;
            que--;
        }
        if(rem){
            if(rem==5){
                int xar[6];
                fre(i,1,5){
                    int r1 = ((i+1)%5==0?5:(i+1)%5);
                    int r2 = ((i+2)%5==0?5:(i+2)%5);
                    cout<<1<<" "<<off+i<<" "<<off+r1<<" "<<off+r2<<endl;
                    fflush(stdout);
                    cin>>ch;
                    if(ch==-1)  return 0;
                    xar[i]=ch;
                }
                ar[off+5] = xar[1]^xar[2]^xar[4];
                ar[off+1] = xar[2]^xar[3]^xar[5];
                ar[off+2] = xar[3]^xar[4]^xar[1];
                ar[off+3] = xar[4]^xar[5]^xar[2];
                ar[off+4] = xar[5]^xar[1]^xar[3];
                off+=5;
            }
            else if(rem==6){
                int xar[7];
                fre(i,1,6){
                    int r1 = ((i+1)%6==0?6:(i+1)%6);
                    int r2 = ((i+3)%6==0?6:(i+3)%6);
                    cout<<1<<" "<<off+i<<" "<<off+r1<<" "<<off+r2<<endl;
                    fflush(stdout);
                    cin>>ch;
                    if(ch==-1)  return 0;
                    xar[i]=ch;
                }56+2
                ar[off+3] = xar[1]^xar[2]^xar[4];
                ar[off+4] = xar[2]^xar[3]^xar[5];
                ar[off+5] = xar[3]^xar[4]^xar[6];
                ar[off+6] = xar[4]^xar[5]^xar[1];
                ar[off+1] = xar[5]^xar[6]^xar[2];
                ar[off+2] = xar[6]^xar[1]^xar[3];
                off+=6;
            }
            else if(rem==7){
                int xar[8];
                fre(i,1,7){
                    int r1 = ((i+1)%7==0?7:(i+1)%7);
                    int r2 = ((i+2)%7==0?7:(i+2)%7);
                    cout<<1<<" "<<off+i<<" "<<off+r1<<" "<<off+r2<<endl;
                    fflush(stdout);
                    cin>>ch;
                    if(ch==-1)  return 0;
                    xar[i]=ch;
                }
                ar[off+3] = xar[2]^xar[1]^xar[3]^xar[5]^xar[6];
                ar[off+4] = xar[3]^xar[2]^xar[4]^xar[6]^xar[7];
                ar[off+2] = xar[2]^ar[off+3]^ar[off+4];
                ar[off+5] = xar[3]^ar[off+3]^ar[off+4];
                ar[off+1] = xar[1]^ar[off+2]^ar[off+3];
                ar[off+7] = xar[7]^ar[off+2]^ar[off+1];
                ar[off+6] = xar[6]^ar[off+7]^ar[off+1];
                off+=7;
            }
        }
        cout<<2<<" ";
        fre(i,1,n){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
        fflush(stdout);
        cin>>ch;
        if(ch==-1)  return 0;
        else if(ch==1)  continue;
    }
    return 0;
}