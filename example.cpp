#include "fs.h"
#include "cc.h"
#include "log.h"

struct TestData {
    uint8_t a;
    uint8_t b;
    uint8_t c;
};

int main(int argc, char **argv) {
    LOGI("available space: %.2lf%%", diskcache::fs::getAvailablePercent("/"));

    diskcache::diskcache cache("/tmp");

    {
        TestData data {1, 2, 3};
        cache.push(&data, sizeof(data));
    }

    {
        std::tuple<bool, void*, std::size_t> ret = cache.pop();
        auto* dataP = (TestData*)std::get<2>(ret);
        LOGI("%u, %u, %u", dataP->a, dataP->b, dataP->c);
    }

    return 0;
}
