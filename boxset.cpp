//
// Created by Brian Hughes on 2019-01-18.
//

#include "boxset.h"

int boxset::display() {
    records::display();
    return 0;
}

int boxset::edit() {
    return 0;
}

void boxset::display_options() const {

}

boxset::boxset(const boxset & boxset) {
    info = boxset.info;
}
