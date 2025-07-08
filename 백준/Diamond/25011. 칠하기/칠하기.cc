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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <string> st;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool vx[MAX][MAX], vy[MAX][MAX];
ll num[MAX][MAX][2];

class _scc { // 1-based index
public:
    ll n, dcnt = 0, scnt = 0;
    vector <ll> d, sn, ind; // dfsn, scc번호, ind
    vector<vector<ll>> adj, scc; // 간선, scc
    vector <bool> fin;
    stack <ll> st;
    vector <set <ll>> sccset; // 위상정렬 간선

    _scc(){}
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
        return scc;
    }

    ll num(ll a) { // scc 번호 반환
        return sn[a];
    }

    vector <ll> top() { //위상정렬
        deque <ll> q; vector <ll> ts;
        sccset.resize(n + 1); ind.resize(n + 1);

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
};

_scc scc;
bool outrange(ll cy, ll cx, ll N, ll M, std::vector<std::string>& V){
    if(cy < 0 || cx < 0 || cy >= N || cx >= M) return 1;
    return V[cy][cx] == '#';
}

int yellowblue(int N, int M, std::vector<std::string> V){
    ll cnt = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(V[i][j] == '#') continue;
            
            if(!vy[i][j]){
                ll ny1 = i, ny2 = i; ++cnt;
                while(!outrange(ny1 - 1, j, N, M, V)) ny1--;
                while(!outrange(ny2 + 1, j, N, M, V)) ny2++;

                for(int k = ny1;k <= ny2;k++){
                    vy[k][j] = 1;
                    num[k][j][0] = cnt;
                }
            }

            if(!vx[i][j]){
                ll nx1 = j, nx2 = j; ++cnt;
                while(!outrange(i, nx1 - 1, N, M, V)) nx1--;
                while(!outrange(i, nx2 + 1, N, M, V)) nx2++;

                for(int k = nx1;k <= nx2;k++){
                    vx[i][k] = 1;
                    num[i][k][1] = cnt;
                }
            }
        }
    }

    scc = {cnt};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(V[i][j] == '#') continue;
            if(outrange(i - 1, j, N, M, V) || outrange(i + 1, j, N, M, V)){
                scc.add(num[i][j][0], num[i][j][1]);
            }

            if(outrange(i, j - 1, N, M, V) || outrange(i, j + 1, N, M, V)){
                scc.add(num[i][j][1], num[i][j][0]);
            }
        }
    }

    scc.init();
    vector <ll> top = scc.top();
    for(int i = 1;i < top.size();i++){
        if(!scc.sccset[top[i - 1]].count(top[i])) return 0;
    }

	return 1;
}


