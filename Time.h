#pragma once
#include <iostream>
using namespace std;

class Time_
{
	int hours;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours),    false = am/pm (12-hours), 

public:
	Time_(); // Current local time
	Time_(int hours, int minutes, int seconds = 0, bool format = true);
	Time_(const Time_& obj); //?? копирование

	void setHour(int hours);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format

	Time_& operator --(); //previous minute
	Time_ operator --(int); //previous minute
	Time_& operator ++(); //next minute
	Time_ operator ++(int); //next minute

	//--------- Comparison operators ---------
	bool operator == (const Time_& obj)const&;
	bool operator != (const Time_& obj)const&;
	bool operator > (const Time_& obj)const&;
	bool operator < (const Time_& obj)const&;
	bool operator >= (const Time_& obj)const&;
	bool operator <= (const Time_& obj)const&;

	//--------- Assignment operators ---------	
	Time_& operator += (int s);		// add seconds
	Time_& operator -= (int s);
	Time_& operator += (float m);	// add minutes
	Time_& operator -= (float m);
	Time_& operator += (double h);	// add hours
	Time_& operator -= (double h);

	//--------- Arithmetic operators ---------
	Time_ operator + (int s)const&;	// add seconds
	Time_ operator - (int s)const&;
	friend Time_ operator + (int s, const Time_& a);
	friend Time_ operator - (int s, const Time_& a);

	Time_ operator + (float m)const&; // add minutes
	Time_ operator - (float m)const&;
	friend Time_ operator + (float m, const Time_& a);
	friend Time_ operator - (float m, const Time_& a);

	Time_ operator + (double h)const&; // add hours
	Time_ operator - (double h)const&;
	friend Time_ operator + (double h, const Time_& a);
	friend Time_ operator - (double h, const Time_& a);


	//--------- Iostream operators ---------
	friend ostream& operator << (ostream& os, const Time_& t);
	friend istream& operator >> (istream& is, Time_& t);
};

