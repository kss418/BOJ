#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 21;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX][MAX], able[MAX][MAX];

template <typename T = ll>
class _floyd { // ret(i,j) == INF 처리하기
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

int main() {
    fastio;
    cin >> n;
    _floyd floyd(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (i == j) continue;
            able[i][j] = 1;
            floyd.addsol(i, j, arr[i][j]);
        }
    }
    floyd.init();
    ll result = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (result >= INF) break;
                if (!able[i][j] || i == k || j == k) continue;
                if (arr[i][j] < floyd.ret(i, k) + floyd.ret(k, j)) continue;
                else if (arr[i][j] > floyd.ret(i, k) + floyd.ret(k, j)) {
                    result = INF;
                    break;
                }
                able[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!able[i][j]) continue;
            result += arr[i][j];
        }
    }

    if (result >= INF) cout << -1;
    else cout << result;

    return 0;
}