// Created by Brian Hughes on 2019-01-18.

#include <cstring>
#include <cctype>
#include <iostream>

#ifndef RECORD_TRACKER_RECORDS_H
#define RECORD_TRACKER_RECORDS_H

#include <boost/noncopyable.hpp>

//record_info definitions are found in records.cpp
class record_info{
public:
    int display() const;
    void display_options() const;
    int edit_string(int, std::string);
    int edit_int(int, int);
    const std::string get_artist() const {
        return artist;
    }
    const std::string get_album() const {
        return album;
    }


private:
    std::string catalog_id;
    std::string artist;
    std::string album;
    std::string label;
    std::string format;
    int rating;
    int released;
    int release_id;
    std::string collection_folder;
    std::string date_added;
    std::string media_condition;
    std::string sleeve_condition;
    std::string notes;

    float purchase_price;
    float value;
    bool boxset;
    bool seven;
};

class records: private boost::noncopyable {
public:
    virtual int display()const=0; //pure virtual
    virtual int edit();
    virtual void display_options() const {
        info.display_options();
    };
    std::string get_artist() const {
        return info.get_artist();
    };
    std::string get_album() const {
        return info.get_album();
    }
    int enter_string(int);
    int enter_number(int);
    explicit records(const record_info &);

private:
    //can only create object by above method
    records()=default;
    int edit_object(int);
    record_info info;
};

#endif //RECORD_TRACKER_RECORDS_H