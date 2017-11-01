#ifndef SHARKDB_NODE_NODE_H
#define SHARKDB_NODE_NODE_H

#include "common.h"

SHARKDB_NODE_NS_BEGIN

class Node {

public:
    Node();
    virtual ~Node();

    void Start();

};

SHARKDB_NODE_NS_END

#endif//SHARKDB_NODE_NODE_H
