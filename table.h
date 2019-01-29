//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_LIST_H
#define RECORD_TRACKER_LIST_H

#include "node.h"
#include "records.h"
#include <string>
#include <iostream>
#include <fstream>

class table: private boost::noncopyable {
public:
    table();
    table(const table &);
    ~table();
    int add(records *&);
    int delete_node(const std::string&, const std::string&);
    int display_all() const;
    int count() const;
    int edit(std::string);
    int importtxt(std::string);
    void importtxt_given(std::string);
    void importcsv();
    int edit(std::string&, std::string&);
protected:
    node ** head; //array of LLL
    const int index;
    void deleteAll(node *&);
    int add(node *&, records *&);
    void importcsv_given(std::string);
    int hash(const std::string&);
};


#endif //RECORD_TRACKER_LIST_H