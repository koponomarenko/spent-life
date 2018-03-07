#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(int, int, int);
    int get_age() const;

private:
    Person();

    int birth_year;
    int birth_month;
    int bith_day;
};

#endif // PERSON_H
