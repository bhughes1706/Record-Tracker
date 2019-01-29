// This is the table, which is an array of LLL. I'm avoiding templates, because
// practice is good and I'm a glutton for punishment, apparently

char DELIM = ',';

#include "table.h"

table::table(): index(29) {
    head = new node * [index];
    for(int i = 0; index > i; ++i)
        head[i] = nullptr;
}

//adds one record to table 'collection'
//wrapper for protected recursive fx
int table::add(records *& to_add) {
    std::string artist = to_add->get_artist();
    int hash = this->hash(artist);

    if(!head[hash]) {
        head[hash] = new node(to_add);
        return 1;
    }

    return this->add(head[hash], to_add) ? 1 : 0;
}

//caller: table::add(records *&)
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

//deletes one node in table
int table::delete_node(const std::string & artist, const std::string & album) {
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

//dtor
table::~table(){
    int i = 0;
    for(; i < index; ++i)
        deleteAll(head[i]);
}

//displays all, returns count of all displayed
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

//returns total number of records
int table::count() const {
    int count = 0, i = 0;
    for(; i < index; ++i) {
        if(head[i])
            count += head[i]->count();
    }
    return count;
}

int table::edit(std::string entry) {
    return 0;
}

void table::deleteAll(node *& head) {
    if(!head)
        return;
    deleteAll(head->get_next());
    delete head;
}

int table::importtxt(std::string name) {

    return 0;
}

// // // in dev
void table::importcsv() {
    std::string input;
    std::cout << "\nRemember to keep style: catalog_id, artist, album, label\n"
         << "format, rating, released, release_id, collection_folder, date_added\n"
         << "media_condition, sleeve_condition, and notes\n"
         << "Everything should be on a new line. Format should be 2xLP, LP, 78, box, or 7.\n"
         << "What is the .csv path file on your computer? ";
    getline(std::cin, input);

    //importcsv_given(input);

    importcsv_given("record_collection.csv");
}

// // in dev
void table::importtxt_given(std::string input) {

}

//edits one record, returns callee
int table::edit(std::string & artist, std::string & album) {
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

// // in dev
void table::importcsv_given(std::string input) {
    if(input.empty())
        return;
    std::ifstream file;
    file.open(input);
    std::string temp;

    if(file){
        getline(file, temp, DELIM);
    }
}

//hash function, called by multiple functions
int table::hash(const std::string & artist) {
    int total = 0, i = 0;
    //counts each character
    for(; i < artist.length(); ++i){
        total = artist[i];
    }
    return total % index;
}
