//
// Created by Brian Hughes on 2019-01-18.
//
#include "table.h"

#ifndef RECORD_TRACKER_MAIN_H
#define RECORD_TRACKER_MAIN_H

//prototypes for main.cpp
int menu();
int import(table &);
int display_all(table &);
int edit(table &);
int delete_item(table &);
int add(table &);
int load_user(table &);
int add_user(table &);
int check_username(string);

#endif //RECORD_TRACKER_MAIN_H
