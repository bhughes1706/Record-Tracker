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
    int compare_id(records *);
    int compare_id(char *);
    int display() const;
    int service() const;
    int edit();
protected:
    records * record;//contains transport
};


#endif //RECORD_TRACKER_NODE_H
