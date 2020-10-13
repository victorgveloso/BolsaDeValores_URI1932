//
// Created by victorguerraveloso on 13/10/2020.
//

#include <gtest/gtest.h>
#include "StockExchange.h"
TEST(TestStockExchange, ConstructionTest) {
    int C = 2, N = 3, P[] = {1,2,3};
    auto se = StockExchange(C,N,P);
    EXPECT_EQ(se.getDays(), 3);
    EXPECT_EQ(se.getFee(), 2);
    EXPECT_EQ(se.getStock(0),1);
    EXPECT_EQ(se.getStock(1),2);
    EXPECT_EQ(se.getStock(2),3);
}
TEST(TestStockExchange, FirstExampleTest) {
    int C = 10, N = 6, P[] = {100,120,130,80,50,40};
    auto se = StockExchange(C,N,P);
    EXPECT_EQ(se.calculateMaxProfit(), 20);
}
TEST(TestStockExchange, SecondExampleTest) {
    int C = 10, N = 5, P[] = {70,80,50,40,50};
    auto se = StockExchange(C,N,P);
    EXPECT_EQ(se.calculateMaxProfit(), 0);
}
TEST(TestStockExchange, ThirdExampleTest) {
    int C = 30, N = 13, P[] = {10,80,20,40,30,50,40,60,50,70,60,10,200};
    auto se = StockExchange(C,N,P);
    EXPECT_EQ(se.calculateMaxProfit(), 220);
}