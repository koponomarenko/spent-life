#ifndef PERSON_H
#define PERSON_H

#include <chrono>

class Person
{
public:
    Person(int, int, int);
    int get_age() const;

private:
    Person();

    int birth_year_;
    int birth_month_;
    int bith_day_;
    std::chrono::system_clock::time_point birth_time_;
};

#endif // PERSON_H
