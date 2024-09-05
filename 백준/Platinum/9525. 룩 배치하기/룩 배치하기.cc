#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
class _flow {
public:
    ll n;
    vector <ll> d, w;
    deque <ll> q;

    class edge {
    public:
        ll nxt, c, f;
        edge* rev;

        edge(ll nxt, ll c) {
            this->nxt = nxt; this->c = c;
            this->rev = nullptr; this->f = 0;
        }

        void flow(ll num) { f += num; rev->f -= num; }
        ll cap() { return c - f; }
    };
    vector <vector<edge*>> adj;

    _flow(ll n) {
        this->n = n;
        d.resize(n + 1); w.resize(n + 1);
        adj.resize(n + 1);
    }

    void addsol(ll st, ll en, ll c = 1) {
        adj[st].push_back(new edge(en, c));
        adj[en].push_back(new edge(st, 0));
        adj[st].back()->rev = adj[en].back();
        adj[en].back()->rev = adj[st].back();
    }


    bool bfs(ll st, ll en) { // sink 도달 여부 반환
        fill(d.begin(), d.end(), -1);
        d[st] = 0;

        q.push_back(st);
        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            for (auto& edge : adj[cur]) {
                ll nxt = edge->nxt;
                if (d[nxt] != -1) continue;
                if (edge->cap() <= 0) continue;

                d[nxt] = d[cur] + 1; q.push_back(nxt);
            }
        }

        return d[en] != -1;
    }

    ll dfs(ll cur, ll en, ll val) { // sink 도달 최대 유량 반환
        if (cur == en) return val;

        while (w[cur] < adj[cur].size()) {
            ll i = w[cur]; w[cur]++;
            edge* edge = adj[cur][i];
            ll nxt = edge->nxt;

            if (d[nxt] != d[cur] + 1) continue;
            if (edge->cap() <= 0) continue;

            ll mn = dfs(nxt, en, min(edge->cap(), val));
            if (mn <= 0) continue;
            edge->flow(mn);

            return mn;
        }

        return 0;
    }

    ll ret(ll st, ll en) {
        ll r = 0;
        while (bfs(st, en)) {
            fill(w.begin(), w.end(), 0);
            while (1) {
                ll f = dfs(st, en, INF);
                if (!f) break;
                r += f;
            }
        }

        return r;
    }
};
map <pll, ll> num[2];
string st[MAX];


int main() {
    fastio;

    cin >> n;
    _flow flow(20101);
    for (int i = 0; i < n; i++) cin >> st[i];

    ll cnt = 1, la = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (st[i][j] == 'X') { cnt++; continue; }
            num[0][{i, j}] = cnt;
            la = max(la, cnt);
        }
        cnt++;
    }
    for (int i = 1; i <= la; i++) flow.addsol(0, i);

    la = 0; cnt = 10001;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (st[j][i] == 'X') { cnt++; continue; }
            num[1][{j, i}] = cnt;
            la = max(la, cnt);
        }
        cnt++;
    }
    for (int i = 10001; i <= la; i++) flow.addsol(i, 10000);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) flow.addsol(num[0][{i, j}], num[1][{i, j}]);
    }

    cout << flow.ret(0, 10000);



    return 0;
}