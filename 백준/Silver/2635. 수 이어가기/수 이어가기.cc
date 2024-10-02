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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> n;
    vector <ll> result;
    ll si = 0;

    for(int i = 1;i <= n;i++){
        vector <ll> cur;
        cur.push_back(n); cur.push_back(i);
        while(1){
            ll nxt = cur[cur.size() - 2] - cur[cur.size() - 1];
            if(nxt < 0) break;
            cur.push_back(nxt);
        }

        if(cur.size() <= si) continue;
        si = cur.size(); result = cur;
    }

    cout << si << "\n";
    for(auto& i : result) cout << i << " ";


    return 0;
}