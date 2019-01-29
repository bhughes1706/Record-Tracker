//
// Created by Brian Hughes on 2019-01-20.
//

#ifndef RECORD_TRACKER_TWELVE_H
#define RECORD_TRACKER_TWELVE_H

#include "records.h"

class twelve: public records {
public:
    int display() const override {
        return records::display();
    };
    int edit() override;
    void display_options() const override;
};


#endif //RECORD_TRACKER_TWELVE_H
