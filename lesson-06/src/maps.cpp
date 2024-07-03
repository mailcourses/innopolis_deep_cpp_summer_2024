#include <iostream>
#include <map>
#include <vector>
//#include <multimap>
#include <unordered_map>

int main()
{
    std::map<std::string, int32_t> counter;
    //std::unordered_map<std::string, int32_t> counter;
    //counter.reserve(1024);
    std::vector<std::string> words = {"let", "it", "be", "let", "let", "it", "abc", "cat", "zzz"};
    for (const auto& word : words ) {
        std::map<std::string, int32_t>::iterator it = counter.find(word);
        //std::unordered_map<std::string, int32_t>::iterator it = counter.find(word);
        // auto it = counter.find(word);
        // Мы ничего не нашли.
        if (it == counter.end()) {
            counter[word] = 0;
        }
        counter[word] += 1;
    }

    auto begin = counter.begin(); // std::begin(counter)
    auto end = counter.end(); // std::end(counter)
    while (begin != end) {
        std::cout << "key = " << begin->first << ", value= " << begin->second << std::endl;
        ++begin;
    }

    int32_t group_id = 42;
    const std::map<int32_t, std::vector<int32_t>> ids;
    std::cout << ids.count(group_id) << std::endl;
    std::cout << ids.size() << std::endl;

    std::unordered_multimap<std::string, int32_t> mmap;
    mmap.insert(std::make_pair(std::string{"duck"}, 1));
    mmap.insert(std::make_pair(std::string{"duck"}, 2));
    mmap.insert(std::make_pair(std::string{"duck"}, 3));
    {
        auto mm_begin = std::begin(mmap);
        auto mm_end = std::end(mmap);
        while (mm_begin != mm_end) {
            std::cout << "key = " << mm_begin->first << ", value = " << mm_begin->second << std::endl;
            ++mm_begin;
        }
    }
    auto find_it = mmap.find("duck");
    while (find_it != mmap.end()) {
        std::cout << "found key " << find_it->first << ", value = " << find_it->second << std::endl;
        mmap.erase(find_it);
        find_it = mmap.find("duck");
    }
}
