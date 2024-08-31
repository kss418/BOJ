#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301;
constexpr ll MOD = 1e9 + 7;
ll able[MAX][MAX];
vector<pll> sccadj[MAX];

class _uf {
public:
    ll n; vector <ll> p, size;
    _uf(ll n) {
        this->n = n;
        p.resize(n + 1); size.resize(n + 1);
        fill(p.begin(), p.end(), -1);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a > b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};


class _scc { // 1-based index
public:
    ll n, dcnt = 0, scnt = 0;
    vector <ll> d, sn, ind; // dfsn, scc번호, ind
    vector<vector<ll>> adj, scc; // 간선, scc
    vector <bool> fin;
    stack <ll> st;
    vector <set <ll>> sccset; // 위상정렬 간선

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
        sort(scc.begin(), scc.end());
    }

    vector <vector <ll>> ret() { // scc 반환
        return scc;
    }

    ll num(ll a) { // scc 번호 반환
        return sn[a];
    }

    vector<ll> top() { //위상정렬
        deque <ll> q; vector<ll> ts;
        sccset.resize(n + 1); ind.resize(n + 1);

        for (auto& i : scc) {
            for (auto& cur : i) {
                for (auto nxt : adj[cur]) {
                    if (num(cur) == num(nxt)) continue;
                    if (sccset[num(cur)].count(num(nxt))) continue;
                    sccadj[num(cur)].push_back({ cur,nxt });
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
};

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        _scc scc(n); memset(able, 0, sizeof(able));
        for (int i = 1; i <= n; i++) sccadj[i].clear();

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '0') continue;
                if (i == j) continue;
                scc.add(i + 1, j + 1);
            }
        }

        scc.init();
        vector <vector<ll>> ret = scc.ret();
        vector <ll> ts = scc.top();
        vector <pll> result;

        for (int i = 0; i < scc.scnt;i++) {
            for (int j = 0; j < ret[i].size() - 1; j++) {
                result.push_back({ ret[i][j], ret[i][j + 1] });
            }
            if(ret[i].size() > 1) result.push_back({ret[i].back(), ret[i].front()});
        }

        for (auto& i : ts) {
            for (auto& j : sccadj[i]) {
                able[scc.num(j.first)][scc.num(j.second)] = 1;
            }
        }

        for (int k = 0; k < scc.scnt; k++) {
            for (int i = 0; i < scc.scnt; i++) {
                for (int j = 0; j < scc.scnt; j++) {
                    if (able[i][k] && able[k][j]) able[i][j] = 0;
                }
            }
        }

        for (auto& i : ts) {
            for (auto& j : sccadj[i]) {
                if (!able[scc.num(j.first)][scc.num(j.second)]) continue;
                able[scc.num(j.first)][scc.num(j.second)] = 0;
                result.push_back(j);
            }
        }


        cout << result.size() << "\n";
        for (auto& i : result) cout << i.first << " " << i.second << "\n";
        cout << "\n";
    }


    return 0;
}