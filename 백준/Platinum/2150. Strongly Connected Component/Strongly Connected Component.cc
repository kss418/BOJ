#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

class _scc { // 1-based index
public:
    ll n, dcnt = 0, scnt = 0;
    vector <ll> d, sn;
    vector<vector<ll>> adj, scc;
    vector <bool> fin;
    stack <ll> st;

    _scc(ll n) {
        this->n = n;
        d.resize(n + 1); fin.resize(n + 1);
        adj.resize(n + 1); sn.resize(n + 1);
    }

    void add(ll st, ll en) {
        adj[st].push_back(en);
    }


    ll dfs(ll cur) {
        d[cur] = ++dcnt;
        st.push(cur);

        ll mn = d[cur];
        for (auto& nxt : adj[cur]) {
            if (!d[nxt]) mn = min(mn, dfs(nxt));
            else if (!fin[nxt]) mn = min(mn, d[nxt]);
        }

        if (mn == d[cur]) {
            vector <ll> curscc;
            while (1) {
                ll t = st.top(); st.pop();
                curscc.push_back(t);
                fin[t] = 1; sn[t] = scnt;
                if (t == cur) break;
            }

            sort(curscc.begin(), curscc.end());
            scc.push_back(curscc); scnt++;
        }

        return mn;
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            if (d[i]) continue;
            dfs(i);
        }
    }

    vector <vector <ll>> ret() { // scc 반환
        sort(scc.begin(), scc.end());
        return scc;
    }

    ll num(ll a) { // scc 번호 반환
        return sn[a];
    }
};

int main() {
    fastio;
    cin >> n >> m;
    _scc scc(n);
    while (m--) {
        ll s, e;
        cin >> s >> e;
        scc.add(s, e);
    }
    
    scc.init();
    vector <vector<ll>> ret = scc.ret();

    cout << ret.size() << "\n";
    for (auto& i : ret) {
        for (auto& j : i) cout << j << " ";
        cout << -1 << "\n";
    }

    return 0;
}