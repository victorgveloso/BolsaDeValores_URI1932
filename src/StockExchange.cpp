//
// Created by victorguerraveloso on 13/10/2020.
//

#include "StockExchange.h"

int calculate(int *start, int *end, int fee) {
    if (start >= end) {
        return 0;
    }
    int *nextToMax = start;
    int *prevToMin = end;
    bool left_ascending = false;
    // Divide
    while (nextToMax <= end) {
        if (*nextToMax <= *(nextToMax - 1)) {
            if (left_ascending) {
                break;
            }
        } else {
            left_ascending = true;
        }
        ++nextToMax;
    }
    bool right_descending = false;
    while (start <= prevToMin) {
        if (*prevToMin >= *(prevToMin + 1)) {
            if (right_descending) {
                break;
            }
        } else {
            right_descending = true;
        }
        --prevToMin;
    }
    // Conquer
    int delta = (*end) - (*start);
    int left, right, first_case = delta - fee;
    if (end < nextToMax) { // must be OR for sorted inputs
        return std::max(first_case, 0);
    }
    else if (prevToMin < start) {
        return std::max((*(nextToMax-1) - (*start)) - fee, 0);
    }
    else {
        left = calculate(start, nextToMax - 1, fee);
        right = calculate(prevToMin + 1, end, fee);
        int forth_case = left + right;
        return std::max({first_case, forth_case, 0});
    }
}

int StockExchange::calculateMaxProfit() {
    return calculate(stocks, stocks + days - 1, fee);
}
