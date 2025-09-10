#include <bits/stdc++.h>
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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll n1, n2, m1, m2, result = INF;
string st[MAX][2], tmp[MAX];
ll mny, mxy, mnx, mxx;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n1 || cx >= m1;
}

void prop(ll cy, ll cx){
    mny = min(mny, cy); mxy = max(mxy, cy);
    mnx = min(mnx, cx); mxx = max(mxx, cx);
}

void chk(ll cy, ll cx){
    mny = INF, mxy = MINF, mnx = INF, mxx = MINF;
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < m1;j++){
            if(st[i][0][j] == '0') continue;
            prop(i, j);
        }
    }

    for(int i = 0;i < n2;i++){
        for(int j = 0;j < m2;j++){
            if(st[i][1][j] == '0') continue;
            prop(i + cy, j + cx); 

            if(outrange(i + cy, j + cx)) continue;
            if(st[i + cy][0][j + cx] == '1') return;
        }
    }

    result = min(result, (mxy - mny + 1) * (mxx - mnx + 1));
}

void tf(){
    for(int i = 0;i < m2;i++) tmp[i].resize(n2);
    for(int i = n2 - 1;i >= 0;i--){
        for(int j = 0;j < m2;j++){
            tmp[j][n2 - i - 1] = st[i][1][j];
        }
    }

    for(int i = 0;i < m2;i++) st[i][1] = tmp[i];
    swap(n2, m2);
}

void run(){
    cin >> n1 >> m1;
    for(int i = 0;i < n1;i++) cin >> st[i][0];

    cin >> n2 >> m2;
    for(int i = 0;i < n2;i++) cin >> st[i][1];

    for(int k = 0;k < 4;k++){
        for(int i = -n2;i <= n1;i++){
            for(int j = -m2;j <= m1;j++) chk(i, j);
        }

        tf();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}