#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM 7

  typedef struct {

      char*DN;
      int Dt;
      char*Act;
  }DAYTYPE;

  void fnFree(DAYTYPE*);
  void fnDisp(DAYTYPE*);
  void fnRead(DAYTYPE*);
  DAYTYPE*fnCreate();

  int main() {

   DAYTYPE*Cal = fnCreate();

    fnRead(Cal);

    fnDisp(Cal);

    fnFree(Cal);

    return 0;

  }

    DAYTYPE*fnCreate()
    {
      DAYTYPE*c = (DAYTYPE*)malloc(NUM*sizeof(DAYTYPE));

      for(int i=0;i<NUM;i++)
      {
          c[i].DN = NULL;
          c[i].Dt = 0;
          c[i].Act = NULL;
      }
       return c;

    }

    void fnRead(DAYTYPE*c) {
     char Ch;
     for(int i=0;i<NUM;i++) {
        printf("\n do you want to enter details for day %d[Y/N]",i+1);
        scanf("%c",&Ch); getchar();

        if(tolower(Ch)=='n')
            continue;

        printf("Day Name:");
        char nameBuffer[50];
        scanf("%s",nameBuffer);
        c[i].DN = strdup(nameBuffer);

        printf("Date:");
        scanf("%d,&c[i].Dt");

        printf("Activity:");
          char activityBuffer[100];
        scanf("%[^\n]",activityBuffer);
        c[i].Act = strdup(activityBuffer);


        printf("n");
        getchar();

     }

    }


     void fnDisp(DAYTYPE*c) {

     printf("\n Week's Activity Details :\n");
       for(int i=0;i<NUM;i++) {

        printf("Day %d:\n",i+1);
           if(c[i].Dt == 0)
            {
              printf("No Activity\n\n");
                 continue;


            }

          printf("Day Name:%s\n",c[i].DN);
          printf("Date:%d\n",c[i].Dt);
          printf("Activity:%s\n",c[i].Act);

       }

     }

       void fnFree(DAYTYPE*c) {

         for(int i=0;i<NUM;i++){
            free(c[i].DN);
            free(c[i].Act);
         }
          free(c);
       }
