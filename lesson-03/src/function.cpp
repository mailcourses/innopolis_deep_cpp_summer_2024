#include <iostream>
#include <functional>

void moveLeft(int& x, int&y)
{
    std::cout << "Move left (" << x << ", " << "y)" << std::endl;
    --x;
}

class RightMover
{
public:
    void operator()(int&x, int&y)
    {
        std::cout << "RightMover (" << x << ", " << "y)" << std::endl;
        ++x;
    }
};

using MoverType = std::function<void (int&, int&)>;
//using map_t = std::unordered_map<std::string, std::vector<std::queue>>;
//map_t::iterator;

int main()
{
    auto top_mover = [](int&x, int&y) -> void {
        ++y;
    };

    RightMover right_mover;
    std::vector<MoverType> movers = {moveLeft, top_mover, right_mover};
    int x = 0, y = 0;
    for (auto mover: movers) {
        mover(x, y);
    }
    std::cout << "x = " << x << " y = " << y << std::endl;
}
