#include "SongsHeaderFile.h"

int main()
{
    START:
    printf("****************************************************************************\n");
    printf("*                               ****************                           *\n");
    printf("*                               *SONGS DATABASE*                           *\n");
    printf("*                               ****************                           *\n");
    printf("****************************************************************************\n\n\n");
    printf("----------------------------------------------------------------------------\n");
    printf("|                                   MAIN MENU                              |\n");
    printf("----------------------------------------------------------------------------\n\n\n");
    printf("\t   1.Search a song\n");
    printf("\t   2.Add a song\n");
    printf("\t   3.List all songs\n");
    printf("\t   4.Create a new Database for songs (only use this if Database Doesn't exist)\n");
    printf("\t   5.List Popular Songs\n");
    printf("\t   6.Get a song Recommendation\n");
    printf("\t   7.Exit\n\n");
    printf("_____________________________________________________________________________\n\n");
    printf("\t   Enter your choice(1-7):");
    int choice=0,n=0;
    do
        {
            scanf("%d",&choice);
        if((choice<8) && (choice>0))
        {
            n=choice;
        }
        else
        {
            printf("\n\n\tInvalid choice!! Enter again(1-7):");
        }}
    while((choice>=8) || (choice<=0));
    char option;
    choice=0;
    clrscr();
    switch(n)
    {
        case 1:
            printf("---------------------------------------------------------------------------\n");
            printf("|                                 Song Search Menu                        |\n");
            printf("---------------------------------------------------------------------------\n\n\n");
            printf("    1.Search by Title\n");
            printf("    2.Search by Artist\n");
            printf("    3.Search by Album\n");
            printf("    4.Search by Genre\n");
            printf("    5.Search by Release Year\n");
            printf("    6.Search by Duration\n");
            printf("    7.Search by Rating\n\n");
            printf("    Enter your choice(1-7):");
            int m;
            do
            {
                scanf("%d",&choice);
                if((choice<8) && (choice>0))
                {
                    m=choice;
                }
                else
                {
                    printf("\n\n    Wrong choice!! Please Enter again(1-7) ");
                }}
            while((choice<=0) || (choice>=8));
            getchar();
            SONG_SEARCH(m);
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            scanf("%c",&option);
            if(option== 'y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;

            break;
        case 2:
            printf("---------------------------------------------------------------------------\n");
            printf("|                                Song Entry Portal                        |\n");
            printf("---------------------------------------------------------------------------\n\n\n");
            SONG_ENTRY();
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            scanf("%c",&option);
            if(option== 'y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;
            break;
        case 3:
            DISPLAY_DATABASE();
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            getchar();
            option=getchar();
            if(option=='y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;
            break;
        case 4:
            NEW_DATABASE();
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            getchar();
            option=getchar();
            if(option=='y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;
            break;
        case 5:
            POPULAR_SONGS();
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            scanf("%c",&option);
            if(option=='y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;
            break;
        case 6:
            getchar();
            SONG_RECOMMENDATION();
            printf("\n\n\tDo you want to go to MAIN MENU? [Y/N]");
            scanf("%c",&option);
            if(option=='y'||option=='Y')
                {
                clrscr();
                goto START;
                }
            else if(option=='n'||option=='N')
                {printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");
                }}
                option=0;
            break;
        case 7:
            printf("\n\n\tTerminating the Program");
                for(int sec=1000;sec>100;sec=sec-300)
                {
                    delay(sec);
                    printf(".");}
            exit(0);
            break;
    }

}
