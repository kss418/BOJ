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
vector <ll> vx, vy;
ll result;

void run(){
    cin >> n >> m;
    while(m--){
        ll cx, cy; cin >> cx >> cy;
        vx.push_back(cx);
        vy.push_back(cy);
    }
    sort(all(vx)); sort(all(vy));

    for(auto& i : vx){
        result += abs(vx[(vx.size() - 1) / 2] - i);
    }

    for(auto& i : vy){
        result += abs(vy[(vy.size() - 1) / 2] - i);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

