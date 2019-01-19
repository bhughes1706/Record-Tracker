//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_BOXSET_H
#define RECORD_TRACKER_BOXSET_H


#include "records.h"

class boxset: public records {
public:
    int display() override;
    boxset(const boxset &);
    int edit() override;
    void display_options() const override;
protected:
    int no_records;
};


#endif //RECORD_TRACKER_BOXSET_H
