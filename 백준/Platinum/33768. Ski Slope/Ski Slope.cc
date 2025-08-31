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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], d[MAX], e[MAX], sum[MAX];
deque <ll> mx[MAX];
vector <tll> q;
vector <pll> num[11];

void run(){
    cin >> n; for(int i = 0;i <= 10;i++) mx[1].push_back(MINF);
    for(int i = 2;i <= n;i++){
        cin >> p[i] >> d[i] >> e[i];
        sum[i] = sum[p[i]] + e[i];
    }

    for(int i = 2;i <= n;i++){
        for(auto& j : mx[p[i]]) mx[i].push_back(j);
        mx[i].push_back(d[i]);
        sort(all(mx[i])); reverse(all(mx[i]));

        if(mx[i].size() > 11) mx[i].pop_back();
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 10;j++){
            if(j < mx[i].size()){
                num[j].push_back({mx[i][j], sum[i]});
            }
            else num[j].push_back({MINF, sum[i]});
        }
    }

    for(int i = 0;i <= 10;i++){
        ll mx = MINF; sort(all(num[i]));
        for(int j = 0;j < num[i].size();j++){
            mx = max(mx, num[i][j].y);
            num[i][j].y = mx;
        }
    }

    cin >> m;
    for(int i = 1;i <= m;i++){
        ll v, c; cin >> v >> c;
        ll ub = upper_bound(all(num[c]), pll(v, INF)) - num[c].begin();
        cout << (ub ? num[c][ub - 1].y : 0) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}