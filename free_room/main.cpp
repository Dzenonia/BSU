#include <bits/stdc++.h>
typedef long long ll;

const ll mod = 1e9 + 7;

std::vector<ll> variable(150);
std::vector<ll> step(10);
int last = 0;
bool hasVariable = 0;

void prec(const std::string& input) {
    int pos = 0;
    for (; input[pos] != '='; ++pos) {
        if (input[pos] >= 'a' && input[pos] <= 'z') {
            ++variable[input[pos]];
            last = std::max(last, (int)input[pos]);
            hasVariable = 1;
            continue;
        }
        if (input[pos] == '*') {
            continue;
        }
        int value = input[pos] - '0';
        for (int i = 2; i <= 7; ++i) {
            if (i != 2 && i != 3 && i != 5 && i != 7) {
                continue;
            }
            while (value % i == 0) {
                --step[i];
                value /= i;
            }
        }
    }
    ++pos;
    for (; pos < input.size(); ++pos) {
        if (input[pos] == '*') {
            continue;
        }
        int value = input[pos] - '0';
        for (int i = 2; i <= 7; ++i) {
            if (i != 2 && i != 3 && i != 5 && i != 7) {
                continue;
            }
            while (value % i == 0) {
                ++step[i];
                value /= i;
            }
        }
    }
}

void check() {
    for (int i = 'a'; i <= 'z'; ++i) {
        std::cout << variable[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 2; i <= 7; ++i) {
        std::cout << step[i] << ' ';
    }
    std::cout << '\n';
}

ll getAns(ll sz) {
    std::vector<std::vector<ll>> dp(sz + 1, std::vector<ll>(150, 0));
    dp[0]['a' - 1] = 1;
    for (int i = 'a'; i <= 'z'; ++i) {
        dp[0][i] = 1;
    }
    //    for (int i = 1; i <= sz; ++i) {
    //        for (int j = 'a'; j <= 'z'; ++j) {
    //            if (variable[j] == 0) {
    //                continue;
    //            }
    //            if (i - variable[j] >= 0) {
    //                dp[i][j] += dp[i - variable[j]][j];
    //                dp[i][j] %= mod;
    //            }
    //        }
    //    }
    for (int i = 'a'; i <= 'z'; ++i) {
        for (ll j = 1; j <= sz; ++j) {
            ll k = 0;
            if (variable[i] == 0) {
                dp[j][i] = dp[j][i - 1];
                continue;
            }
            while ((j - variable[i] * k) >= 0) {
                dp[j][i] = (dp[j][i] + dp[j - variable[i] * k][i - 1]) % mod;
                ++k;
            }
        }
    }
//    std::cout << dp[step[2]]['z'] << " " << step[2] << " " << variable['a'] << std::endl;
    return (((dp[step[2]]['z'] * dp[step[3]]['z']) % mod * dp[step[5]]['z']) % mod)
        * dp[step[7]]['z'];
    //    for (int i = 'a'; i <= 'z'; ++i) {
    //        iterDp[0] = 1;
    //        for (int j = 1; j <= step[prost]; ++j) {
    //
    //        }
    //    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string s;
    std::cin >> s;
    prec(s);
    if (!hasVariable) {
        for (int i = 2; i <= 7; ++i) {
            if (step[i] != 0) {
                std::cout << 0 << '\n';
                return 0;
            }
        }
        std::cout << -1 << '\n';
        return 0;
    }
    std::cout << getAns(std::max(std::max(step[2], step[3]), std::max(step[5], step[7]))) % mod
              << '\n';
    return 0;
}
