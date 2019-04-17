//
//  LinkedList.h
//  Appdome
//
//  Created by Yigal Omer on 16/04/2019.
//  Copyright © 2019 Yigal Omer. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include "Constants.h"


// The node in the linked list will hold the absolute time in which the timer will be fired
// the order is from the lowest time to the highest
typedef struct {
    int timeToBeFired;
    callback_func hook_cb ;
    callback_func user_cb ;
} DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

void init_linked_list(NODE** head) ;
void print_linked_list(NODE* head) ;

void  push_to_linked_list(NODE** node, DATA data);
void pop_from_linked_list(NODE** head);
void inset_sorted_to_linked_list(NODE** head, DATA data);

#endif /* LinkedList_h */
