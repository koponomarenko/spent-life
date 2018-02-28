#include <iostream>
#include <chrono>
#include <ctime>

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

    std::cout << std::endl;
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
