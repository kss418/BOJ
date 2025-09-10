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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], tmp[MAX];
class node{
public:
    char op; ll idx, v;
}; vector <node> result;

void r(ll idx, ll v){
    v %= n; if(!v) return;
    for(int i = 0;i < n;i++) tmp[(i + v) % n] = a[idx][i];
    for(int i = 0;i < n;i++) a[idx][i] = tmp[i];
    result.push_back({'R', idx + 1, v});
}

void d(ll idx, ll v){
    v %= n; if(!v) return;
    for(int i = 0;i < n;i++) tmp[(i + v) % n] = a[i][idx];
    for(int i = 0;i < n;i++) a[i][idx] = tmp[i];
    result.push_back({'D', idx + 1, v});
}

void solve(ll cy, ll cx){
    for(int i = cx + 1;i < n;i++){
        if(a[cy][i] != cy + 1) continue;
        d(cx, 1); d(i, 1);
        r(cy + 1, n - i + cx);
        d(cx, n - 1); d(i, n - 1);
        return;
    }

    for(int i = cy + 1;i < n;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j] != cy + 1) continue;
            if(cx == j) r(i, 1);
            d(cx, i - cy);
            if(cx == j) r(i, n - 1);
            else r(i, (cx - j + n) % n);
            d(cx, n - i + cy); 
            return;
        }
    }
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j] == i + 1) continue;
            solve(i, j);
        }
    }

    cout << result.size() << "\n";
    for(auto& [op, idx, v] : result){
        cout << op << " " << idx << " " << v << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}