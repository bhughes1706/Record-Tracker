// Created by Brian Hughes on 2019-01-18.

#include "records.h"

records::records() = default;

records::records(record_info & copy){
    info = copy;
}

int records::display(){

}

records::records(const records & copy){
    info = copy.info;
}

int records::edit() {
    return 0;
}

void records::display_options() const {

}

int records::edit_object() {
    return 0;
}
