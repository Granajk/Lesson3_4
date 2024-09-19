#pragma once
#include "Time.h"
#include "Date.h"
#include <string>

class Order
{
	Date orderDate;
	Time_ orderTime;
	int readyMinuts;
	string info;
	float price;
	int numberOfOrder;
	static int counter;
public:
	Order();
	Order(string info, float price, int readyMinuts);

	Date getOrderDate()const;
	Time_ getOrderTime()const;
	int getReadyMinuts()const;
	string getInfo()const;
	float getPrice()const;
	int getNumberOfOrder()const;
	Time_ getReadyOrderTime()const;


};

