//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_SEVEN_H
#define RECORD_TRACKER_SEVEN_H

#include "records.h"

class seven: public records {
public:
    int display() override {
        return records::display();
    };
    int edit() override;
    int display_options() const override;
};


#endif //RECORD_TRACKER_SEVEN_H
