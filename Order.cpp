#include "Order.h"

Order::Order()
{
}

Order::Order(string info, float price, int readyMinuts)
{
}

Date Order::getOrderDate() const
{
    return Date();
}

Time_ Order::getOrderTime() const
{
    return Time_();
}

int Order::getReadyMinuts() const
{
    return 0;
}

string Order::getInfo() const
{
    return string();
}

float Order::getPrice() const
{
    return 0.0f;
}

int Order::getNumberOfOrder() const
{
    return 0;
}

Time_ Order::getReadyOrderTime() const
{
    return Time_();
}
