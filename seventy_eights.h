//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_SEVENTY_EIGHTS_H
#define RECORD_TRACKER_SEVENTY_EIGHTS_H

#include "records.h"

class seventy_eights: public records {
    int display() const override {
        return records::display();
    };
    int edit() override;
    void display_options() const override;
};


#endif //RECORD_TRACKER_SEVENTY_EIGHTS_H
