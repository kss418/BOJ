#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
set <pair<pll, pll>> v;

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    if(st[cy][cx] != 'C') return 1;
    return 0;
}

void run(){
    cin >> n >> m; ll result = 0;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 1;j < m - 1;j++){
            if(st[i][j] != 'G') continue;
            if(st[i][j - 1] != 'C' || st[i][j + 1] != 'C') continue;
            result++; st[i][j] = '.';
        }   
    }

    for(int i = 1;i < n - 1;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'G') continue;
            if(st[i - 1][j] != 'C' || st[i + 1][j] != 'C') continue;
            result++; st[i][j] = '.';
        }   
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'G') continue;
            if(!outrange(i - 1, j) && !outrange(i, j - 1)){
                if(!v.count({{i - 1, j}, {i, j - 1}})){
                    v.insert({{i - 1, j}, {i, j - 1}});
                    st[i][j] = '.'; result++; continue;
                }
            }

            if(!outrange(i - 1, j) && !outrange(i, j + 1)){
                if(!v.count({{i - 1, j}, {i, j + 1}})){
                    v.insert({{i - 1, j}, {i, j + 1}});
                    st[i][j] = '.'; result++; continue;
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'G') continue;
            if(!outrange(i + 1, j) && !outrange(i, j - 1)){
                if(!v.count({{i, j - 1}, {i + 1, j}})){
                    v.insert({{i, j - 1}, {i + 1, j}});
                    st[i][j] = '.'; result++; continue;
                }
            }

            if(!outrange(i + 1, j) && !outrange(i, j + 1)){
                if(!v.count({{i, j + 1}, {i + 1, j}})){
                    v.insert({{i, j + 1}, {i + 1, j}});
                    st[i][j] = '.'; result++; continue;
                }
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}