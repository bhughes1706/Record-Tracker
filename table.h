//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_LIST_H
#define RECORD_TRACKER_LIST_H

#include "node.h"
#include "records.h"

class table {
public:
    table();
    table(const table &);
    ~table();
    int add(records *&);
    int delete_node(string&, string&);
    int display_all() const;
    int count() const;
    int edit(string);
    int importtxt(string);
    void importtxt_given(string);
    void importcsv();
    int edit(string&, string&);
protected:
    node ** head; //array of LLL
    int index;
    void deleteAll(node *&);
    int add(node *&, records *&);
    void importcsv_given(string);
    int hash(string&);
};


#endif //RECORD_TRACKER_LIST_H