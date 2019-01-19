//
// Created by Brian Hughes on 2019-01-18.
//

#include "list.h"

list::list() =default;

list::list(const list &) {

}

int list::add(records *&) {
    return 0;
}

int list::delete_node(char *) {
    return 0;
}

int list::deleteAll() {
    return 0;
}

list::~list()=default;

int list::display() const {
    if(!head)
      return 0;
    return head->display();
}

int list::compare(char *) {
    return 0;
}

int list::count() const {
    return 0;
}

int list::edit(string entry) {
    return 0;
}

int list::deleteAll(node *&) {
    if(!head)
        return 0;
    deleteAll(head->get_next());
    return 0;
}

void list::add_all(const node *, node *&) {

}

int list::add(node *&, records *&) {
    return 0;
}

int list::delete_node(node *&, char *) {
    return 0;
}

int list::display(const node *, int) const {
    return 0;
}

int list::compare(node *, char *) {
    return 0;
}

int list::count(node *head) const {
    return 0;
}

int list::add() {

    return 0;
}