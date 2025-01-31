#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <iomanip>
#include <limits>
#include <numeric>

//#include "atcoder/segtree.hpp"
//#include <atcoder/modint.hpp>

#define LMAX 9223372036854775807
#define IMAX 2147483647
#define INF 2e9
#define MOD 1000000007
#define endl '\n'
#define END "0"
#define ll long long
#define ull unsigned long long
#define ld long double
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void kill() { cout << END; exit(0); }
//using mint = atcoder::modint998244353;

char arr[1001][1001];
char temp[1001][1001];
int n,m;
int cnt=0;
int x, y;

void rotate() {
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            temp[i][j]=arr[n-j+1][i];
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            arr[i][j]=temp[i][j];
        }
    }
    swap(n,m);
}

void pri() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout<<arr[i][j];
        } cout<<endl;
    }
}

void sol() {
    if(cnt<0) cnt+=4;
    if(cnt%4==0) {
        if(x+1<=n && arr[x+1][y]=='.') {
            arr[x][y] = '.'; arr[++x][y] = 'J';
        }
    } else if(cnt%4==1) {
        if(y+1<=m && arr[x][y+1]=='.') {
            arr[x][y] = '.'; arr[x][++y] = 'J';
        }
    } else if(cnt%4==2) {
        if(x-1>=1 && arr[x-1][y]=='.') {
            arr[x][y] = '.'; arr[--x][y] = 'J';
        }
    } else {
        if(y-1>=1 && arr[x][y-1]=='.'){
            arr[x][y] = '.'; arr[x][--y] = 'J';
        }
    }
}

int main() {
    FASTIO
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='J') x=i,y=j;
        }
    }
    string str; cin>>str;
    for(auto f:str) {
        if(f=='R') cnt++;
        else if(f=='L') cnt--;
        sol();
    }
    
    for(int d=1;d<=cnt%4;d++) rotate();
    pri();


    return 0;
}