//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_NODE_H
#define RECORD_TRACKER_NODE_H


#include "records.h"

class node {
public:
    node();
    explicit node(records *);
    node(const node &);
    ~node();
    int display() const;
    int edit();
    node *& get_next();
protected:
    records * record;//contains transport
    node * next;
};


#endif //RECORD_TRACKER_NODE_H
