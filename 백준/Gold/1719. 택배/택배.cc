#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
pll arr[MAX];

template <typename T = ll> // 반환 타입
class _floyd {
public:
    ll n; vector <vector<T>> d, nxt;

    _floyd(ll n) {
        this->n = n;
        d.resize(n + 1, vector<T>(n + 1, INF));
        nxt.resize(n + 1, vector<T>(n + 1, 0));
    }

    void add(ll st, ll en, T c = 1) { //양방향
        d[st][en] = c; d[en][st] = c;
        nxt[st][en] = en; nxt[en][st] = st;
    }

    void addsol(ll st, ll en, T c = 1) { //단방향
        d[st][en] = c;
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
};

int main()
{
    fastio;
    cin >> n >> m;
    _floyd floyd(n);

    while (m--) {
        ll st, en, c;
        cin >> st >> en >> c;
        floyd.add(st, en, c);
    }
    floyd.init();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "-" << " ";
            else cout << floyd.nxt[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}