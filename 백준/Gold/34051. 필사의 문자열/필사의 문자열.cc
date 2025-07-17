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
ll mn[33];
string result;

void run(){
    cin >> n >> s; memset(mn, 0x3f, sizeof(mn));
    result = s;
    for(int i = 0;i < n;i++){
        mn[s[i] - 'a' + 1] = min<ll>(mn[s[i] - 'a' + 1], i);
    }

    for(int i = 1;i < 26;i++) mn[i] = min(mn[i], mn[i - 1]);

    for(int i = 1;i < n;i++){
        ll idx = mn[s[i] - 'a'];
        if(idx > i) continue;
        reverse(s.begin() + idx, s.begin() + i + 1);
        result = max(result, s);
        reverse(s.begin() + idx, s.begin() + i + 1);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

