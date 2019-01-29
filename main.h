#include "table.h"
#include "seven.h"
#include "seventy_eights.h"
#include "boxset.h"

#ifndef RECORD_TRACKER_MAIN_H
#define RECORD_TRACKER_MAIN_H

//prototypes for main.cpp
int menu();
int import(std::string, table &);
int display_all(table &);
int edit(table &);
int delete_item(table &);
int add(table &);
int load_user(table &);
int add_user(table &);
int check_username(std::string);

#endif //RECORD_TRACKER_MAIN_H
