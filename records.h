// Created by Brian Hughes on 2019-01-18.

#include <cstring>
#include <cctype>
#include <iostream>

#ifndef RECORD_TRACKER_RECORDS_H
#define RECORD_TRACKER_RECORDS_H

using namespace std;

class record_info{
public:
    int display();
    int edit();

protected:
    string catalog_id;
    string artist;
    string album;
    string label;
    string format;
    int rating;
    int released;
    int release_id;
    string collection_folder;
    string date_added;
    string media_condition;
    string sleeve_condition;
    string notes;

    float purchase_price;
    float value;
    bool boxset;
    bool seven;
};

class records {
public:
    virtual int display() = 0; //pure virtual
    virtual~records()=default;
    virtual int edit();
    virtual void display_options() const;
protected:
    //CANNOT allocate memory for this object
    records();
    records(const records &);
    explicit records(struct record_info &);
    int edit_object();
    record_info info;
};

#endif //RECORD_TRACKER_RECORDS_H