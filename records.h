// Created by Brian Hughes on 2019-01-18.

#include <cstring>
#include <cctype>
#include <iostream>

#ifndef RECORD_TRACKER_RECORDS_H
#define RECORD_TRACKER_RECORDS_H

using namespace std;

struct record_info{
protected:
    int year;
    float purchase_price;
    float value;
    bool boxset;
    bool seven;
    string artist;
    string album;
};

class records {
    virtual int display() = 0; //pure virtual
    records(const records &);
    virtual int edit();
    virtual void display_options() const;
protected:
    //CANNOT allocate memory for this object
    records();
    explicit records(struct record_info &);
    int edit_object();
    record_info info;
};

#endif //RECORD_TRACKER_RECORDS_H