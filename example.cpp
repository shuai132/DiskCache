#include "fs.h"
#include "log.h"

int main(int argc, char **argv) {
    LOGI("available space: %.2lf%%", diskcache::fs::getAvailablePercent("/"));
    return 0;
}
