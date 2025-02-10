#include <bits/stdc++.h>
#define int long long
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for(int i=1, j=0; i<S; i++) {
        int bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(int k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx dir(cos(angle), sin(angle));

        for(int i=0; i<S; i+=k*2) {
            cpx unit(1, 0);

            for(int j=0; j<k; j++) {
                cpx a = v[i+j];
                cpx b = v[i+j+k] * unit;

                v[i+j] = a + b;
                v[i+j+k] = a - b;

                unit *= dir;
            }
        }
    }

    if(inv)
        for(int i=0; i<S; i++) v[i] /= S;
}

vector<cpx> mul(vector<cpx> &v, vector<cpx> &u) {
    int S = 2;
    while(S < v.size() + u.size()) S *= 2;

    v.resize(S); FFT(v, false);
    u.resize(S); FFT(u, false);

    vector<cpx> w(S);
    for(int i=0; i<S; i++) w[i] = v[i] * u[i];
    FFT(w, true);

    return w;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string a, b; cin >> a >> b;

    vector<cpx> v, u;
    for(int i=0; i<a.length(); i++) v.push_back(cpx(a[i] - '0', 0));
    for(int i=0; i<b.length(); i++) u.push_back(cpx(b[i] - '0', 0));

    reverse(v.begin(), v.end());
    reverse(u.begin(), u.end());

    vector<cpx> w = mul(v, u);

    vector<int> ans(w.size());
    for(int i=0; i<ans.size(); i++) ans[i] = round(w[i].real());

    for(int i=0; i<ans.size(); i++) {
        if(ans[i] < 10) continue;

        if(i < ans.size()-1) ans[i+1] += ans[i]/10;
        else ans.push_back(ans[i]/10);

        ans[i] %= 10;
    }

    reverse(ans.begin(), ans.end());

    int i=0; while(ans[i] == 0) i++;
    if(i >= ans.size()) cout << 0 << "\n";

    while(i < ans.size()) {
        cout << ans[i];
        i++;
    }
    cout << "\n";
}