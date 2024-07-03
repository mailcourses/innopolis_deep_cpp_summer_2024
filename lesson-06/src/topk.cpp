#include <queue>
#include <vector>
#include <iostream>

int main()
{
    //                               0   1  2  3  4  5   6  7
    std::vector<int32_t> arr_orig = {10, 4, 8, 2, 3, 13, 9, 7};
    const int k = 3;
    {
        std::vector<int32_t> arr(arr_orig);
        // O(n log n)
        std::sort(std::begin(arr), std::end(arr));
        std::vector<int32_t> res;
        res.reserve(k);
        auto begin = arr.rbegin();
        auto end = arr.rend();
        // O(k)
        while (res.size() != k && begin != end) {
            res.push_back( *begin );
            ++begin;
        }
        // O(k)
        for (auto num : res ) {
            std::cout << num << " ";
        }
        // O(n*(log n))
        std::cout << std::endl;
    }

    {
        std::vector<int32_t> arr(arr_orig);
        std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> pq;
        // O(n)
        for (auto num : arr) {
            // O(log k)
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        std::vector<int32_t> res;
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        std::reverse(std::begin(res), std::end(res));
        for (auto num : res ) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
