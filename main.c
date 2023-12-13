//   CCCCCCC  LL        OOOO        CCCCCCCC  KK  KK
//  CCC       LL       OO   OO     CCC        KK KK
// CCC        LL      OO     OO   CCC         KKK
// CCC        LL      OO     OO   CCC         KKK
//  CCC       LL       OO   OO     CCC        KK KK
//   CCCCCCC  LLLLLLL   OOOO        CCCCCCCC  KK  KK
//
// by Darwin Zmugg

#include <stdio.h>
#include "conf.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int timer() {
    int inter;
    scanf("%d", &inter);
    if (inter < 1) {
        printf(ANSIRED"Argument too small\n"ANSIRESET);
    } else {
        while (inter != 0) {
            printf("\r%d", inter);
            fflush(stdout);
            sleep(1);
            --inter;
            if (inter == 0) {
                printf("\n");
            } else {
                continue;
            }
        }
    }
    return 0;
}

int stopwat() {
    struct termios oldt, newt;
    char ch;
    int oldf;
    int count = 0;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    while ((ch = getchar()) != 27) {  // 27 is the ASCII value of ESC
        
        printf("%d\n", count);
        sleep(1);
        count++;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
}

int alarmclock () {
    unsigned int hour;unsigned int min;char message[99];
    //scanf("When do you want to be waken?(hour/minutes + message) %d/%d + %s", &hour, &min, &message);
    int status = system("* %d * * * /path/to/command >> /tmp/crontab_new");
    return 0;
}

int option() {
    return 0;
}

int main () {
 int chosen;  
 printf(ANSICYAN"%s"ANSIRESET,welcMess);
 do
 {
 printf(ANSIMAGENTA"\n\n\n1. Timer\n2. Stopwatch\n3. Alarm clock\n4. Option\n5. Exit\n\n\n"ANSIRESET);
 scanf("%d", &chosen);
 } while (chosen < 1 || chosen > 5);
 switch (chosen)
 {
 case 1:
    timer();
    break;
 case 2:
 stopwat();
 break;
 case 3:
 alarmclock();
 break;
 case 4:
 option();
 case 5:
 break;
 }
 return 0;
}
