#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 2501;
constexpr ll MOD = 1e9 + 7;

class _2sat { // 1-based index
public:
    ll n, dcnt = 0, scnt = 0;
    vector <ll> d, sn, ind; // dfsn, scc번호, ind
    vector<vector<ll>> adj, scc; // 간선, scc
    vector <bool> fin;
    stack <ll> st;
    vector <set <ll>> sccset; // 위상정렬 간선

    _2sat(ll n) {
        this->n = n;
        d.resize(2 * n + 1); fin.resize(2 * n + 1);
        adj.resize(2 * n + 1); sn.resize(2 * n + 1);
    }

    ll no(ll cur){
        if (cur > n) return cur - n;
        return cur + n;
    }

    void add(ll st, ll en) {
        adj[no(st)].push_back(en);
        adj[no(en)].push_back(st);
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
        for (int i = 1; i <= 2 * n; i++) {
            if (d[i]) continue;
            dfs(i);
        }
    }

    vector <vector <ll>> sccret() { // scc 반환
        return scc;
    }

    ll num(ll a) { // scc 번호 반환
        return sn[a];
    }

    vector <ll> top() { //위상정렬
        deque <ll> q; vector <ll> ts;
        sccset.resize(2 * n + 1); ind.resize(2 * n + 1);

        for (auto& i : scc) {
            for (auto& cur : i) {
                for (auto nxt : adj[cur]) {
                    if (num(cur) == num(nxt)) continue;
                    if (sccset[num(cur)].count(num(nxt))) continue;
                    sccset[num(cur)].insert(num(nxt));
                    ind[num(nxt)]++;
                }
            }
        }

        for (int i = 0; i < scnt; i++) {
            if (ind[i]) continue;
            q.push_back(i);
        }

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            ts.push_back(cur);

            for (auto& nxt : sccset[cur]) {

                if (!--ind[nxt]) q.push_back(nxt);
            }
        }

        return ts;
    }

    ll ret() {
        ll flag = 1;
        for (int i = 1; i <= n; i++) {
            if (num(i) != num(no(i))) continue;
            flag = 0; break;
        }

        return flag;
    }
};

int main() {
    fastio;

    cin >> n >> m;
    _2sat sat(n);

    while (m--) {
        ll s, e;
        cin >> s >> e;
        if (s < 0) s = -s + n;
        if (e < 0) e = -e + n;

        sat.add(s, e);
    }
    sat.init();

    cout << sat.ret();

    return 0;
}