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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll sy[MAX][MAX], sx[MAX][MAX], result;
vector <ll> a[MAX][MAX];

void run(){
    cin >> n >> m; 
    for(int i = 0;i < n;i++) cin >> st[i];
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            sx[i][j] = (j ? sx[i][j - 1] : 0) + (st[i][j] == 'X');
            sy[i][j] = (i ? sy[i - 1][j] : 0) + (st[i][j] == 'X');
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = j;k < m;k++){
                if(sx[i][k] - (j ? sx[i][j - 1] : 0)) continue;
                a[j][k].push_back(i);
            }
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = i;j < m;j++){
            if(a[i][j].empty()) continue;
            ll mn = a[i][j][0];

            for(auto& now : a[i][j]){
                if(sy[now][i] - (mn ? sy[mn - 1][i] : 0)) mn = now;
                if(sy[now][j] - (mn ? sy[mn - 1][j] : 0)) mn = now;
                result = max(result, (now - mn + 1) * (j - i + 1));
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