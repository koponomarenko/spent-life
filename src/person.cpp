#include "person.h"
#include "date.h"

Person::Person(int birth_year, int birth_month, int bith_day)
    : birth_year_(birth_year), birth_month_(birth_month), bith_day_(bith_day)
{
    date::year_month_day birthday = date::year{birth_year_}/birth_month_/bith_day_;
    birth_time_ = date::sys_days{birthday}; // high precision is specified differently on each platform.
}

int Person::get_age(Age_units age_units) const
{
    // Get the current time
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

    std::chrono::system_clock::duration spent_life = today - birth_time_;

    typedef std::chrono::duration<int, std::ratio_multiply<std::chrono::hours::period, std::ratio<24>>::type> Days;
    typedef std::chrono::duration<int, std::ratio<60*60*24*30>> Month; // wrong way of counting it !
    typedef std::chrono::duration<int, std::ratio<60*60*24*365>> Years;

    int age = 0;
    switch (age_units)
    {
    case Age_units::years:
        age = std::chrono::duration_cast<Years>(spent_life).count();
        break;
    case Age_units::months:
        age = std::chrono::duration_cast<Month>(spent_life).count();
        break;
    case Age_units::days:
        age = std::chrono::duration_cast<Days>(spent_life).count();
        break;
    case Age_units::hours:
        age = std::chrono::duration_cast<std::chrono::hours>(spent_life).count();
        break;
    case Age_units::minutes:
        age = std::chrono::duration_cast<std::chrono::minutes>(spent_life).count();
        break;
    case Age_units::seconds:
        age = std::chrono::duration_cast<std::chrono::seconds>(spent_life).count();
        break;
    }

    return age;
}
