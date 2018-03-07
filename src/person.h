#ifndef PERSON_H
#define PERSON_H

#include <chrono>

enum class Age_units { years, months, days, hours, minutes, seconds };

class Person
{
public:
    Person(int, int, int);
    int get_age(Age_units) const;

private:
    Person();

    int birth_year_;
    int birth_month_;
    int bith_day_;
    std::chrono::system_clock::time_point birth_time_;
};

#endif // PERSON_H
