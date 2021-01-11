#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
typedef struct songs //This data structure is responsible for the input of data in the database//
{                    //This will also help in reading data from the files during search operations//
    char name;
    char artist;
    char album;
    char genre;
    char year;
    char duration;
    char rating;
}s;
void clrscr()       //this function simplifies the syntax for clear screen a bit for the coder//
{
    system("cls");
};
void delay(int millisec)    //This function uses built in clock to count the time elapsed and it is used in between statements//
{                           //to make the execution look smoother//
    clock_t start=clock();
    while(clock()<start+millisec);
}
void SONG_ENTRY()                   //This function is used for entering a new song in the existing database//
{
    struct songs s;
    char temp;        //this variable will temporarily hold the input character//
    FILE *fp;                           //file pointer is declared and the file is opened in a+ mode//
    fp=fopen("Songs.txt","a+");         // with append plus mode we can enter data in the file without//
    if(fp==NULL)                        //losing our previous data in the file//
    {
        printf("\n  Database does not exist.\n");
    }
    else
    getchar();
    printf("\n  Enter Title of the song : ");
    while((s.name=getchar())!='\n')                 //the parameters are taken from the user character by character//
    {                                               //the input will only terminate with a new line character i.e when//
        temp=tolower(s.name);                       //user hits the ENTER button//
        fputc(temp,fp);                             //as the characters are entered they're converted into lower case for the//
    }                                               //ease of operation, already lowercase entries stay in lowercase//
    fprintf(fp," | ");
    printf("\n  Enter Artist of the song : ");
    while((s.artist=getchar())!='\n')
    {
        temp=tolower(s.artist);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n  Enter Album of the song : ");
    while((s.album=getchar())!='\n')
    {
        temp=tolower(s.album);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n  Enter Genre of the song : ");
    while((s.genre=getchar())!='\n')
    {
        temp=tolower(s.genre);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n  Enter Release Year of the song : ");
    while((s.year=getchar())!='\n')
    {
        temp=tolower(s.year);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n  Enter Duration of the song (format mins:sec) : ");
    while((s.duration=getchar())!='\n')
    {
        temp=tolower(s.duration);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n  Enter Rating of the song(0.0-5.0) : ");
    while((s.rating=getchar())!='\n')
    {
        temp=tolower(s.rating);
        fputc(temp,fp);
    }
    fprintf(fp," |");
    fprintf(fp,"\n");
    fclose(fp);
}
void DISPLAY_DATABASE()         //this function loads the database check for its status if it exists or not//
{
    char temp;                  //in case of presence of database, it prints all the available contents to console screen//
    FILE *fp;
    fp=fopen("Songs.txt","r");
    if(fp==NULL)
    {
        printf("\nDatabase does not exist\n");
    }
    else
        printf("\n\n\t\t\tLoading Database");
    for(int sec=1000;sec>100;sec=sec-300)                   //This will add delays in printing the database on screen giving//
     {                                                      //animation effect//
         delay(sec);
         printf(".");
     }
     delay(500);
     clrscr();
    printf("\n\n\n");
    while(!feof(fp))
    {
        delay(30);
        temp=fgetc(fp);
        if(temp=='\n')
            printf("\n");
        printf("%c",temp);
    }
    fclose(fp);
    }
void NEW_DATABASE()                         //This function makes a new database and saves it into the memory//
{                                    //if database is already present with the code it will not proceed, because in that case//
    FILE *fp;                        //file will be recreated and data will be overwritten//
    fp=fopen("Songs.txt","r");       //so we only use this function if database is not present//
    if(fp!=NULL)                    //in case database already exists it terminates the file pointer//
        {
        printf("\nDatabase already exist\n");
        fclose(fp);
        }
    else
    {
    struct songs s;
    char temp;
    fp=fopen("Songs.txt","r");
    printf("/n/n\t   Enter Contents of Database/n/n");
    getchar();
    printf("\n\t  Enter Title of the song : ");
    while((s.name=getchar())!='\n')
    {
        temp=tolower(s.name);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Artist of the song : ");
    while((s.artist=getchar())!='\n')
    {
        temp=tolower(s.artist);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Album of the song : ");
    while((s.album=getchar())!='\n')
    {
        temp=tolower(s.album);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Genre of the song : ");
    while((s.genre=getchar())!='\n')
    {
        temp=tolower(s.genre);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Release Year of the song : ");
    while((s.year=getchar())!='\n')
    {
        temp=tolower(s.year);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Duration of the song (format mins:sec) : ");
    while((s.duration=getchar())!='\n')
    {
        temp=tolower(s.duration);
        fputc(temp,fp);
    }
    fprintf(fp," | ");
    printf("\n\t  Enter Rating of the song(0.0-5.0) : ");
    while((s.rating=getchar())!='\n')
    {
        temp=tolower(s.rating);
        fputc(temp,fp);
    }
    fprintf(fp," |");
    fprintf(fp,"\n");
    fclose(fp);}
}
int SONG_SEARCH(int choice)                  //This program loads the database into the memory and search for the given parameters//
{
     struct songs s;
     int i=0,m=0,op=0;                   //variables declaration & initialization//
     char *mysearch=NULL;           //character pointers that will take and store the strings from user and database respectively//
     char *mydata=NULL;
     char data;
     mysearch=(char*)malloc(i*sizeof(char)); //allocating memory to the pointers//
     mydata=(char*)malloc(m*sizeof(char));
     FILE *fp;                              //opening the file//
     fp=fopen("Songs.txt","r");
     if(fp==NULL)                           //checking null//
     {
         printf("\n\nDatabase does not exist\n\n");
     }
     switch(choice)                         //upon the user request the function will behave accordingly and ask for what user
     {                                      //wished to enter but in the back end performs the same search operation
     case 1:
        printf("\n\n\tEnter Title of song: ");
        break;
     case 2:
        printf("\n\n\tEnter Artist of song: ");
        break;
     case 3:
        printf("\n\n\tEnter Album of song: ");
        break;
     case 4:
        printf("\n\n\tEnter Genre of song: ");
        break;
     case 5:
        printf("\n\n\tEnter Release Year of song: ");
        break;
     case 6:
        printf("\n\n\tEnter Duration of song: ");
        break;
     case 7:
        printf("\n\n\tEnter Rating of song: ");
        break;

     }
     fflush(stdin);
     while(((scanf("%c",&s.name))==1)&&(s.name!='\n'))  //input is taken from the user until new line character//
    {
        s.name=tolower(s.name);                         //input is converted into lower case for searching through database//
        mysearch=(char*)realloc(mysearch,(i+1)*sizeof(char));   //while the character is stored in the pointers it is continually//
        mysearch[i]=s.name;                                     //reallocated thus appending new memory in the existing string//
        i++;                                                    //without losing data//
    }
    mysearch=(char*)realloc(mysearch,(i+1)*sizeof(char));
    mysearch[i]='\0';
    printf("\n\n\tSearching");
    for(int sec=1000;sec>100;sec=sec-300)                   //This will add delays in printing the characters on screen giving//
     {                                                      //animation effect//
         delay(sec);
         printf(".");
     }
    while((fscanf(fp,"%c",&data))!=EOF)                     //data from file is read//
    {
        if(data!='\n')                                      //data is stored till new line//
        {
            mydata=(char*)realloc(mydata,(m+1)*sizeof(char));
            mydata[m]=data;
                m++;
        }
        else if(data=='\n')
        {
            mydata=(char*)realloc(mydata,(m+1)*sizeof(char));   //once we hit new line character string is closed with end of string//
            mydata[m]='\0';                                     //character//
            if(strstr(mydata,mysearch)!= NULL)          //entered string and read string is compared//
            {
                delay(500);
                printf("\n\n                  %s\n",mydata);
                op++;
            }
            free(mydata);
            m=0;                                    //mydata is freed so it can read new line from the file//
            mydata=(char*)malloc(m*sizeof(char));
			}
        }
        if(op==0)
        {
            printf("\n\n\tSearched item Does not exist in database");
        }
        free(mydata);
        free(mysearch);
        fclose(fp);
        return choice;
}
void POPULAR_SONGS()        /**< This program reads through database and prints min 1 or max 3 highest rated songs on the screen */
{
     struct songs s;                      /**< Declarations, we use pretty much the same declarations as previous function*/
     int m=0,c=0,i=0,itr=1,tim;
     float num,n=5.0;                    /**< 5.0 is the max, hence the starting rating for traversing */
     char rat[3];                        /**< this character array will be assigned the rating */
     char *mydata=NULL;
     char data;
     char *mysearch=NULL;
     mysearch=(char*)malloc(c*sizeof(char));
     mydata=(char*)malloc(m*sizeof(char));
     FILE *fp;                              /**< opening file */
     fp=fopen("Songs.txt","r");
     if(fp==NULL)
     {
         printf("\n\nDatabase does not exist\n\n");
     }
     fflush(stdin);
     srand(time(NULL));             /**< this logic with srand(),time() and rand() are used to get a random number between 1 and 3*/
     tim=rand()%4;
     if(tim==0)
        {
            tim++;
        }
        printf("\n\n\t\t\tSearching");
        for(int sec=1000;sec>100;sec=sec-300)
     {
         delay(sec);
         printf(".");
     }
         while((n<=5.0) && (n>=0.0))        /**< ratings from 5.0 to 0.0 */
     {
         num=n;
         sprintf(rat,"%f",num);             /**<the rating in float is converted to string */
         rat[3]='\0';
         while(i<=2)
         {
             s.rating=rat[i];               /**< rating is stored in the mysearch pointer string */
             mysearch=(char*)realloc(mysearch,(c+1)*sizeof(char));
             mysearch[c]=s.rating;
             c++;
             i++;
         }
         mysearch=(char*)realloc(mysearch,(c+1)*sizeof(char));
         mysearch[c]='\0';
         while(fscanf(fp,"%c",&data)!=EOF)
        {
            if(data!='\n')
     {                                                            //same string search operation is repeated with the rating//
         mydata=(char*)realloc(mydata,(m+1)*sizeof(char));
         mydata[m]=data;
         m++;
     }
     else if(data=='\n')
     {
         mydata=(char*)realloc(mydata,(m+1)*sizeof(char));
         mydata[m]='\0';
         if(strstr(mydata,mysearch)!=NULL && itr<=tim)
         {
             delay(500);
             printf("\n\n     %s\n",mydata);
             itr++;
         }
         mydata=NULL;
         m=0;
         mydata=(char*)malloc(m*sizeof(char));
     }}
     fp=fopen("Songs.txt","r");                         /**< file pointed is redirected to the start to read from the first line again */
     c=0;
     mysearch=(char*)realloc(mysearch,c*sizeof(char));
     i=0;                                               /**< while loop is restarted as well */
     n=n-0.1;
     fflush(stdin);                                     /**< any chances of garbage collection are looked over */
     }
     free(mydata);
     free(mysearch);
     fclose(fp);
}
void SONG_RECOMMENDATION()     /**< This function search the user desired genre and displays the highest rated songs of that genre */
{
    struct songs s;
     int m=0,c=0,genresize=0,i=0,decision=0,op=0;
     float num,n=5.0;
     char rat[3];
     char data;                      /**< The logic from the POPULAR_FUNCTION is repeated but with the addition of entry of genre from the user */
     char *mydata=NULL;
     char *mysearch=NULL;
     char *mygenre=NULL;
     mysearch=(char*)malloc(c*sizeof(char));
     mydata=(char*)malloc(m*sizeof(char));
     mygenre=(char*)malloc(genresize*sizeof(char));
     FILE *fp;
     fp=fopen("Songs.txt","r");
     if(fp==NULL)
     {
         printf("\n\nDatabase does not exist\n\n");
     }
     printf("\n\n\t\tEnter the Desired Genre : ");
     while((scanf("%c",&s.genre)==1)&&(s.genre!='\n'))
     {
         s.genre=tolower(s.genre);
         mygenre=(char*)realloc(mygenre,(genresize+1)*sizeof(char));
         mygenre[genresize]=s.genre;
         genresize++;
     }
     mygenre=(char*)realloc(mygenre,(genresize+1)*sizeof(char));
     mygenre[genresize]='\0';
     printf("\n\nSearching");
     for(int sec=1000;sec>100;sec=sec-300)
     {
         delay(sec);
         printf(".");
     }
         while((n<=5.0) && (n>=0.0))
     {
         num=n;
         sprintf(rat,"%f",num);
         rat[3]='\0';
         while(i<=2)
         {
             s.rating=rat[i];
             mysearch=(char*)realloc(mysearch,(c+1)*sizeof(char));
             mysearch[c]=s.rating;
             c++;
             i++;
         }
         mysearch=(char*)realloc(mysearch,(c+1)*sizeof(char));
         mysearch[c]='\0';
         while(fscanf(fp,"%c",&data)!=EOF)
        {
            if(data!='\n')
     {
         mydata=(char*)realloc(mydata,(m+1)*sizeof(char));
         mydata[m]=data;
         m++;
     }
     else if(data=='\n')
     {
         mydata=(char*)realloc(mydata,(m+1)*sizeof(char));
         mydata[m]='\0';
         if((strstr(mydata,mysearch)!=NULL) && (strstr(mydata,mygenre)!=NULL) && (decision==0)) //more comparisons in order to get one song//
         {
             delay(500);
             printf("\n\n     %s\n",mydata);
             decision++;
             op++;
         }
         mydata=NULL;
         m=0;
         mydata=(char*)malloc(m*sizeof(char));
     }}
     fp=fopen("Songs.txt","r");
     c=0;
     mysearch=(char*)realloc(mysearch,c*sizeof(char));
     i=0;
     n=n-0.1;
     fflush(stdin);
     }
     if(op==0)
     {
         printf("\n\n\tThe Desired Genre is not present in Database\n");
     }
     free(mydata);
     free(mysearch);
     fclose(fp);
}



