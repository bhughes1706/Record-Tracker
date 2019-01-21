//
// Created by Brian Hughes on 2019-01-20.
//

#include "twelve.h"

int twelve::display() {
    return 0;
}

twelve::twelve(const twelve &) {

}

int twelve::edit() {
    return records::edit();
}

void twelve::display_options() const {
    records::display_options();
}
