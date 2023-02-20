#include <bits/stdc++.h>
/*
 * Ответ это n - (N(alpha_i)) + .... - (N(alpha_i1, ...., alpha_i15)) ( так как если взять больше чем 15 множителей, то
 * их произведение будет больше чем 1e18, что видет к нулевому слагаемому)
 * где N(alpha_i1, alpha_i2, ...., alpha_ik) = (n - 1) / (alpha_i1 * alpha_i2 * .... * alpha_ik) округленное вниз
 * alpha_i это упорядоченные простые числа <= 500)
 * dp[k][max][l] -- множества размера k, в которых максимальный элемент равен max и
 * максимальное произведение чисел множеств не превосходит l (пытаемся также хранить сумму
 * всех (n - 1) / (multiply множества) (15 * 95 * 96 ~ 150000)
 * dp[k][max][l] = sgma    dp[k - 1][p][l1] / max
 *                 p < max
 * (для каждого p < max мы выбераем максимальное l1, такое что l1 * max <= l)
 * l = n, (n / 2), (n / 3), .... (n / 499)
 * Ответ = n - dp[1][по всем max][n] + ... (-1)^k dp[k][по всем max][n] + .....
 */
using ll = long long;

std::vector<ll> prostNumbers;

const int MAX_PROST_NUMBERS = 501;
const int CNT_PROST_NUMERS = 95;
const ll BIG_NUMBER = 1e18;

void precalc();

void letCheck();

int howMuch(ll prost);

void precalc() {
    for (int i = 2; i < MAX_PROST_NUMBERS; ++i) {
        bool ok = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            prostNumbers.push_back(i);
        }
    }
}

int howMuch(ll prost) {
    int res = 1;
    ll mul = prost;
    for (ll num: prostNumbers) {
        if (num >= prost) {
            break;
        }
        if (BIG_NUMBER / mul >= num) {
            ++res;
            mul *= num;
        } else {
            break;
        }
    }
    assert(mul <= BIG_NUMBER);
    return res;
}

void letCheck() {
    std::vector<std::pair<ll, std::vector<bool>>> numbersLast;
    std::vector<std::pair<ll, std::vector<bool>>> numbersNew;
    for (ll prost: prostNumbers) {
        numbersLast.push_back({prost, std::vector<bool>(MAX_PROST_NUMBERS, 0)});
        numbersLast.back().second[prost] = 1;
    }
    for (int tt = 2; tt < 7; ++tt) {
        for (ll prost: prostNumbers) {
            for (const auto &value: numbersLast) {
                if (!value.second[prost] && (BIG_NUMBER / value.first >= prost)) {
                    numbersNew.push_back(value);
                    numbersNew.back().first *= prost;
                    numbersNew.back().second[prost] = 1;

                }
                if (numbersNew.size() >= 1e7) {
                    std::cerr << numbersNew.back().first << '\n';
                }
            }
        }
        numbersLast = std::move(numbersNew);
        numbersNew.clear();
        //std::cout << numbersLast.size() << " " << tt << '\n';
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    precalc();
    // letCheck();
    for (ll num: prostNumbers) {
        std::cerr << num << " " << howMuch(num) << '\n';
    }
    return 0;
}