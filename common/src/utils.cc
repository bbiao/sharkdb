#include "utils.h"

namespace sharkdb {
namespace common {

Mutex::Mutex() {
    pthread_mutex_init(&mutex_, NULL);
}

Mutex::~Mutex() {
    pthread_mutex_destroy(&mutex_);
}

void Mutex::Lock() {
    pthread_mutex_lock(&mutex_);
}

void Mutex::Unlock() {
    pthread_mutex_unlock(&mutex_);
}

}
}
