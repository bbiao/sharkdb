#ifndef SHARKDB_COMMON_UTILS_H
#define SHARKDB_COMMON_UTILS_H

#include <pthread.h>

namespace sharkdb {
namespace common {

class Mutex {

public:
    Mutex();
    virtual ~Mutex();
    void Lock();
    void Unlock();

private:
    pthread_mutex_t mutex_;

};

class Lockable {

public:
    void RdLock();
    void WrLock();

    void Unlock();
};

}
}

#endif//SHARKDB_COMMON_UTILS_H
