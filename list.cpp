//
// Created by Brian Hughes on 2019-01-18.
//

#include "list.h"
#include <string>
#include <iostream>
using namespace std;

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

int list::display_all() const {
    if(!head)
      return 0;
    int count = 0;
    count = head->display_all();
    return head->get_next()->display_all() + count;
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

int list::compare(node *, char *) {
    return 0;
}

int list::count(node *head) const {
    return 0;
}

int list::add() {
    return 0;
}

int list::delete_record(string) {
    return 0;
}

void list::importtxt() {
  string input;
  cout << "\nRemember to keep style: catalog_id, artist, album, label\n"
       << "format, rating, released, release_id, collection_folder, date_added\n"
       << "media_condition, sleeve_condition, and notes\n"
       << "Everything should be on a new line. Format should be 2xLP, LP, 78, box, or 7.\n"
       << "What is the .txt path file on your computer? ";
  getline(cin, input);

  importtxt_given(input);
}

void list::importcsv() {

}

void list::importtxt_given(string input) {
  if(input.length() == 0)
      return;


}

int list::edit(node *&, char *) {
    return 0;
}
