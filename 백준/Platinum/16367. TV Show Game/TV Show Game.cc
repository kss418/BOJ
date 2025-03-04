#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll num[3]; char c[3];

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

    ll ret() { // 2sat 여부 반환
        ll flag = 1;
        for (int i = 1; i <= n; i++) {
            if (num(i) != num(no(i))) continue;
            flag = 0; break;
        }

        return flag;
    }

    vector <ll> val() { // 참 일때 값 반환
        vector <ll> ret;
        ret.resize(2 * n + 1, -1);
        vector <ll> track = top();
        for (auto& i : track) {
            for (auto& cur : scc[i]) {
                if (ret[cur] != -1) continue;
                ret[cur] = 0; ret[no(cur)] = 1;
            }
        }

        return ret;
    }
};

int main() {
    fastio;

    cin >> n >> m; _2sat sat(n);
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < 3;j++) cin >> num[j] >> c[j];
        for(int j = 0;j < 3;j++) {
            ll cur = (c[j] == 'R' ? num[j] : sat.no(num[j]));
            ll nxt = (c[(j + 1) % 3] == 'R' ? num[(j + 1) % 3] : sat.no(num[(j + 1) % 3]));

            sat.add(cur, nxt);
        }
    }
    sat.init();

    vector <ll> ret = sat.val();
    if(sat.ret()) for(int i = 1;i <= n;i++){
        if(ret[i]) cout << 'R';
        else cout << 'B';
    }
    else cout << -1;


    return 0;
}

