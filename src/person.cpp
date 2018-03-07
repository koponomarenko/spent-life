#include "person.h"
#include <chrono>
#include <ctime>

Person::Person(int birth_year, int birth_month, int bith_day)
    : birth_year(), birth_month(), bith_day()
{
}

int Person::get_age() const
{
    // Get the current date
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

    // TODO: rewrite this piece
    std::tm timeinfo = {0};
    timeinfo.tm_year = birth_year - 1900; // years since 1900
    timeinfo.tm_mon = birth_month - 1; // January is 0
    timeinfo.tm_mday = bith_day;
    std::time_t tt = std::mktime(&timeinfo);
    std::chrono::system_clock::time_point birth_date = std::chrono::system_clock::from_time_t(tt);

    std::chrono::system_clock::duration spent_life = today - birth_date;
    // convert to number of years
    typedef std::chrono::duration<int, std::ratio<60*60*24*365>> years_t;
    int spent_years = std::chrono::duration_cast<years_t>(spent_life).count();
    return spent_years;
}
