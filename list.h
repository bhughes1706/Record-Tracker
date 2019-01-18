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
    int display() const;
    int compare(char*);
    int count() const;
    int edit(char*);
protected:
    node * head;//beginning of DLL
    int deleteAll(node *&);
    void add_all(const node*, node*&);
    int add(node *&, records *&);
    int delete_node(node *&, char*);
    int display(const node *, int) const;
    int compare(node*, char*);
    int count(node * head) const;
    int edit(node *&,char*);
};


#endif //RECORD_TRACKER_LIST_H
