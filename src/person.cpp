#include "person.h"
#include <ctime>

Person::Person(int birth_year, int birth_month, int bith_day)
    : birth_year_(birth_year), birth_month_(birth_month), bith_day_(bith_day)
{
    // Set the birthday time
    std::tm timeinfo = {0};
    timeinfo.tm_year = birth_year_ - 1900;  // years since 1900
    timeinfo.tm_mon = birth_month_ - 1;     // months since January    0-11
    timeinfo.tm_mday = bith_day_;           // day of the month        1-31
    timeinfo.tm_hour = 0;                   // hours since midnight    0-23
    timeinfo.tm_min = 0;                    // minutes after the hour  0-59
    std::time_t tt = std::mktime(&timeinfo);
    birth_time_ = std::chrono::system_clock::from_time_t(tt);
}

int Person::get_age() const
{
    // Get the current date
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

    std::chrono::system_clock::duration spent_life = today - birth_time_;
    typedef std::chrono::duration<int, std::ratio<60*60*24*365>> years_t;
    int spent_years = std::chrono::duration_cast<years_t>(spent_life).count();
    return spent_years;
}
