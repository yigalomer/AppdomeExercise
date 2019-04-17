//
//  OSTimer.h
//  Appdome
//
//  Created by Yigal Omer on 16/04/2019.
//  Copyright © 2019 Yigal Omer. All rights reserved.
//

#ifndef OSTimer_h
#define OSTimer_h

#include <stdio.h>
#include <time.h>
#include "Constants.h"

void os_set_timer(unsigned int sec,callback_func cb);

void os_cancel_timer(void);

unsigned int os_get_time(void);


void os_set_multi_timer(unsigned int sec,callback_func cb);

#endif /* OSTimer_h */
