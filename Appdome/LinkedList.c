//
//  LinkedList.c
//  Appdome
//
//  Created by Yigal Omer on 16/04/2019.
//  Copyright © 2019 Yigal Omer. All rights reserved.
//

#include "LinkedList.h"


#include <stdio.h>
#include <stdlib.h>


void init_linked_list(NODE** _head) {
    *_head = NULL;
}

void print_linked_list(NODE * _head) {

    printf("Print list\n");
    NODE * current = _head;
    
    while (current != NULL) {
        printf("Node : aabsolut time to fire %d \n", current->data.timeToBeFired);
        current = current->next;
    }
}

void push_to_linked_list(NODE** _head, DATA data) {
    
    printf("push_to_linked_list absolute time :  %d seconds\n" ,data.timeToBeFired);
    NODE* new_node;
    new_node = malloc(sizeof(NODE));
    
    if (*_head == NULL) {
        *_head = new_node ;
        (*_head)->data = data;
        return ;//*_head;
    }
    new_node->data = data;
    new_node->next = *_head;
    *_head = new_node;
}

void pop_from_linked_list(NODE** _head) {
    
    NODE* next_node = NULL;
    
    if (_head == NULL) {
        return;
    }
    next_node = (*_head)->next;
    free(*_head);
    *_head = next_node;
    
}


void inset_sorted_to_linked_list(NODE** _head, DATA data){
    
    printf("inset_sorted_to_linked_list absolute time :  %d seconds\n" ,data.timeToBeFired);
    
    NODE* current = *_head;
    NODE* current_prev = *_head;

    while (current != NULL) {

        if (data.timeToBeFired < (int)current->data.timeToBeFired ){

            NODE* newNode = (NODE*) malloc(sizeof (NODE));

            printf("inset_sorted_to_linked_list -  insert not at head\n");

            newNode->data = data;
            newNode->next = current_prev->next;
            current_prev->next = newNode;

            break;
        }
        current_prev = current ;
        current = current->next;
        

    }
}

