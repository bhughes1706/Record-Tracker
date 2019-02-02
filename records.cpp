// Created by Brian Hughes on 2019-01-18.

#include "records.h"


int records::display() const{
    return info.display();
}

int records::edit() {
    display_options();

    int select = 0;
    do{
        std::cout << "What would you like to choose? ";
        std::cin >> select; std::cin.ignore(1000, '\n');
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        if(select > 13 || select < 1)
            std::cout << "\nPlease enter a valid number";
    } while(select > 13 || select < 1);
    return edit_object(select);
}

int records::edit_object(int const select) {
    std::cout << "What would you like the new value of ";
    try{
        switch(select){
            case 1: std::cout << " catalog ID to be? "; return enter_string(select);
            case 2: std::cout << " artist to be? "; return enter_string(select);
            case 3: std::cout << " album to be? "; return enter_string(select);
            case 4: std::cout << " label to be? "; return enter_string(select);
            case 5: std::cout << " format to be? "; return enter_string(select);
            case 6: std::cout << " rating to be? "; return enter_number(select);
            case 7: std::cout << " release date to be? "; return enter_number(select);
            case 8: std::cout << " release ID to be? "; return enter_number(select);
            case 9: std::cout << " folder to be? "; return enter_string(select);
            case 10: std::cout << " date added to be? "; return enter_string(select);
            case 11: std::cout << " media condition to be? "; return enter_string(select);
            case 12: std::cout << " sleeve condition to be? "; return enter_string(select);
            case 13: std::cout << " notes to be? "; return enter_string(select);
            default: throw select;
        }
    }
    catch(int e){
        std::cout << "\nError: option " << e << " not found in edit_object.";
        return 0;
    }
}

int records::enter_string(int const select) {
    std::string str_entry;
    getline(std::cin, str_entry);
    return info.edit_string(select, str_entry);
}

int records::enter_number(int const select) {
    int entry = 0;
    while(entry == 0) {
        std::cin >> entry;
        std::cin.ignore(1000, '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nPlease enter valid number.\n";
            entry = 0;
        }
    }
    return info.edit_int(select, entry);
}

records::records(const record_info & entry): info(entry){}


int record_info::display() const {
    std::cout << "\n\nCatalog ID: " << catalog_id
         << "\nArtist: " << artist << "\nAlbum: " << album
         << "\nLabel: " << label << "\nFormat: " << format
         << "\nRating: " << rating << "\nReleased: " << released
         << "\nRelease ID: " << release_id << "\nFolder: " << collection_folder
         << "\nDate Added: " << date_added << "\nMedia Condition: "
         << media_condition << "\nSleeve Condition: " << sleeve_condition
         << "\nNotes: " << sleeve_condition << "\n";
    return 1;
}

int record_info::edit_int(const int select, const int entry) {
    try{
        switch(select){
            case 6: rating = entry; return 1;
            case 7: released = entry; return 1;
            case 8: release_id = entry; return 1;
            default: throw select;
        }
    }
    catch(int e){
        std::cout << "\nError: option " << e << " not found in edit_int in record_info\n";
        return 0;
    }
}

int record_info::edit_string(const int select, const std::string entry) {
    try{
        switch(select){
            case 1: catalog_id = entry; return 1;
            case 2: artist = entry; return 1;
            case 3: album = entry; return 1;
            case 4: label = entry; return 1;
            case 5: catalog_id = entry; return 1;
            case 9: collection_folder = entry; return 1;
            case 10: date_added = entry; return 1;
            case 11: media_condition = entry; return 1;
            case 12: sleeve_condition = entry; return 1;
            case 13: notes = entry; return 1;
            default: throw select;
        }
    }
    catch (int e){
        std::cout << "\nError: option " << e << " not found in edit_string in record_info\n";
        return 0;
    }
}

void record_info::display_options() const {
    std::cout << "\n1) Catalog ID: " << catalog_id
         << "\n2) Artist: " << artist << "\n3) Album: " << album
         << "\n4) Label: " << label << "\n5) Format: " << format
         << "\n6) Rating: " << rating << "\n7) Released: " << released
         << "\n8) Release ID: " << release_id << "\n9) Folder: " << collection_folder
         << "\n10) Date Added: " << date_added << "\n11) Media Condition: "
         << media_condition << "\n12) Sleeve Condition: " << sleeve_condition
         << "\n13) Notes: " << sleeve_condition << "\n";
}
