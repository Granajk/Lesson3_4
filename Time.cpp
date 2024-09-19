#include "Time.h"
#include <ctime>
Time_::Time_()
{
    time_t now = time(0);
    tm* info = new tm;
    localtime_s(info, &now);

    hours = info->tm_hour;
    minutes = info->tm_min;
    seconds = info->tm_sec;
    format = false;
    delete info;
}

Time_::Time_(int hours, int minutes, int seconds, bool format)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time_::Time_(const Time_& obj)//?
{

}


void Time_::setHour(int hours)
{
    if (hours >= 0 && hours <= 23)
    {
        this->hours = hours;
    }
}

int Time_::getHour() const
{
    return hours;
}

void Time_::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes <= 59)
    {
        this->minutes = minutes;
    }
}

int Time_::getMinutes() const
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    if (seconds >= 0 && seconds <= 60)
    {
        this->seconds = seconds;
    }
}

int Time_::getSeconds() const
{
    return seconds;
}

void Time_::setFormat(bool format)
{
    this->format = format;
}

bool Time_::getFormat() const
{
    return format;
}

bool Time_::valid() const
{
    return (format == true || format == false) && (hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59) && (seconds >= 0 && seconds <= 60);
}

void Time_::tickTime()//every tick add one second
{
    if (hours == 23 && minutes == 59 && seconds == 59)
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    else if (hours < 23 && minutes == 59 && seconds == 59)
    {
        hours++;
        minutes = 0;
        seconds = 0;
    }
    else if (hours < 23 && minutes < 59 && seconds == 59)
    {
        minutes++;
        seconds = 0;
    }
    else
    {
        seconds++;
    }
}

void Time_::untickTime()
{
    if (hours == 0 && minutes == 0 && seconds == 0)
    {
        hours = 23;
        minutes = 59;
        seconds = 59;
    }
    else if (hours > 0 && minutes == 0 && seconds == 0)
    {
        hours--;
        minutes = 59;
        seconds = 59;
    }
    else if (hours > 0 && minutes > 0 && seconds == 0)
    {
        minutes--;
        seconds = 59;
    }
    else
    {
        seconds--;
    }
}

void Time_::showTime() const
{
    if (format)
    {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    else
    {
        bool isPM = hours >= 12;
        int displayHour = (hours % 12 == 0) ? 12 : hours % 12;

        cout << (displayHour < 10 ? "0" : "") << displayHour << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds
            << (isPM ? " PM" : " AM") << endl;
    }
}

Time_& Time_::operator--()
{
    this->untickTime();
    return *this;
}

Time_ Time_::operator--(int)
{
    Time_ tmp = *this;
    this->untickTime();
    return tmp;
}

Time_& Time_::operator++()
{
    this->tickTime();
    return *this;
}

Time_ Time_::operator++(int)
{
    Time_ tmp = *this;
    this->tickTime();
    return tmp;
}

bool Time_::operator==(const Time_& obj) const&
{
    return hours == obj.hours && minutes == obj.minutes && seconds == obj.seconds;
}

bool Time_::operator!=(const Time_& obj) const&
{
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
    if (hours > obj.hours)
    {
        return true;
    }
    else if (hours == obj.hours && minutes > obj.minutes)
    {
        return true;
    }
    else if (hours == obj.hours && minutes == obj.minutes && seconds > obj.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time_::operator<(const Time_& obj) const&
{
    return !(*this > obj) || *this != obj;
}

bool Time_::operator>=(const Time_& obj) const&
{
    return !(*this > obj) || *this == obj;
}

bool Time_::operator<=(const Time_& obj) const&
{
    return !(*this < obj) || *this == obj;
}

Time_& Time_::operator+=(int s)
{
    for (int i = 0; i < seconds; i++)
    {
        this->tickTime();
    }return *this;
}

Time_& Time_::operator-=(int s)
{
    for (int i = 0; i < seconds; i++)
    {
        this->untickTime();
    }return *this;
}

Time_& Time_::operator+=(float m)
{
    for (int i = 0; i < minutes; i++)
    {
        this->tickTime();
    }return *this;
}

Time_& Time_::operator-=(float m)
{
    for (int i = 0; i < minutes; i++)
    {
        this->untickTime();
    }return *this;
}

Time_& Time_::operator+=(double h)
{
    for (int i = 0; i < hours; i++)
    {
        this->tickTime();
    }return *this;
}

Time_& Time_::operator-=(double h)
{
    for (int i = 0; i < hours; i++)
    {
        this->untickTime();
    }return *this;
}
//-----------------------------------
Time_ Time_::operator+(int s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(int s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator+(float m) const&
{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(float m) const&
{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(double h) const&
{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(double h) const&
{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}

Time_ operator+(int s, const Time_& a)
{
    return a + s;
}

Time_ operator-(int s, const Time_& a)
{
    return a - s;
}

Time_ operator+(float m, const Time_& a)
{
    return a + m;
}

Time_ operator-(float m, const Time_& a)
{
    return a - m;
}

Time_ operator+(double h, const Time_& a)
{
    return a + h;
}

Time_ operator-(double h, const Time_& a)
{
    return a - h;
}

ostream& operator<<(ostream& os, const Time_& t)
{
    if (t.format)
    {
        os << (t.hours < 10 ? "0" : "") << t.hours << ":"
            << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
            << (t.seconds < 10 ? "0" : "") << t.seconds;
    }
    else
    {
        bool isPM = t.hours >= 12;
        int displayHour = (t.hours % 12 == 0) ? 12 : t.hours % 12;

        os << (displayHour < 10 ? "0" : "") << displayHour << ":"
            << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
            << (t.seconds < 10 ? "0" : "") << t.seconds
            << (isPM ? " PM" : " AM");
    }
    return os;
}

istream& operator>>(istream& is, Time_& t)
{
    do
    {
        cout << "(24-hours)true/false(12-hours) hh mm ss: ";
        is >> t.format >> t.hours >> t.minutes >> t.seconds;
    } while (!t.valid());
    return is;
}
