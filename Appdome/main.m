//
//  main.m
//  Appdome
//
//  Created by Yigal Omer on 16/04/2019.
//  Copyright © 2019 Yigal Omer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#include "OSTimer.h"
#include "LinkedList.h"



void timer_fired1() {
    printf("*** User CB fired1\n");
}
void timer_fired2() {
    printf("*** User CB fired2\n");
}
void timer_fired3() {
    printf("*** User CB fired3\n");
}

NODE* linked_list_head = NULL;

int main(int argc, char * argv[]) {
    
    os_get_time();
    
    init_linked_list(&linked_list_head);

    os_set_multi_timer(10,timer_fired1);
    
    sleep(1);
    
    os_set_multi_timer(2,timer_fired2);
    
    sleep(1);
    
    os_set_multi_timer(6,timer_fired3);
    
    //print_linked_list( linked_list_head) ;
    
  
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}


