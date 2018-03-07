#include "person.h"
#include <iostream>

const int hundred_percent = 100;

int main()
{
    const int life_expectancy = 100; // in Earth years
    // 80 years sounds more realistic in general.

    // Get the birth date of the person
    std::cout << "Enter your birth ...";
    std::cout << "year";
    int birth_year = 1987;
    //cin >> birth_year;
    std::cout << "month";
    int birth_month = 6;
    //cin >> birht_month;
    std::cout << "day";
    int bith_day = 29;
    //cin >> birth_day;
    std::cout << std::endl;


    std::cout << std::endl;
    Person person(birth_year, birth_month, bith_day);
    int spent_years = person.get_age();
    std::cout << "You've been living for " << spent_years << " years" << std::endl;
    std::cout << "It is " << spent_years / (life_expectancy / hundred_percent) << "% of " << life_expectancy << " years of life expectancy." << std::endl;


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
