//
// Created by victorguerraveloso on 13/10/2020.
//

#include "StockExchange.h"

int calculate(int *start, const int *end, int fee) {
    int *cursor = start + 1;
    bool ascending = false;
    int left = 0;
    int right = 0;
    while (cursor <= end) { //TODO: break recursively
        if (*cursor <= *(cursor - 1)) {
            if (ascending) {
                left = calculate(start, cursor - 1, fee);
                right = calculate(cursor, end, fee);
                break;

            }
        } else {
            ascending = true;
        }
        ++cursor;
    }
    int delta = (*end) - (*start);
    return std::max({delta - fee, left + right, 0});
}

int StockExchange::calculateMaxProfit() {
    return calculate(stocks, stocks + days - 1, fee);
}
