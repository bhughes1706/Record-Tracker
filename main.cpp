#include <fstream>
#include "records.h"
#include "main.h"
#include "table.h"
#include "seven.h"
#include "seventy_eights.h"
#include "boxset.h"


int main() {
    int selector;
    char yesno;
    table table;

    cout << "\nThis program tracks the performance of your record collection.";
    /*<< "\nYou must have a Discogs collection to use this program."
    << "\nIf you haven't already, download your Discogs collection via "
    << "\nExport -> Collection -> Export Collection Data"
    << "\nThis should give you a .csv document to work with";*/

    do {
        cout << "\nAre you an existing user? (Y/N): ";
        cin >> yesno; cin.ignore(1000, '\n');
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }

        yesno = (char)toupper(yesno);

        if(yesno == 'Y') {
            if (!load_user(table)) {
                yesno = 'x';
            }
        }
        else if(yesno == 'N') {
            if (!add_user(table))
                yesno = 'x';
        }

    } while (yesno != 'Y' && yesno != 'N');

    do {
        selector = menu();
        switch (selector) {
            case 1: display_all(table); break;
            case 2: edit(table); break;
            case 3: delete_item(table);
            default: break;
        }
    } while(selector != 4);
    return 0;
}

int load_user(table & table){
    ifstream file;
    file.open("users.txt");
    if(file) {
        if (file.peek() == EOF) {
            cout << "\nNo users present.";
            return add_user(table);
        }

        string name, read_name, password, password_entry;
        int tries = 0;

        cout << "\nWhat is your username (must use correct case) // Enter 'test' for test entries: ";
        getline(cin, name);
        if(!check_username(name)) {
            cout << "\nUser name not found.";
        }

        while(getline(file, read_name)) {

            if(read_name == name) {
                getline(file, password);
                while(password != password_entry){
                    cout << "\nWhat is your password? // enter 'password' for test entries: ";
                    getline(cin, password_entry);
                    if(password != password_entry) {
                        ++tries;
                        cout << "\nYou have " << 3 - tries << " attempts left.\n";
                    }
                    if(tries == 3){
                        cout << "\nYou've reached your maximum password attempts.\n";
                        exit(0);
                    }
                }
                return import(name, table);
            }
        }
    }

    else {
        cout << "\nError reading from file";
        exit(EXIT_FAILURE);
    }

    return 0;
}

int add_user(table & table){
    ofstream file;
    file.open("users.txt", ios::app);
    string user;
    string password;

    if(file) {
        while (user.length() < 2) {
            cout << "\nWhat would you like your username to be (at least 2 characters)?: ";
            getline(cin, user);

            if (user.length() != 0) {
                if(!check_username(user)) {
                    while(password.length() < 6) {
                        cout << "What would you like your password to be (at least 6 characters)?: ";
                        getline(cin, password);
                    }
                    file << "\n" << user << "\n" << password;
                }
                else {
                    cout << "\nUsername already exists, choose another.\n";
                    user.clear();
                }
            }
            else
                cout << "Please enter a valid username\n";
        }
    }
    else{
        cout << "\nError reading from file.";
        exit(EXIT_FAILURE);
    }
    file.close();

    string fileName = user + ".txt";
    file.open(fileName);

    if(file)
        return 1;
    else{
        cout << "\nError creating new file for storing information\n";
        exit(EXIT_FAILURE);
    }
}

int menu() {
    int selector;
    do {
        cout << "\n\nWould you like to: \n1) Display entire database"
             << "\n2) Edit current database \n3) Delete current database \n4) Exit\n"
             << "Enter option: ";
        cin >> selector; cin.ignore(1000, '\n');
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            selector = 0;
        }
        if(selector > 4 || selector <= 0)
            cout << "\n\nPlease enter valid number.";
    } while(selector > 4 || selector <= 0);
    return selector;
}

int import(string user, table & table){
   ifstream file;
   file.open(user + ".txt");
   if(file && file.peek() != EOF){
       record_info info;
   }
   else{
       file.open(user + ".csv");
       if(file && file.peek() != EOF){
           record_info info;


       }
       else
           cout << "\nYour library is empty.\n";
   }
   return 1;
}

int display_all(table & table){
    table.display_all();
    return 0;
}

int edit(table & table){
    string name_entry;
    int selector;
    do{
        cout << "\n\nWould you like to: \n1) Add a record manually"
             << "\n2) Edit record in database\n";
        cin >> selector; cin.ignore(1000, '\n');
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        if(selector != 1 && selector != 2){
            cout << "\nPlease enter a valid number.";
        }
    }while(selector == 2 || selector == 1);

    switch(selector){
        case 1: add(table); break;
        case 2: edit(table);
        default: break;
    }
    cout << "\n\nWhat artist would you like to edit?\n";
    cin >> name_entry;
    table.edit(name_entry);
    return 0;
}

int delete_item(table & table){
    string artist, album;
    cout << "\nWhat artists would you like to delete?\n";
    cin >> artist;
    cout << "\nWhat album would you like to delete?\n";
    cin >> album;
    table.delete_node(artist, album);
    return 0;
}

int add(table & table){
    //table.add();
    return 0;
}

int check_username(const string user_new){
    ifstream file;
    file.open("users.txt");
    if(file){
        if(file.peek() == EOF)
            return 1;

        string get_name;
        while(getline(file, get_name)){
            if(user_new == get_name)
                return 1;
        }
    }
  return 0;
}

string cipher(const string){

}