#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

public:
	//--------- КОНСТРУКТОРИ та ДЕСТРУКТОРИ ---------
	Date(); // За замовчуванням - поточна дата
	Date(int year, int month, int day); // З параметрами - задана дата	 

	bool isLeapYear()const; //Перевірка на високосний рік
	int monthDays()const; //Кількість днів за місяцем
	void nextDate(); // Наступна дата
	void prevDate(); // Попередня дата        
	bool valid()const; // Перевірка дати на коректність

	//--------- АКСЕСОРИ ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;


	//--------- ОПЕРАТОРИ виведення та введення
	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);


	//--------- ОПЕРАТОРИ ІНКРЕМЕНТУ ТА ДЕКРЕМЕНТУ ---------
	Date& operator --(); // Префіксна форма декременту
	Date operator --(int); // Постфіксна форма декременту
	Date& operator ++ (); // Префіксна форма інкременту
	Date operator ++ (int); // Постфіксна форма інкременту

	//--------- ОПЕРАТОРИ ПОРІВНЯННЯ ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;


	//--------- ОПЕРАТОРИ ПРИСВОЄННЯ ---------	
	Date& operator += (int days); // додати days днів до дати
	Date& operator -= (int days); // відняти days дні від дати
	Date& operator += (double years); // додати years років до дати
	Date& operator -= (double years); // відняти years років від дати


	//--------- АРИФМЕТИЧНІ ОПЕРАТОРИ ---------
	Date operator + (int days)const&;
	Date operator - (int days)const&;
	friend Date operator + (int days, const Date& a);
	friend Date operator - (int days, const Date& a);

	Date operator + (double years)const&;
	Date operator - (double years)const&;
	friend Date operator + (double years, const Date& a);
	friend Date operator - (double years, const Date& a);

};