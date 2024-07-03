#include <cassert>
#include <iostream>
#include <system_error>

enum class [[nodiscard]] HttpCode
{
    OK = 200,
    NO_CONTENT = 204,
    NOT_FOUND = 404,
    SERVER_ERROR = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    int get(size_t i)
    {
        size_t size_ = 100;
        int data[size_];
        assert(i < size_);
        return data[i];
    }

    std::string message(int code) const noexcept override
    {
        switch(code) {
            case 200:
                return "ok";
            case 404:
                return "not found";
            case 500:
                return "internal server error";
            default:
                //assert(!"unknown http code");
                assert("unknown http code");
                return "";
        }
    }
};

std::error_code make_error_code(HttpCode code)
{
    static const HttpCategory instance;
    return std::error_code(static_cast<int>(code), instance);
}

std::error_code download(const std::string& url)
{
    return make_error_code(HttpCode::NO_CONTENT);
}

HttpCode foo()
{
    return HttpCode::NOT_FOUND;
}

int main()
{
    const auto error = download("https://vk.com");
    if (error) {
        std::cout << error << std::endl;
        std::cout << error.message() << std::endl;
    }
    auto val = foo();
}
