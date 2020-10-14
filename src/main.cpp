//
// Created by victorguerraveloso on 13/10/2020.
//
#include <iostream>
#include "StockExchange.h"

int main() {
    int N, C;
    std::cin >> N >> C;
    int P[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> P[i];
    }
    std::cout << StockExchange(C, N, P).calculateMaxProfit() << std::endl;
    return 0;
}