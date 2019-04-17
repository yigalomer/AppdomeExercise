# AppdomeExercise
Exercise that implements multi-timer capabilities when only one os time is available

When these following functions are given :

void os_set_timer(unsigned int sec,callback_func cb);

void os_cancel_timer(void);

unsigned int os_get_time(void);

Implement : void os_set_multi_timer(unsigned int sec,callback_func cb);

which will allow to fire multiple timers
