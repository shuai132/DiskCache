#include <string>
#include <string_view>

namespace diskcache {

//using byte = unsigned char;

class diskcache {
public:
    explicit diskcache(std::string_view path, double maxDiskUsage = 0.9f)
    : path_(path)
    , maxDiskUsage_(maxDiskUsage)
    {}

public:
    std::size_t push(const void* data, std::size_t size) {
        return ++length_;
    }

    template <typename T>
    std::size_t push(T& data) {
        return push(&data, sizeof(data));
    }

    std::tuple<bool, void*, std::size_t> pop() {
        if (length_ == 0) {
            return {false, nullptr, 0};
        }

        return {true, data, --length_};
    }

private:
    std::string path_;
    double maxDiskUsage_;

    std::size_t length_;
};

}
