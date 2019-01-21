//
// Created by Brian Hughes on 2019-01-18.
//

#include "node.h"
#include "twelve.h"
#include "seventy_eights.h"
#include "boxset.h"
#include "seven.h"

node::node() {
    record = nullptr;
    next = nullptr;
}

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

}

node::~node() {
    delete record;
    delete next;
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

node *& node::get_next() {
    return next;
}

node & node::operator=(const node & copy) {
    if(!copy.record)
        return *this;

    delete record;
    delete next;

    record = copy.record;
    next = copy.next;
    return *this;
}

int node::count() const {
    if(!next)
        return 1;
    return next->count() + 1;
}


int node::add(records *& to_add) {
    int result = 0;
    node * current = this;
    node * previous = nullptr;

    while(result > 0) {
        result = to_add->get_artist().compare(record->get_artist());
        if(result > 0 && next){
            previous = current;
            current = next;
        }
        else{
            node * temp = new node(to_add);
            temp->next = current->next;
            current->next = temp;
            if(previous)
                previous->next = current;
        }
    }
    return result;
}


