//
//  OSTimer.c
//  Appdome
//
//  Created by Yigal Omer on 16/04/2019.
//  Copyright © 2019 Yigal Omer. All rights reserved.
//

#include "OSTimer.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

#include "LinkedList.h"

extern NODE* linked_list_head ; //defined in main.c, represent out linked list

void os_set_timer(unsigned int sec, callback_func cb){
    
    if (sec == 0 ) {
        printf("os_set_timer - canceling timer\n");
    }
    else{
        printf("os_set_timer starting timer for %d seconds\n" ,sec);
    }

    struct itimerval it_val;
    
    it_val.it_value.tv_sec = sec;
    it_val.it_value.tv_usec = 0;
    it_val.it_interval.tv_sec = 0;
    it_val.it_interval.tv_usec = 0;
    
    if (cb && signal(SIGALRM, (callback_func_for_signal)cb) == SIG_ERR) {
        perror("Unable to catch SIGALRM");
        exit(1);
    }
    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }
}

void os_cancel_timer(void){
    
    printf("canceling timer\n");
    os_set_timer(0,NULL);
}

unsigned int os_get_time(void){
    
    unsigned int now = (unsigned int)time(0);
    printf("os_get_time now = %u\n",now);
    return now;
}




// the hook callback
void my_callback(){
    
    printf("my_callback fired! \n");

    if( !linked_list_head) return ;
    
    // in the hook callback, we first call the actual user cb
    linked_list_head->data.user_cb() ;
    
    // then handle the next elemnt in the list and fire a timer with the diff time
    if (  linked_list_head->next != NULL ){
        os_set_timer(linked_list_head->next->data.timeToBeFired - linked_list_head->data.timeToBeFired,my_callback) ;
    }
    // get rid of the head
    pop_from_linked_list(&linked_list_head);
    
}

void os_set_multi_timer(unsigned int sec,callback_func cb) {
    
    printf("os_set_multi_timer - starting timer for %u seconds\n" ,sec);
    
    unsigned int now = (unsigned int)os_get_time() ;
    unsigned int absolute_time_to_fire_timer = now + sec ;
    
    DATA element;
    element.timeToBeFired = absolute_time_to_fire_timer ;
    element.hook_cb = my_callback ;
    element.user_cb = cb;
    
    // Empty list
    if ( linked_list_head == NULL) {
        
        push_to_linked_list(&linked_list_head, element);
        os_set_timer(sec,my_callback) ;
    }
    // if the new timer is erlier than the lowest timer(head), then:
    // 1. cancel the current timer
    // 2. push it to the head of the list
    // 3. set a new timer
    else if (absolute_time_to_fire_timer < linked_list_head->data.timeToBeFired   ) {
        
        os_cancel_timer() ;
        push_to_linked_list(&linked_list_head, element);
        os_set_timer(sec,my_callback) ;
    }
    // if the new timer is later than lowest timer(head), just
    // insert the element to the correct place in the list
    else if (absolute_time_to_fire_timer > linked_list_head->data.timeToBeFired  ) {
        
        inset_sorted_to_linked_list(&linked_list_head, element);
    }
    
    print_linked_list( linked_list_head) ;
}



