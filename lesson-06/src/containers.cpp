#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>
#include <cassert>

enum class RankerType {
    Date = 0,
    Default = 1,
    Distance = 2,
};

std::unordered_map<std::string, RankerType> ranker_type_map = {
   { "date", RankerType::Date },
   { "distance", RankerType::Distance },
   { "default", RankerType::Default }
};

// avl_map<std::string, RankerType> ranker_type_map = {
//    { "date", RankerType::Date },
//    { "distance", RankerType::Distance },
//    { "default", RankerType::Default }
// };

RankerType convertStrToRankerType(const std::string& param) {
    auto it = ranker_type_map.find( param );
    if ( it != ranker_type_map.end() ) {
        return it->second;
    }
    return RankerType::Default;
}

struct A
{
    A(int, double, std::string) {
        std::cout << "ctr A(int, double, std::string)" << std::endl;
    }
    A(const A& a) {
        std::cout << "copy ctr A(A)" << std::endl;
    }
    A(A&& a) {
        std::cout << "move ctr A(A)" << std::endl;
    }
};

int main()
{
    ranker_type_map["new_date"] =  RankerType::Default;
    // int arr[5];
    std::array<int, 5> arr1;
    for (size_t i = 0; i < 5; ++i) {
        arr1[i] = i + 1;
    }

    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};

    assert(arr1 == arr2);
    /*
    size_t n = 0;
    std::cin >> n;
    std::array<int, n> arr3;
    */
    const std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    /*
     * std::vector<std::pair<int, int>> directions;
     * directions.push_back(std::make_pair(1, 0));
     * directions.push_back(std::make_pair(-1, 0));
     * directions.push_back(std::make_pair(0, 1));
     * directions.push_back(std::make_pair(0, -1));
     */
    std::vector<std::string> params(10);
    std::cout << "params.size() = " << params.size() << std::endl;
    std::cout << "params.capacity() = " << params.capacity() << std::endl;
    params[9] = std::string{"Hello world"};
    for (size_t i = 0; i < params.size(); ++i) {
        std::cout << i << ") " << params[i] << std::endl;
    }
    params.reserve(20);
    std::cout << "params.size() = " << params.size() << std::endl;
    std::cout << "params.capacity() = " << params.capacity() << std::endl;
    try {
        params.at(19) = std::string{"Hello kitty"};
        //params[19] = std::string{"Hello kitty"};
    }
    catch (std::out_of_range) {
        std::cerr << "Exception: out of range" << std::endl;
    }
    for (size_t i = 0; i < 5; ++i) {
        params.push_back(std::to_string(i));
    }
    std::cout << "params.size() = " << params.size() << std::endl;
    std::cout << "params.capacity() = " << params.capacity() << std::endl;

    
    for (size_t i = 0; i < params.size(); ++i) {
        std::cout << i << ") " << params[i] << std::endl;
    }

    const int alphabet_size = 26;
    std::vector<int> counter(alphabet_size, 0);
    std::cout << "counter.size() = " << counter.size() << std::endl;
    std::cout << "counter.capacity() = " << counter.capacity() << std::endl;
    counter.reserve(alphabet_size * 2);
    std::cout << "counter.size() = " << counter.size() << std::endl;
    std::cout << "counter.capacity() = " << counter.capacity() << std::endl;
    for (size_t i = 0; i < alphabet_size + 1; ++i) {
        counter.push_back(i);
        std::cout << "i = " << i << std::endl;
        std::cout << "counter.size() = " << counter.size() << std::endl;
        std::cout << "counter.capacity() = " << counter.capacity() << std::endl;
    }
    counter[50] = 100500;
    /*counter.resize(alphabet_size * 3);
    std::cout << "counter.size() = " << counter.size() << std::endl;
    std::cout << "counter.capacity() = " << counter.capacity() << std::endl;
    */

    A a(10, 2.0, std::string{"Hello"});
    std::vector<A> aaa;
    aaa.reserve(10);
    std::cout << "Before push_back" << std::endl;
    aaa.push_back(a);
    std::cout << "Before emplace_back" << std::endl;
    aaa.emplace_back(10, 2.0, std::string{"Hello"});
    std::cout << "Before emplace_back(A)" << std::endl;
    aaa.emplace_back(a);

    std::vector<int> nums = {1,2,3,4,5};

    const size_t nums_size = nums.size();
    for (size_t i = 0; i < nums_size; ++i) {
        nums.push_back(i);
    }
    nums.reserve(1024);
    std::vector<int>().swap(nums); // <-- capacity станет 0
    //nums.clear();                // <-- capacity не изменится
    std::cout << "nums.size() = " << nums.size() << std::endl;
    std::cout << "nums.capacity() = " << nums.capacity() << std::endl;
    
}
