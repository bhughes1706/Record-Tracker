//all simple functions are implemented in .h file

#include "node.h"
#include "twelve.h"
#include "seventy_eights.h"
#include "boxset.h"
#include "seven.h"

node::node(records * new_record) {
    auto * twelves = dynamic_cast<twelve*>(new_record);
    if(twelves){
        record = twelves;
        return;
    }

    auto * sevens = dynamic_cast<seven*>(new_record);
    if(sevens){
        record = sevens;
        return;
    }

    auto * seven_eight = dynamic_cast<seventy_eights*>(new_record);
    if(seven_eight){
        record = seven_eight;
        return;
    }

    auto * box = dynamic_cast<boxset*>(new_record);
    if(box)
        record = box;
    next = nullptr;
}

node::node(const node & copy) {
    auto * twelves = dynamic_cast<twelve*>(copy.record);
    if(twelves)
        record = twelves;


    auto * sevens = dynamic_cast<seven*>(copy.record);
    if(sevens)
        record = sevens;

    auto * seven_eight = dynamic_cast<seventy_eights*>(copy.record);
    if(seven_eight)
        record = seven_eight;

    auto * box = dynamic_cast<boxset*>(copy.record);
    if(box)
        record = box;

    if(next)
        next = new node(*copy.next);
}

int node::display_all() const {
    int count = 0;
    if(record)
        count = record->display();
    if(next)
        return next->display_all() + count;
    return count;
}

int node::edit() {
    return 0;
}

node & node::operator=(const node & copy) {
    if(!copy.record)
        return *this;

    auto * twelves = dynamic_cast<twelve*>(copy.record);
    if(twelves)
        record = twelves;

    auto * sevens = dynamic_cast<seven*>(copy.record);
    if(sevens)
        record = sevens;

    auto * seven_eight = dynamic_cast<seventy_eights*>(copy.record);
    if(seven_eight)
        record = seven_eight;

    auto * box = dynamic_cast<boxset*>(copy.record);
    if(box)
        record = box;

    if(copy.next)
        next = new node(*copy.next);
    return *this;
}

int node::count() const {
    if(!next)
        return 1;
    return next->count() + 1;
}