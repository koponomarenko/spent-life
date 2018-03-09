#include "person.h"
#include <iostream>

Person create_person();
void show_spent_life(int spent_years);
void show_spent_life(const Person & person);

int main()
{
    Person person = create_person();
    //Person person = Person(1987, 6, 29);
    int spent_years = person.get_age(Age_units::years);
    show_spent_life(spent_years);
    //show_spent_life(person);
}

Person create_person()
{
    // Get the birth date of the person
    std::cout << "Enter your birth ..." << std::endl;
    std::cout << "year: ";
    int birth_year;
    std::cin >> birth_year;
    std::cout << "month (number): ";
    int birth_month;
    std::cin >> birth_month;
    std::cout << "day: ";
    int birth_day;
    std::cin >> birth_day;

    return Person(birth_year, birth_month, birth_day);
}

void show_spent_life(int spent_years)
{
    const int life_expectancy = 100; // in Earth years
    // 80 years sounds more realistic in general.

    std::cout << std::endl;
    std::cout << "You've been living for " << spent_years << " years" << std::endl;
    const int hundred_percent = 100;
    std::cout << "It is " << spent_years / (life_expectancy / hundred_percent)
              << "% of " << life_expectancy << " years of life expectancy." << std::endl;

    std::cout << std::endl;
    // show in matrix 10x10
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (spent_years > 0)
            {
                std::cout << '+';
                --spent_years;
            }
            else
            {
                std::cout << '-';
            }
        }
        std::cout << std::endl;
    }
}

void show_spent_life(const Person & person)
{
    std::cout << std::endl;
    std::cout << "years: " << person.get_age(Age_units::years) << std::endl;
    std::cout << "months: " << person.get_age(Age_units::months) << std::endl;
    std::cout << "days: " << person.get_age(Age_units::days) << std::endl;
    std::cout << "hours: " << person.get_age(Age_units::hours) << std::endl;
    std::cout << "minutes: " << person.get_age(Age_units::minutes) << std::endl;
    std::cout << "seconds: " << person.get_age(Age_units::seconds) << std::endl;
}
