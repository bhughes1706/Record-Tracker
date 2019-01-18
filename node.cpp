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

int node::display() const {
    if(record)
        return record->display();
    return 0;
}

int node::edit() {
    return 0;
}


