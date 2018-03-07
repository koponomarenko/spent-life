#include "person.h"
#include <iostream>

Person create_person();
void show_spent_life(int spent_years);

int main()
{
    Person person = create_person();
    int spent_years = person.get_age();
    show_spent_life(spent_years);
}

Person create_person()
{
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

    return Person(birth_year, birth_month, bith_day);
}

void show_spent_life(int spent_years)
{
    const int life_expectancy = 100; // in Earth years
    // 80 years sounds more realistic in general.

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
