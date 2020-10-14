//
// Created by victorguerraveloso on 13/10/2020.
//

#include "StockExchange.h"

int calculate(int *start, int *end, int fee) {
    if (start >= end) {
        return 0;
    }
    int *midleft = start + 1;
    int *midright = end - 1;
    bool left_ascending = false;
    // Divide
    while (midleft <= midright) {
        if (*midleft <= *(midleft - 1)) {
            if (left_ascending) {
                break;
            }
        } else {
            left_ascending = true;
        }
        ++midleft;
    }
    bool right_descending = false;
    while (midleft <= midright) {
        if (*midright >= *(midright + 1)) {
            if (right_descending) {
                break;
            }
        } else {
            right_descending = true;
        }
        --midright;
    }
    // Conquer
    int delta = (*end) - (*start);
    int left, right, first_case = delta - fee;
    if (start > midright || end < midleft) { // must be OR for sorted inputs
        return std::max(first_case, 0);
    }
    else {
        left = calculate(start, midleft - 1, fee);
        right = calculate(midright + 1, end, fee);
        if (midleft <= midright) {
            int left_aggregated = calculate(start, midright, fee);
            int right_aggregated = calculate(midleft, end, fee);
            int second_case = left_aggregated + right;
            int third_case = left + right_aggregated;
            // Combine #1
            return std::max({first_case, second_case, third_case, 0});
        } else {
            int forth_case = left + right;
            // Combine #2
            return std::max({first_case, forth_case, 0});
        }
    }
}

int StockExchange::calculateMaxProfit() {
    return calculate(stocks, stocks + days - 1, fee);
}
