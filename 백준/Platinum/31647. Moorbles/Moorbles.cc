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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll suf[MAX], mn[MAX][2], mx[MAX][2];

void init(){
    for(int i = 1;i <= m + 1;i++){
        mx[i][0] = mx[i][1] = suf[i] = 0;
        mn[i][0] = mn[i][1] = INF;
    }
}

void run(){
    cin >> n >> m >> k; init();
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < k;j++){
            ll now; cin >> now;
            mx[i][now & 1] = max(mx[i][now & 1], now);
            mn[i][now & 1] = min(mn[i][now & 1], now);
        }

        if(!mx[i][0]) mx[i][0] = -mn[i][1];
        if(!mx[i][1]) mx[i][1] = -mn[i][0];
    }

    for(int i = m;i >= 1;i--){
        suf[i] = min(suf[i + 1] + max(-mx[i][0], -mx[i][1]), 0ll);
    }

    ll now = n;
    vector <bool> result;
    for(int i = 1;i <= m;i++){
        if(now - mx[i][1] + suf[i + 1] > 0){
            result.push_back(0);
            now -= mx[i][1];
        }
        else if(now - mx[i][0] + suf[i + 1] > 0 ){
            result.push_back(1);
            now -= mx[i][0];
        }
        else{
            cout << -1 << "\n";
            return;
        }
    }
    
    for(auto i : result){
        cout << (i ? "Odd" : "Even") << " ";
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}