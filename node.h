// Nodes for LLLs, contained in table
// Simple functions implemented here, ell else in .cpp


#ifndef RECORD_TRACKER_NODE_H
#define RECORD_TRACKER_NODE_H

#include "records.h"

class node {
public:
    node()=default;
    explicit node(records *);
    explicit node(const node &);
    ~node() {
        record = nullptr;
        next = nullptr;
    };
    int display_all() const;
    node & operator=(const node &);
    int edit() {
        return record->edit();
    };
    node *& get_next() { return next; };
    int count() const;
    int added() const {
        return record ? 1 : 0;
    } //implemented here
    std::string get_artist() const {
        return record->get_artist();
    };
    std::string get_album() const {
        return record->get_album();
    }
protected:
    records * record;//contains transport
    node * next;
};


#endif //RECORD_TRACKER_NODE_H
