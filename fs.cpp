#include <filesystem>
#include "fs.h"
#include "log.h"

namespace diskcache::fs {

float getAvailablePercent(std::string_view absPath) {
    auto info = std::filesystem::space(absPath);
    const auto MB = 1024 * 1024;
    auto percent = (double)info.available * 100 / info.capacity;
    LOGD("available: %lfMB, capacity: %lfMB, percent: %lf%%", (double)info.available / MB, (double)info.capacity / MB, percent);
    return percent;
}

}
