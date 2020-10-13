//
// Created by victorguerraveloso on 13/10/2020.
//

#ifndef BOLSADEVALORES_STOCKEXCHANGE_H
#define BOLSADEVALORES_STOCKEXCHANGE_H
#include <bits/stdc++.h>

class StockExchange {
    int *stocks;
    int days;
    int fee;
public:

    StockExchange(int C, int N, int *P) : days(N), fee(C), stocks(P) {}
    int getStock(int idx) const {
        return stocks[idx];
    }

    int getDays() const {
        return days;
    }

    int getFee() const {
        return fee;
    }

    int calculateMaxProfit();
};


#endif //BOLSADEVALORES_STOCKEXCHANGE_H
