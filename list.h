//
// Created by Brian Hughes on 2019-01-18.
//

#ifndef RECORD_TRACKER_LIST_H
#define RECORD_TRACKER_LIST_H

#include "node.h"
#include "records.h"

class list {
public:
    list();
    list(const list &);
    ~list();
    int add(records *&);
    int delete_node(char*);
    int deleteAll();
    int display_all() const;
    int compare(char*);
    int count() const;
    int edit(string entry);
    int add();
    int delete_record(string);
    void importtxt();
    void importcsv();
protected:
    node ** head; //array of LLL
    int index;
    int deleteAll(node *&);
    void add_all(const node*, node*&);
    int add(node *&, records *&);
    int delete_node(node *&, char*);
    int compare(node*, char*);
    int count(node * head) const;
    int edit(node *&,char*);
    void importtxt_given(string input);
    void importcsv_given(string input);
    int hash(string);
};


#endif //RECORD_TRACKER_LIST_H
