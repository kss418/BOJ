#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 1005;
bool v1[MAX][MAX];
map <pair<pll, pll>, bool> v2;
ll cy = MID, cx = MID;
ll p, l; 


void run(){
    cin >> n >> s;

    v1[MID][MID] = 1;
    for(auto& i : s){
        ll py = cy, px = cx;
        if(i == 'N') cy++;
        else if(i == 'S') cy--;
        else if(i == 'E') cx++;
        else cx--;
        
        p += v1[cy][cx] ? 0 : 1;
        l += v2.count({{py, px}, {cy, cx}}) ? 0 : 1;

        v1[cy][cx] = 1;
        v2[{{py, px}, {cy, cx}}] = 1;
        v2[{{cy, cx}, {py, px}}] = 1;
    }

    cout << l - p;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

