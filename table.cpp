//
// This is the table, which is a array of LLL. I'm avoiding templates, because
// I need the practice and I'm a glutton for punishment, apparently

char DELIM = ',';

#include "table.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

table::table(){
    index = 29;
    head = new node * [index];
    for(int i = 0; index > i; ++i)
        head[i] = nullptr;
}

table::table(const table & copy) {
    index = copy.index;
    head = new node * [index];
    for(int i = 0; index > i; ++i)
        head[i] = copy.head[i];
}

int table::add(records *& to_add) {
    string artist = to_add->get_artist();
    int hash = this->hash(artist);

    if(!head[hash]) {
        head[hash] = new node(to_add);
        return 1;
    }

    if(head[hash]->add(to_add))
        return 1;
    return 0;
}

int table::delete_node(char *) {
    return 0;
}

int table::deleteAll() {
    return 0;
}

table::~table(){
    int i = 0;
    for(; i < index; ++i)
        delete head[i];
}

int table::display_all() const {
    if(!head)
      return 0;
    int count = 0;
    for(int i = 0; i < index; ++i) {
        if(head[i])
            count += head[i]->display_all();
    }
    return count;
}

int table::compare(char *) {
    return 0;
}

int table::count() const {
    int count = 0, i = 0;
    for(; i < index; ++i) {
        if(head[i])
            count += head[i]->count();
    }
    return count;
}

int table::edit(string entry) {
    return 0;
}

int table::deleteAll(node *&) {
    if(!head)
        return 0;
    //deleteAll(head->get_next());
    return 0;
}

void table::add_all(const node *, node *&) {

}

int table::add(node *&, records *&) {
    return 0;
}

int table::delete_node(node *&, char *) {
    return 0;
}

int table::compare(node *, char *) {
    return 0;
}

int table::count(node *head) const {
    return 0;
}

int table::add() {
    return 0;
}

int table::delete_record(string) {
    return 0;
}

void table::importtxt() {
  string input;
  cout << "\nRemember to keep style: catalog_id, artist, album, label\n"
       << "format, rating, released, release_id, collection_folder, date_added\n"
       << "media_condition, sleeve_condition, and notes\n"
       << "Everything should be on a new line. Format should be 2xLP, LP, 78, box, or 7.\n"
       << "What is the .txt path file on your computer? ";
  getline(cin, input);

  importtxt_given(input);
}

void table::importcsv() {
    string input;
    cout << "\nRemember to keep style: catalog_id, artist, album, label\n"
         << "format, rating, released, release_id, collection_folder, date_added\n"
         << "media_condition, sleeve_condition, and notes\n"
         << "Everything should be on a new line. Format should be 2xLP, LP, 78, box, or 7.\n"
         << "What is the .csv path file on your computer? ";
    getline(cin, input);

    //importcsv_given(input);

    importcsv_given("record_collection.csv");
}

void table::importtxt_given(string input) {

}

int table::edit(node *&, char *) {
    return 0;
}

void table::importcsv_given(string input) {
    if(input.empty())
        return;
    ifstream file;
    file.open(input);
    string temp;

    if(file){
        getline(file, temp, DELIM);
    }
}

int table::hash(string artist) {
    int total = 0, i = 0;
    //counts each character
    for(; i < artist.length(); ++i){
        artist[i] += total;
    }
    return total % index;
}
