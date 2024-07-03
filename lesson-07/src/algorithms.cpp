#include <algorithm>
#include <iostream>
#include <vector>

struct City
{
    std::string name_;
    size_t population_ = 0;
    City(const std::string &name, size_t population) : name_(name), population_(population) {} 
};

int main()
{
    std::vector<int> v { 3, 2, 3, 4, 8 };
    auto n = std::count(v.begin(), v.end(), 3);
    std::cout << "Count ot three is " << n << std::endl;

    auto even_n = std::count_if(std::begin(v), std::end(v), [](int num) { return num % 2 == 0; });
    std::cout << "Count of even numbers is " << even_n << std::endl;

    std::vector<City> cities = {City("Moscow", 12000000), City("Kazan", 1308660), City("Omsk", 1160000), City("Domodedovo", 127000), City("Bolgar", 8285)};
    auto big_city_cnt = std::count_if(std::begin(cities), std::end(cities), [](City& city) { return city.population_ > 1000000; });
    std::cout << "big city cnt = " << big_city_cnt << std::endl;
}
