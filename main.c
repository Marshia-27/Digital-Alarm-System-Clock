#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<signal.h>

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void frame(int x,int y,int l1,int b1)
{
    int i,m;
    gotoxy(x,y);
    printf("%c",201);
    for(i=x+1; i<l1-1; i++)
    {
        gotoxy(i,y);
        printf("%c",205);  }

    gotoxy(i,y);
    printf("%c",187);

    for (m=y+1; m<b1; m++)
    {
        gotoxy(x,m);
        for(i=x; i<l1; i++)
        {
            if(i==x||i==l1-1)
            {
                gotoxy(i,m);
                printf("%c",186); } }  }
    gotoxy(x,m);
    printf("%c",200);

    for(i=x+1; i<l1-1; i++)
    {
        gotoxy(i,m);
        printf("%c",205);  }

    gotoxy(i,m);
    printf("%c",188);
}


int main()
{   abc:
    system("cls");  //clears the screen
    system("color E5"); //Creates Bright White Background with black text
    int h=0,m=0,s=0,l,z,y,a,b,c;
    frame(29,5,93,24);
    int hours, minutes, seconds, day, month, year;

    // `time_t` is an arithmetic time type
    time_t now;

    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);

    // Convert to local time format and print to stdout
    gotoxy(31,6);
    printf("What do you want to use?");
    gotoxy(31,7);
    printf("1.Tell the time now and date today.");
    gotoxy(31,8);
    printf("2.Set an alarm.");

    gotoxy(31,10);
    printf("Please Input 1 or 2 according to your choice:");
    int option,alarm=0;
    input:
    scanf("%d",&option);
    if(option<1||option>3||(option==3&&alarm==1)) {
        gotoxy(31,11);
        printf("Wrong Input . Please try again in 2 seconds");
        Sleep(1000);
        gotoxy(31,11);
        printf("Wrong Input . Please try again in 1 seconds");
        Sleep(1000);
        gotoxy(31,11);
        printf("Wrong Input . Please try again in 0 seconds");
        Sleep(100);
        goto input;
    }
    if (option ==1) {

    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);

    hours = local->tm_hour;         // get hours since midnight (0-23)
    minutes = local->tm_min;        // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;        // get seconds passed after a minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900

    // print local time
    //int am=0;
    gotoxy(31,11);
    if(hours>12){
    printf("Now it is  %02d:%02d:%02d\n ",hours-12,minutes,seconds);}
    else if (hours==0)
    {printf("Now it is  %02d:%02d:%02d\n ",12,minutes,seconds);}
    else{
    printf("Now it is  %02d:%02d:%02d ",hours,minutes,seconds);}
    //if()
    // print the current date
    gotoxy(31,12);
    printf("Date is: %02d/%02d/%04d\n", day, month, year);


    char p[100]="Hello . It   Is ";
    int d;
    if (hours < 12)
        d=hours;
    else d=hours-12;
    if (hours==0) d=12;
    char q[100],r[100];
                        itoa(d,q,10);
                        strcat(p,q);
                        char rrr[7]="    ";
                        strcat(p,rrr);
                        itoa(minutes,r,10);
                        strcat(p,r);
                        strcat(p,rrr);
                        itoa(seconds,r,10);
                        strcat(p,r);
                        strcat(p,rrr);
                        if(hours>=12)
                        {char word[5]=" PM ";
                        strcat(p,word);}
                        if (hours<12) {
                        char w[5]=" AM ";
                        //printf("%c",w[1]);
                        strcat(p,w);}
                        //printf("%c%c%c%c%c%c",rr[0],rr[1],rr[2],rr[3],rr[4],rr[5]);}

                        char  cc[100];
                        strcpy(cc,"espeak \"");
                        strcat(cc,p);
                        strcat(cc,"\"");
                        system(cc);
                        goto abc;}


    else if(option == 2 ){
        int ah , am ,as, dn ;
    alarm=1;
    struct tm *local = localtime(&now);
    hours = local->tm_hour;         // get hours since midnight (0-23)
    minutes = local->tm_min;        // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;        // get seconds passed after a minute (0-59)
    gotoxy(31,11);
    if(hours>12){
    printf("Now it is  %02d:%02d:%02d\n ",hours-12,minutes,seconds);}
    else if (hours==0)
    {printf("Now it is  %02d:%02d:%02d\n ",12,minutes,seconds);}
    else{
    printf("Now it is  %02d:%02d:%02d ",hours,minutes,seconds);}
    gotoxy(31,12);
    printf("Is the alarm time in am or pm?");
    gotoxy(31,13);
    printf("1.AM 2.PM");
    gotoxy(45,13);
    scanf("%d",&dn);
    gotoxy(31,14);
    printf("Please Input the alarm time in hh mm ss format:");
    gotoxy(31,15);
    scanf("%d%d%d",&ah,&am,&as);
    seconds = seconds+(minutes*60)+(hours*3600);
    if(dn==2 && ah!=12) ah=ah+12;
    else if(dn==1 && ah==12) ah=0;
    as=as+(am*60)+(ah*3600);
    if (as<seconds) as=24*3600;
    while(as-seconds>0)
        {Sleep(1000);
    gotoxy(31,16);
    printf("Please wait until it alarms . Only %d seconds left",as-seconds);
    seconds=seconds+1;
    if(as==seconds){
    Beep(600,2000);

        }
    }goto abc;
    }
    return 0;}
