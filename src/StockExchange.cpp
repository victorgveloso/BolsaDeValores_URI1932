//
// Created by victorguerraveloso on 13/10/2020.
//

#include "StockExchange.h"


int StockExchange::calculateMaxProfit() {
    int max = stocks[0], min = stocks[0], total = 0;
    for (int i = 1; i < days; ++i) {
        if (stocks[i] > max) {
            max = stocks[i];
        } else {
            if (max >= stocks[i] + fee || stocks[i] < min) {
                total += std::max(max - min - fee, 0);
                max = min = stocks[i]; // reset min-max
            }
        }
    }
    total += std::max(max - min - fee, 0);
    return total;
}
