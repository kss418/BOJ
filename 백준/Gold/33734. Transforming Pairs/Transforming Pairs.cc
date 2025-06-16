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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a, b;

void run(){
    cin >> n >> m >> a >> b; ll result =0;
    if(n == a && m == b){
        cout << 0 << "\n"; return;
    }

    while(n != a || m != b){
        if(a < n || b < m){
            cout << -1 << "\n"; return;
        }

        if(a > b){
            ll now = max((a - n) / b, 1ll);
            a -= now * b; result += now;
        }
        else if(b > a){
            ll now = max((b - m) / a, 1ll);
            b -= now * a; result += now;
        }
        else{
            cout << -1 << "\n"; return;
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

