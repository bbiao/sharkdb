/**
 * @file main.cc
 * @brief main entry for master
 * @author Zhang Biao(zhangbiaozb@didichuxing.com)
 * @version 0.0.1
 * @date 2017-11-02
 */

#include <gflags/gflags.h>

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    return 0;
}
