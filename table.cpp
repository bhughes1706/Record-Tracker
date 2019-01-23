// This is the table, which is an array of LLL. I'm avoiding templates, because
// I need the practice and I'm a glutton for punishment, apparently

char DELIM = ',';

#include "table.h"
#include <string>
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

    return this->add(head[hash], to_add) ? 1 : 0;
}

int table::add(node *& head, records *& record) {
    node *current = head;

    while (current->get_next() && current->get_next()->get_artist().compare(record->get_artist()) > 0) {
        current = current->get_next();

        node *temp = new node(record);
        if (temp->added()) {
            temp->get_next() = current->get_next();
            current->get_next() = temp;
            return 1;
        } else
            return 0;
    }
    return 0;
}

int table::delete_node(string & artist, string & album) {
    int hash = this->hash(artist);
    node * current = head[hash];

    while(current->get_artist() != artist || current->get_album() != album){
        if(current->get_next())
            current = current->get_next();
        else
            return 0;
    }
    if(this->head[hash] == current){
        if(current->get_next()) {
            head[hash] = current->get_next();
        delete current;
        return 1;
        }
    }

    return 0;
}

table::~table(){
    int i = 0;
    for(; i < index; ++i)
        deleteAll(head[i]);
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

void table::deleteAll(node *& head) {
    if(!head)
        return;
    deleteAll(head->get_next());
    delete head;
}

int table::importtxt(string name) {

    return 0;
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

int table::edit(string & artist, string & album) {
    int hash = this->hash(artist);
    node * current = head[hash];

    while(current->get_artist() != artist || current->get_album() != album){
        if(!current->get_next())
            current = current->get_next();
        else
            return 0;
    }

    return current->edit();
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

int table::hash(string & artist) {
    int total = 0, i = 0;
    //counts each character
    for(; i < artist.length(); ++i){
        artist[i] += total;
    }
    return total % index;
}
