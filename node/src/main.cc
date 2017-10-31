#include <gflags/gflags.h>
#include <butil/logging.h>

#include "node.h"

using sharkdb::node::Node;
using logging::LoggingSettings;

Node* g_node = NULL;

void InitSystem() {
    LoggingSettings logging_settings;
    logging_settings.logging_dest = logging::LOG_TO_FILE;
    logging_settings.log_file = "./logs/node.log";
    InitLogging(logging_settings);
}

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    InitSystem();

    g_node = new Node;
    g_node->Start();

    delete g_node;

    LOG(ERROR) << "application stopped";
    return 0;
}
