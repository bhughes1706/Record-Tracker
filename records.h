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
    int display_options() const;
    void edit_string(int, string);
    void edit_int(int, int);
    string get_artist() const {
        return artist;
    }
    string get_album() const {
        return album;
    }

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
    virtual int edit();
    virtual int display_options() const {
        return info.display_options();
    };
    string get_artist() const {
        return info.get_artist();
    };
    string get_album() const {
        return info.get_album();
    }
    string enter_string();
    int enter_number();

protected:
    //CANNOT allocate memory for this object
    records()=default;
    int edit_object(int);
    record_info info;
};

#endif //RECORD_TRACKER_RECORDS_H