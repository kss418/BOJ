#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
vector <ll> num[MAX];
ll cnt[3 * MAX], c[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            num[i].clear();
            cin >> k;

            for(int j = 1;j <= k;j++){
                ll cur; cin >> cur;
                num[i].push_back(cur);
            }
            cin >> c[i];
        }

        for(int i = 1;i <= m;i++) cin >> cnt[i];

        ll result = 0;
        for(int i = 1;i <= n;i++){
            ll mn = INF;
            for(auto& j : num[i]) mn = min(mn, cnt[j]);
            
            result += mn * c[i]; 
        }

        cout << result << '\n';
    }

    return 0;
}