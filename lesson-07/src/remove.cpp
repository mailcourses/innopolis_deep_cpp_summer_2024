#include <algorithm>
#include <iostream>

int main()
{
    std::string str{"bambolelio, bamboleia!"};
    //                  |
    // bambolelio, bamboleia!
    //                      |
    // amolelio, amoleia!eia!
    auto it = std::remove(std::begin(str), std::end(str), 'b');
    std::cout << "result = [" << str << "]\n";
    str.erase(it, std::end(str));
    std::cout << "result after erase = [" << str << "]\n";
}
