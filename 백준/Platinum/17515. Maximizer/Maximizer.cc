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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result = INF;

void even(){    
    vector <ll> u[2], d[2];
    for(int i = 1;i <= n;i++){
        (b[i] <= n / 2 ? d[0] : u[0]).push_back(i);
        (a[i] <= n / 2 ? d[1] : u[1]).push_back(i);
    }

    for(int j = 0;j < 2;j++){
        sort(all(u[j]));
        sort(all(d[j]));
    }

    for(int j = 0;j < 2;j++){
        ll now = 0;
        for(int k = 0;k < u[j].size();k++){
            now += abs(u[j][k] - d[j ^ 1][k]);
        }

        result = min(result, now);
    }
}

void odd(){
    vector <ll> u[2], d[2];
    for(int i = 1;i <= n;i++){
        (b[i] <= n / 2 + 1 ? d[0] : u[0]).push_back(i);
        (a[i] <= n / 2 ? d[1] : u[1]).push_back(i);
    }

    for(int j = 0;j < 2;j++){
        sort(all(u[j]));
        sort(all(d[j]));
    }

    for(int j = 0;j < 2;j++){
        ll now = 0;
        for(int k = 0;k < u[j].size();k++){
            now += abs(u[j][k] - d[j ^ 1][k]);
        }

        result = min(result, now);
    }

    for(int j = 0;j < 2;j++){
        u[j].clear();
        d[j].clear();
    }

    for(int i = 1;i <= n;i++){
        (b[i] <= n / 2 ? d[0] : u[0]).push_back(i);
        (a[i] <= n / 2 + 1 ? d[1] : u[1]).push_back(i);
    }

    for(int j = 0;j < 2;j++){
        sort(all(u[j]));
        sort(all(d[j]));
    }

    for(int j = 0;j < 2;j++){
        ll now = 0;
        for(int k = 0;k < u[j].size();k++){
            now += abs(u[j][k] - d[j ^ 1][k]);
        }

        result = min(result, now);
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    (n % 2 ? odd() : even());
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}