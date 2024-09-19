#include "Order.h"

Order::Order()
{
    
}

Order::Order(string info, float price, int readyMinuts)
{
    orderTime = Time_();
    orderDate = Date();
    numberOfOrder = ++counter;
    this->price = price;
    this->info = info;
    this->readyMinuts = readyMinuts;

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
    return numberOfOrder;
}

Time_ Order::getReadyOrderTime() const
{
    return orderTime + (float)readyMinuts;
}
