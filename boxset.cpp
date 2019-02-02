//
// Created by Brian Hughes on 2019-01-18.
//

#include "boxset.h"

int boxset::edit() {
    records::display_options();
    return 0;
}

void boxset::display_options() const {

}

boxset::boxset(const int box_num, const record_info entry): records(entry) {

}

