#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll> // 반환 타입
class _floyd { // 컴포넌트 분리 생각하기
public:
    ll n; vector <vector<T>> d, nxt;
    vector <ll> tr;

    _floyd(ll n) {
        this->n = n;
        d.resize(n + 1, vector<T>(n + 1, INF));
        nxt.resize(n + 1, vector<T>(n + 1, 0));
    }

    void add(ll st, ll en, T c = 1) { //양방향
        d[st][en] = min(d[st][en], c); 
        d[en][st] = min(d[en][st], c);
        nxt[st][en] = en; nxt[en][st] = st;
    }

    void addsol(ll st, ll en, T c = 1) { //단방향
        d[st][en] = min(d[st][en], c);
        nxt[st][en] = en;
    }

    void init() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (d[i][j] <= d[i][k] + d[k][j]) continue;
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    T ret(ll st, ll en) {
        return d[st][en];
    }

    vector <ll> track(ll st, ll en) {
        ll cur = st; tr.clear();

        while (cur != en) {
            tr.push_back(cur);
            cur = nxt[cur][en];
        }
        tr.push_back(en);

        return tr;
    }
};

int main()
{
    fastio;
    cin >> n >> m;
    _floyd floyd(n);

    while (m--) {
        ll s, e, c;
        cin >> s >> e >> c;
        floyd.addsol(s, e, c);
    }
    floyd.init();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || floyd.ret(i, j) == INF) cout << 0 << " ";
            else cout << floyd.ret(i, j) << " ";
        }
        cout << "\n";
    }

    vector <ll> cur;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {  
            if (i == j || floyd.ret(i, j) == INF) { cout << 0 << "\n"; continue; }
            cur.clear();

            cur = floyd.track(i, j);
            cout << cur.size() << " ";
            for (auto& k : cur) cout << k << " ";
            cout << "\n";
        }
    }


    return 0;
}