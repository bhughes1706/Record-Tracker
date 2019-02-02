//all simple functions are implemented in .h file

#include "node.h"
#include "twelve.h"
#include "seventy_eights.h"
#include "boxset.h"
#include "seven.h"

node::node(records * new_record) {

}

node::node(const node & copy) {

}

int node::display_all() const {
    int count = 0;
    if(record)
        count = record->display();
    if(next)
        return next->display_all() + count;
    return count;
}

node & node::operator=(const node & copy) {


    return *this;
}

int node::count() const {
    if(!next)
        return 1;
    return next->count() + 1;
}