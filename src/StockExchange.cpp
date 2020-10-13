//
// Created by victorguerraveloso on 13/10/2020.
//

#include "StockExchange.h"

int calculate(int *start, const int *end, int fee) {
    int *cursor = start + 1;
    bool ascending = false;
    int left = 0;
    int right = 0;
    int mid = 0;
    int *pivot = nullptr;
    while (cursor <= end) { //TODO: break recursively
        if (*cursor <= *(cursor - 1)) {
            if (ascending) {
                ascending = false;
                if(pivot != nullptr) {
                    mid = calculate(pivot, cursor - 1, fee);
                    right = calculate(cursor, end, fee);
                    break;
                }
                else {
                    pivot = cursor;
                    left = calculate(start, pivot - 1, fee);
                }

            }
        } else {
            ascending = true;
        }
        ++cursor;
    }
    int delta = (*end) - (*start);
    if (cursor > end) {
        if (pivot != nullptr) {
            right = calculate(pivot, end, fee);
            return std::max({delta - fee, left + right, 0});
        }
        else {
            return std::max({delta - fee, 0});
        }
    }
    int left_aggregated = *(cursor-1) - *start - fee;
    int right_aggregated = *end - *pivot - fee;
    return std::max({
        delta - fee,
        left + mid + right,
        left_aggregated + right,
        right_aggregated + left,
        0});
}

int StockExchange::calculateMaxProfit() {
    return calculate(stocks, stocks + days - 1, fee);
}
