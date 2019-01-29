#include "main.h"

int main() {
    int selector; //used for user selection in menus
    char yesno; //user entry for yes and no questions
    table table; //creates empty table for filling

    std::cout << "\nThis program tracks the performance of your record collection.";
    /*<< "\nYou must have a Discogs collection to use this program."
    << "\nIf you haven't already, download your Discogs collection via "
    << "\nExport -> Collection -> Export Collection Data"
    << "\nThis should give you a .csv document to work with";*/

    do {
        std::cout << "\nAre you an existing user? (Y/N): ";
        std::cin >> yesno; std::cin.ignore(1000, '\n');
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
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
    std::ifstream file;
    file.open("users.txt");
    if(file) {
        if (file.peek() == EOF) {
            std::cout << "\nNo users present.";
            return add_user(table);
        }

        std::string name, read_name, password, password_entry;
        int tries = 0;

        std::cout << "\nWhat is your username (must use correct case) // Enter 'test' for test entries: ";
        getline(std::cin, name);
        if(!check_username(name)) {
            std::cout << "\nUser name not found.";
        }

        while(getline(file, read_name)) {

            if(read_name == name) {
                getline(file, password);
                while(password != password_entry){
                    std::cout << "\nWhat is your password? // enter 'password' for test entries: ";
                    getline(std::cin, password_entry);
                    if(password != password_entry) {
                        ++tries;
                        std::cout << "\nYou have " << 3 - tries << " attempts left.\n";
                    }
                    if(tries == 3){
                        std::cout << "\nYou've reached your maximum password attempts.\n";
                        exit(0);
                    }
                }
                return import(name, table);
            }
        }
    }

    else {
        std::cout << "\nError reading from file";
        exit(EXIT_FAILURE);
    }

    return 0;
}

int add_user(table & table){
    std::ofstream file;
    file.open("users.txt", std::ios::app);
    std::string user;
    std::string password;

    if(file) {
        while (user.length() < 2) {
            std::cout << "\nWhat would you like your username to be (at least 2 characters)?: ";
            getline(std::cin, user);

            if (user.length() != 0) {
                if(!check_username(user)) {
                    while(password.length() < 6) {
                        std::cout << "What would you like your password to be (at least 6 characters)?: ";
                        getline(std::cin, password);
                    }
                    file << "\n" << user << "\n" << password;
                }
                else {
                    std::cout << "\nUsername already exists, choose another.\n";
                    user.clear();
                }
            }
            else
                std::cout << "Please enter a valid username\n";
        }
    }
    else{
        std::cout << "\nError reading from file.";
        exit(EXIT_FAILURE);
    }
    file.close();

    std::string fileName = user + ".txt";
    file.open(fileName);

    if(file)
        return 1;
    else{
        std::cout << "\nError creating new file for storing information\n";
        exit(EXIT_FAILURE);
    }
}

int menu() {
    int selector;
    do {
        std::cout << "\n\nWould you like to: \n1) Display entire database"
             << "\n2) Edit current database \n3) Delete current database \n4) Exit\n"
             << "Enter option: ";
        std::cin >> selector; std::cin.ignore(1000, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            selector = 0;
        }
        if(selector > 4 || selector <= 0)
            std::cout << "\n\nPlease enter valid number.";
    } while(selector > 4 || selector <= 0);
    return selector;
}

int import(const std::string user, table & table){
   std::ifstream file;
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
           std::cout << "\nYour library is empty.\n";
   }
   return 1;
}

int display_all(table & table){
    table.display_all();
    return 0;
}

int edit(table & table){
    std::string name_entry;
    int selector;
    do{
        std::cout << "\n\nWould you like to: \n1) Add a record manually"
             << "\n2) Edit record in database\n";
        std::cin >> selector; std::cin.ignore(1000, '\n');
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        if(selector != 1 && selector != 2){
            std::cout << "\nPlease enter a valid number.";
        }
    }while(selector != 2 && selector != 1);

    switch(selector){
        case 1: add(table); break;
        case 2: edit(table);
        default: break;
    }
    std::cout << "\n\nWhat artist would you like to edit?\n";
    std::cin >> name_entry;
    table.edit(name_entry);
    return 0;
}

int delete_item(table & table){
    std::string artist, album;
    std::cout << "\nWhat artists would you like to delete?\n";
    std::cin >> artist;
    std::cout << "\nWhat album would you like to delete?\n";
    std::cin >> album;
    table.delete_node(artist, album);
    return 0;
}

int add(table & table){
    //table.add();
    return 0;
}

int check_username(const std::string user_new){
    std::ifstream file;
    file.open("users.txt");
    if(file){
        if(file.peek() == EOF)
            return 1;

        std::string get_name;
        while(getline(file, get_name)){
            if(user_new == get_name)
                return 1;
        }
    }
  return 0;
}