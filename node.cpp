//
// Created by Brian Hughes on 2019-01-18.
//

#include "node.h"

node::node() {

}

node::node(records *) {

}

node::node(const node &) {

}

node::~node() {

}

int node::display_all() const {
    int count = 0;
    if(record)
        count = record->display();
    return next->display_all() + count;
}

int node::edit() {
    return 0;
}

node *& node::get_next() {
    return next;
}


