 #define KEY_HOME       71

  #define KEY_UP         72

  #define KEY_PGUP       73

  #define KEY_LEFT       75

  #define KEY_CENTER     76

  #define KEY_RIGHT      77

  #define KEY_END        79

  #define KEY_DOWN       80

  #define KEY_PGDN       81

  #define KEY_INSERT     82

  #define KEY_DELETE     83

  #define KEY_F1         59

  #define KEY_F2         60

  #define KEY_F3         61

  #define KEY_F4         62

  #define KEY_F5         63

  #define KEY_F6         64

  #define KEY_F7         65

  #define KEY_F8         66

  #define KEY_F9         67

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

using namespace std;

int ta,tb,tc,flagcheck0,flagcheck1,flagcheck2;
float r=3;

float maxX,maxY;
struct user
{
    char name[40];
    int high_score;
    int hh,mm,ss;
    bool rules;
}user_data;
char name1[40];
struct user1
{
    char name[40];
    int high_score;
    int hh,mm,ss;
    bool rules;
    struct user1*next;
};
struct user1* head=NULL,* current=NULL,* players,*first,*last;



void getdata()
{
    setactivepage(0);
    setvisualpage(0);
    int i=0;
    cleardevice();
    outtextxy(100,200,"ENTER USERNAME");
    int w=textwidth("A");
    int h=textheight("A");
    char d[60];
    char c,name_a[30];
    while((int)(c=(char)getch())==13)
        ;
    sprintf(d,"%c_",c);
    outtextxy(100+i*w,200+2*h,d);
    name1[i]=c;
    i++;
    do
    {

        c = (char) getch();
         switch (c)
            {

                case KEY_HOME:

                case KEY_UP:

                case KEY_PGUP:

                case KEY_LEFT:

                case KEY_CENTER:

                case KEY_RIGHT:

                case KEY_END:

                case KEY_DOWN:

                case KEY_PGDN:

                case KEY_INSERT:

                case KEY_DELETE:

                case KEY_F1:

                case KEY_F2:

                case KEY_F3:

                case KEY_F4:

                case KEY_F5:

                case KEY_F6:

                case KEY_F7:

                case KEY_F8:

                case KEY_F9:    break;

                default:            sprintf(d,"%c_",c);
                                    outtextxy(100+i*w,200+2*h,d);
                                    name1[i]=c;
                                    i+=1;
                                    break;
            }
    }   while ((int(c) != 13));
    name1[i]='\0';
    delay(1000);
}


void filesort()
{

    FILE *fp2;
    struct user1 *temp1,*temp2,*temp3,*temp4;
    first=(struct user1 *)malloc(sizeof(struct user1));
    last=(struct user1 *)malloc(sizeof(struct user1));
    fp2=fopen("E:\\COLLEGE\\Codeblocks\\Project\\Scoreboard.txt","r");
    first=NULL;
    last=NULL;
    while(!(feof(fp2)))
    {
        temp1=(struct user1*)malloc(sizeof(struct user1));
        fscanf(fp2,"%s %d %d %d %d",temp1->name,&temp1->high_score,&temp1->hh,&temp1->mm,&temp1->ss);
        temp1->next=NULL;
        if(first==NULL)
        {
            first=temp1;
            last=first;
        }
        else
        {
            last->next=temp1;
            last=temp1;
        }
    }
    temp2=(struct user1*)malloc(sizeof(struct user1));
    temp4=first;
    while(temp4!=NULL)
    {
        printf("%s",temp4->name);
        temp4=temp4->next;
    }
    fclose(fp2);
    struct user1* new1 = (struct user1*)malloc(sizeof(struct user1));
    struct user1* coun = (struct user1*)malloc(sizeof(struct user1));
	for(new1=first; new1->next != NULL; new1 = new1->next)
	{
		for(coun = new1->next; coun != NULL; coun = coun->next)
		{
			if(new1->high_score < coun->high_score)
			{
                temp2->hh=new1->hh;
                temp2->high_score=new1->high_score;
                temp2->mm=new1->mm;
                strcpy(temp2->name,new1->name);
                temp2->ss=new1->ss;
                new1->hh=coun->hh;
                new1->high_score=coun->high_score;
                new1->mm=coun->mm;
                strcpy(new1->name,coun->name);
                new1->ss=coun->ss;
                coun->hh=temp2->hh;
                coun->high_score=temp2->high_score;
                coun->mm=temp2->mm;
                strcpy(coun->name,temp2->name);
                coun->ss=temp2->ss;
			}
		}
	}
}

void alltime_score()
{
    int k=0;
    int position=textheight("Aa");
    cleardevice();
    setactivepage(0);
    setvisualpage(0);
    char l[100];
    char temp[40];
    struct user1 *temp1 ;
    temp1=(struct user1 *)malloc(sizeof(struct user1));
    filesort();
    temp1=first;
    while(temp1!=NULL)
    {
        sprintf(l,"%d- %s %d %d:%d:%d",k+1,temp1->name,temp1->high_score,temp1->hh,temp1->mm,temp1->ss);
        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        outtextxy(50,150+position*k,l);
        temp1=temp1->next;
        k++;

    }

    getch();
    delay(2000);
}


void output_score()
{
    int position=textheight("Aa");

    char l[300];
    setactivepage(0);
    setvisualpage(0);
    cleardevice();
    char temp1[20];
    int temp2,temp3,i=0,temp4,temp5,j,k=0;

    struct user1* temp;

    temp=head;
    sprintf(l,"LEADERBOARD");
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    outtextxy(50,50,l);


    while(temp!=NULL)
    {


        sprintf(l,"%d- %s %d %d:%d:%d ",k+1,temp->name,temp->high_score,temp->hh,temp->mm,temp->ss);
        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        outtextxy(50,150+position*k,l);
        temp=temp->next;
        k++;

    }
    cleardevice();
    outtextxy(200,100,"Press ENTER to see All-Time Score");

    getch();
    alltime_score();
    delay(1000);
}

void input_score(struct tm* a)
{
    int hr,mins,sec;
    hr=a->tm_hour-ta;
    mins=a->tm_min-tb;
    sec=a->tm_sec-tc;
    if(sec<0)
    {
        mins--;
        sec=60+sec;
    }

    int highscore=(hr*60 + mins*60 + sec);

    players=(struct user1*)malloc(sizeof(struct user1));
    strcpy(players->name,name1);
    players->hh=hr;
    players->mm=mins;
    players->ss=sec;
    players->high_score=highscore;
    players->next=NULL;

    FILE *x;
    x=fopen("E:\\COLLEGE\\Codeblocks\\Project\\Scoreboard.txt","a");
    fprintf(x," %s %d %d %d  %d ",name1,players->high_score,hr,mins,sec);
    fclose(x);

    if(head==NULL)
    {

        head=players;
        current=players;

    }
    else
    {

         current->next=players;
         current=players;

    }
}

void stars()
{
    for(int i=0;i<500;i++)
    {
        circle(int(rand()%int(maxX)),int(rand()%int(maxY)),1);
    }
}


int hr,mins,sec ;
void printtime(struct tm* a)
{
    hr=a->tm_hour-ta;
    mins=a->tm_min-tb;
    sec=a->tm_sec-tc;

    if(sec<0)
    {
        mins--;
        sec=60+sec;
    }


    char s[30];
    sprintf(s," TIME - %d : %d : %d",hr,mins,sec);

    outtextxy(maxX/2,10,s);
}

int p=0;

void countdown()
{
    char a[60];
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    int j=3,page=0;
    for(j=3;j>0;j--)
    {
        setactivepage(page);
        setvisualpage(page);
        cleardevice();
        stars();
        int k=j;
        int width=textwidth("GAME STARTS IN %d SECONDS");
        int height=textheight("GAME STARTS IN %d SECONDS");
        sprintf(a,"GAME STARTS IN %d SECONDS",j);
        outtextxy(maxX/2-width/2,maxY/2-height/2,a);
        delay(1000);
    }
    delay(1000);
}

void endgame()
{
    setactivepage(0);
    setvisualpage(0);
    char a[60];
    cleardevice();
    settextstyle(COMPLEX_FONT,HORIZ_DIR,7);
    int width=textwidth("GAME OVER !!");
    int height=textheight("GAME OVER !!");
    sprintf(a,"GAME OVER !!");
    outtextxy(maxX/2-width/2,maxY/2-height/2,a);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    sprintf(a,"Press any key to go to main menu");

    outtextxy(maxX-500,maxY-100,a);
    getch();

}


int start()
{
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    int i=0,page1=0;
    int midX=getmaxx()/2;
    int midY=getmaxy()/2;
    int width,height;
    int flag=-1;
    while(1)
    {
        setactivepage(page1);
        setvisualpage(1-page1);
        cleardevice();

        POINT cursorPos;
        GetCursorPos(&cursorPos);

        width=textwidth("MENU");
        height=textheight("MENU");
        outtextxy(midX-width/2,75,"MENU");

        if(cursorPos.x>=midX-150 and cursorPos.x<=midX+150 and cursorPos.y>=400 and cursorPos.y<=490)
        {
            setcolor(GREEN);
            if(GetAsyncKeyState(VK_LBUTTON))
                flag=0;
        }

        rectangle(midX-150,400,midX+150,490);
        width=textwidth("Start Game");
        height=textheight("Start Game");
        outtextxy(midX+5-width/2,425,"Start Game");
        setcolor(WHITE);

        if(cursorPos.x>=midX-150 and cursorPos.x<=midX+150 and cursorPos.y>=510 and cursorPos.y<=600)
        {
            setcolor(GREEN);
            if(GetAsyncKeyState(VK_LBUTTON))
                flag=1;
        }

        rectangle(midX-150,510,midX+150,600);
        width=textwidth("View Scores");
        height=textheight("View Scores");
        outtextxy(midX+5-width/2,535,"View Scores");
        setcolor(WHITE);

        if(cursorPos.x>=midX-150 and cursorPos.x<=midX+150 and cursorPos.y>=620 and cursorPos.y<=710)
        {
            setcolor(GREEN);
            if(GetAsyncKeyState(VK_LBUTTON))
                flag=2;
        }
        rectangle(midX-150,620,midX+150,710);
        width=textwidth("Exit");
        height=textheight("Exit");
        outtextxy(midX+5-width/2,645,"Exit");
        setcolor(WHITE);

        page1=1-page1;
        delay(0);

        if(flag!=-1)
            return flag;

    }
}
void spaceship()
{
    rectangle(80,maxY/2-25+p*10,180,maxY/2+25+p*10);
    setfillstyle(XHATCH_FILL, RED);
    floodfill(100,maxY/2+p*10,WHITE);
    line(180,maxY/2-25+p*10,220,maxY/2+p*10);
    line(180,maxY/2+25+p*10,220,maxY/2+p*10);
    circle(160,maxY/2+p*10,10);
    circle(160,maxY/2+p*10,1);
    line(82,maxY/2-25+p*10,82,maxY/2-40+p*10);
    line(120,maxY/2-25+p*10,100,maxY/2-40+p*10);
    line(82,maxY/2+25+p*10,82,maxY/2+40+p*10);
    line(120,maxY/2+25+p*10,100,maxY/2+40+p*10);
    rectangle(80,maxY/2-55+p*10,120,maxY/2-40+p*10);
    rectangle(80,maxY/2+55+p*10,120,maxY/2+40+p*10);
    line(120,maxY/2-55+p*10,130,maxY/2 -47.5+p*10);
    line(120,maxY/2-40+p*10,130,maxY/2 -47.5+p*10);
    line(120,maxY/2+55+p*10,130,maxY/2 +47.5+p*10);
    line(120,maxY/2+40+p*10,130,maxY/2 +47.5+p*10);

    int i,j;
    int a=maxY/2-20;
    for(i=0;i<5;i++,a+=10)
    {
        int k=rand()%3;
        k++;
        for(j=0;j<k;j++)
        {
            line(rand()%75,a+p*10,rand()%75,a+p*10);
        }
    }

}

void health()
{
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(maxX-155,10,"HEALTH");
    rectangle(maxX-80,10,maxX-10,30);
    rectangle(maxX-75,15,maxX-15,25);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(maxX-60,20,WHITE);

}

void asteroid(int t ,int l,int i)
{

                    ellipse(maxX-i-t,maxY/2+l,35,325,110,85);
                    ellipse(maxX-i-t,maxY/2+l,40,320,95,65);
                    circle(maxX-i-67-t,maxY/2+10+l,10);
                    circle(maxX-i-67-t,maxY/2+10+l,12);
                    circle(maxX-i+25-t,maxY/2+10+l,10);
                    circle(maxX-i+25-t,maxY/2+10+l,12);
                    circle(maxX-i-t,maxY/2-5+l,8);
                    circle(maxX-i-t,maxY/2-5+l,10);
                    circle(maxX-i+20-t,maxY/2-25+l,6);
                    circle(maxX-i+20-t,maxY/2-25+l,8);
                    circle(maxX-i+42-t,maxY/2-55+l,3);
                    circle(maxX-i+42-t,maxY/2-55+l,5);
                    circle(maxX-i+75-t,maxY/2+l,11);
                    circle(maxX-i+75-t,maxY/2+l,13);
                    ellipse(maxX-i-t,maxY/2+l,315,50,110,60);
                    circle(maxX-i+80-t,maxY/2-60+l,1);

}

int collisioncheck(int s[3],int z,int p1 )
{

    if(maxX-z-s[0]-80<=250&&p==30&&flagcheck0!=1)
    {
       return 1;
    }
    if(maxX-z-s[1]-80<=250&&p==0&&flagcheck1!=1)
    {
        return 1;
    }
    if(maxX-z-s[2]-80<=250&&p==-30&&flagcheck2!=1)
    {
        return 1;
    }
    return 0;

}

int main()
{

    int page=0,j=0,endcheck=0;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int gd=DETECT;
    int gm;
    initwindow(screenWidth, screenHeight, "",-2,-3);
    maxX=getmaxx();
    maxY=getmaxy();

    setactivepage(page);
    setvisualpage(page);
    B:
    r=3;
    int ch=start();

    if(ch!=2)
    {
        if(ch==0)
        {
            cleardevice();
            getdata();
            countdown();
            struct tm* now;
            struct tm *startI;
            time_t raw_time;
            raw_time = time(NULL);
            startI=localtime(&raw_time);
            ta=startI->tm_hour;
            tb=startI->tm_min;
            tc=startI->tm_sec;
            A:
                int flag4=rand()%13;
                r=r+1;
                int t[3];
                t[0]=rand()%500;
                t[1]=rand()%500;
                t[2]=rand()%500;
                flagcheck0=0;
                flagcheck1=0;
                flagcheck2=0;
                int f1=0;
                int b1=p;

                int y ;
                for(int i=0,y=0;i<maxX;i=i+r)
                {

                    setactivepage(1-page);
                    setvisualpage(page);
                    cleardevice();


                        if(GetAsyncKeyState(VK_DOWN)){
                            y++;
                            if(p<30 && y>=6)
                            {
                                y=0;
                                p+=30;
                            }

                        }
                        if(GetAsyncKeyState(VK_UP)){
                            y++;
                            if(p>-30 && y>=6)
                            {
                                y=0;
                                p-=30;
                            }
                        }
                        if(GetAsyncKeyState(VK_SPACE))
                        {  y++;
                            if(y>=6)
                            {

                                y=0;
                                f1=1;
                                b1=p;
                            }
                        }
                    if(f1==1)
                    {
                        line(130+i,maxY/2 -47.5+b1*10,150+i,maxY/2 -47.5+b1*10);
                    }
                    maxX=getmaxx();
                    maxY=getmaxy();
                    stars();
                    spaceship();
                    health();
                    raw_time = time(NULL);
                    now=localtime(&raw_time);
                    printtime(now);


                    if(i<(maxX-335))
                    {

                    if(flag4==0||flag4==9||flag4==12)
                     {
                       asteroid(t[0],300,i);
                       asteroid(t[2],-300,i);
                       flagcheck1=1;
                       endcheck=collisioncheck(t,i,p);
                    }
                     if(flag4==1||flag4==6||flag4==8)
                     {
                        asteroid(t[0],300,i);
                        asteroid(t[1],0,i);
                        flagcheck2=1;
                        endcheck=collisioncheck(t,i,p);
                    }
                     if(flag4==13)
                     {
                        asteroid(t[0],300,i);
                        flagcheck1=1;
                        flagcheck2=1;
                        endcheck=collisioncheck(t,i,p);
                    }
                    if(flag4==4||flag4==11||flag4==14)
                     {
                       asteroid(t[0],300,i);
                       asteroid(t[2],-300,i);
                       flagcheck1=1;
                       endcheck=collisioncheck(t,i,p);
                    }
                    if(flag4==2||flag4==7||flag4==10)
                     {
                       asteroid(t[1],0,i);
                       asteroid(t[2],-300,i);
                       flagcheck0=1;
                       endcheck=collisioncheck(t,i,p);
                    }
                    if(flag4==3)
                     {
                       asteroid(t[1],0,i);
                       flagcheck0=1;
                       flagcheck2=1;
                       endcheck=collisioncheck(t,i,p);
                    }
                    if(flag4==5)
                     {
                       asteroid(t[2],-300,i);
                       flagcheck0=1;
                       flagcheck1=1;
                       endcheck=collisioncheck(t,i,p);
                    }

                }

                    if(endcheck==1)
                        break;
                    page=1-page;
                    delay(0);
                }
                    if(endcheck==0)
                        goto A;
                    else
                    {
                        endgame();
                        input_score(now);
                        goto B;
                    }
        }
        if(ch==1)
            {
                output_score();
                goto B;
            }
    }

    closegraph();
}
