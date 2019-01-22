//
// Created by Brian Hughes on 2019-01-20.
//

#include "twelve.h"

int twelve::edit() {
    return records::edit();
}

int twelve::display_options() const {
    records::display_options();
    return 0;
}
