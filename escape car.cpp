#include <stdio.h>
#include <graphics.h>

int i=1,j=1,k=1,l=1,m=0;
char score[100];
int count;

void firstScreen()
{
	char arr[12]="Escape Cars";
	settextstyle(1,0,8);
    for(i=0;arr[i]!='\0';i++)
	{
	    delay(200);
	    setcolor(i+5);
	    outtextxy(i+359,-i+301,arr);
    }
	cleardevice();
}

void secondScreen()
{
	setcolor(2);
	settextstyle(3,0,3);
	outtextxy(500,300,"PRESS ANY KEY TO START GAME");
	outtextxy(500,330,"PRESS ESC TO EXIT");
	char press=getch();
	switch(press)
	{
		case 27://ESC
			exit(0);
			break;
			
		default:
			break;
	}
}

int last()
{
	cleardevice();
	
	char arr[10]="GAME OVER";
	settextstyle(10,0,10);
    for(i=0;arr[i]!='\0';i++)
	{
	    setcolor(i+6);
	    outtextxy(280,300-20*i,arr);
	    delay(200);
	}
	printf("Your score is %d.",count);
}
int obstaclesLane1(int n)
{
	setcolor(BLUE);
	rectangle(480,19+n,540,89+n);
	rectangle(495,89+n,525,119+n);//down
	
	if(527>=599+i && 135+n>=614+j || 542>=599+i && 100+n>=614+j)
	{
		last();
		exit(1);
	}
	else
	{
		count+=1;
	}
	arc(480,34+n,90,270,7);
	arc(480,74+n,90,270,7);
	arc(540,34+n,270,90,7);
	arc(540,74+n,270,90,7);
	
	setfillstyle(9,3);
	floodfill(485,21+n,BLUE);
	setfillstyle(11,3);
	floodfill(500,92+n,BLUE);
	
	return 119+n;
}

int obstaclesLane2(int n)
{
	setcolor(BLUE);
	rectangle(610,19+n,670,89+n);
	rectangle(625,89+n,655,119+n);
	if(625<=659+i && 135+n>=614+j && 660>=599+i || 610<=659+i && 100+n>=614+j && 670>=599+i)
	{
		last();
		exit(2);
	}
	else
	{
		count+=1;
	}
	
	arc(610,34+n,90,270,7);
	arc(610,74+n,90,270,7);
	arc(670,34+n,270,90,7);
	arc(670,74+n,270,90,7);
	
	setfillstyle(9,3);
	floodfill(615,21+n,BLUE);
	setfillstyle(11,3);
	floodfill(630,92+n,BLUE);
	
	return 119+n;
}

int obstaclesLane3(int n)
{
	setcolor(BLUE);
	rectangle(740,19+n,800,89+n);
	rectangle(755,89+n,785,119+n);
	if(755<=659+i && 135+n>=614+j || 740<=659+i && 100+n>=614+j)
	{
		last();
		exit(3);
	}
	else
	{
		count+=1;
	}
	arc(740,34+n,90,270,7);
	arc(740,74+n,90,270,7);
	arc(800,34+n,270,90,7);
	arc(800,74+n,270,90,7);
	
	setfillstyle(9,3);
	floodfill(745,21+n,BLUE);
	setfillstyle(11,3);
	floodfill(760,92+n,BLUE);
	
	return 119+n;
}

void lanes()
{
	//Side lanes
	setcolor(YELLOW);
	rectangle(435,0,445,700);
    rectangle(830,0,840,700);
    
    setfillstyle(BKSLASH_FILL, YELLOW);//Pattern of filling style
    floodfill(440,5,YELLOW);
    
    setfillstyle(SLASH_FILL, YELLOW);
    floodfill(835,5,YELLOW);
}

void car(int i, int j)
{
	setcolor(LIGHTGRAY);
	// Coordinates of Car
	arc(629+i,634+j,180,0,30);
	arc(629+i,639+j,180,0,24);
	line(599+i,584+j,599+i,634+j);//left
	line(659+i,584+j,659+i,634+j);//Right
	line(606+i,594+j,606+i,639+j);
	line(652+i,594+j,652+i,639+j);
	line(624+i,620+j,624+i,645+j);
	line(632+i,620+j,632+i,645+j);
	line(659+i,584+j,652+i,594+j);
	line(599+i,584+j,606+i,594+j);
	line(606+i,594+j,652+i,594+j);
	line(606+i,604+j,652+i,604+j);
	arc(629+i,594+j,0,180,24);
	arc(629+i,584+j,0,183,30);
	line(659+i,584+j,665+i,588+j);
	line(593+i,588+j,599+i,584+j);
	
	setfillstyle(SOLID_FILL, RED);
	
	floodfill(629+i,634+j,LIGHTGRAY);
	floodfill(601+i,589+j,LIGHTGRAY);
	floodfill(655+i,591+j,LIGHTGRAY);
	floodfill(608+i,599+j,LIGHTGRAY);	    
	floodfill(629+i,560+j,LIGHTGRAY);
	floodfill(629+i,590+j,LIGHTGRAY);
	floodfill(606+i,600+j,LIGHTGRAY);

}

void checkKeyboardHit()
{
	if(kbhit())
	{
	    char move=getch();
	    if(move==65 || move==97)//A
	    {
	    	if(594+i>445)
	    	{
	    		i=i-10;			
	    	}
		}
		if(move==68 || move==100)//D
		{
			if(659+i<820)
			{
				i=i+10;	
			}
		}
		if(move==87 || move==119)//W
		{
			if(654+j>95)
			{
				j=j-10;
			}
		}
	    if(move==83 || move==115)//S
		{
			if(604+j<605)
			{
				j=j+10;	
			}
		}	
	}
}

void midTracks()
{
	cleardevice();
	
	int ob1=1,ob2=-500,ob3=-50;
	int a;
	for(a=0; ;a++)
	{
		cleardevice();
		
		setcolor(LIGHTMAGENTA);
		settextstyle(4,1,6);
		outtextxy(250,60,"ESCAPE CARS");
		
		setcolor(CYAN);
		settextstyle(4,0,2);
		outtextxy(1000,270,"How to play:");
		
		setcolor(GREEN);
		settextstyle(4,0,1);
		outtextxy(920,300,"Try to escape cars coming");
		outtextxy(923,320,"from opposite direction.");
		
		setcolor(BROWN);
		settextstyle(1,0,2);
		rectangle(1010,420,1140,490);
		
		setcolor(RED);
	    outtextxy(1050,430,"W");
	    outtextxy(1020,460,"A");
	    outtextxy(1060,460,"S");
	    outtextxy(1100,460,"D");
	    
	    setcolor(CYAN);
	    settextstyle(3,0,1);
	    //Instructions to play game.
	    outtextxy(1000,520,"Instructions:");
	    
	    setcolor(DARKGRAY);
		outtextxy(1000,550,"Press W to move up");
		outtextxy(1000,570,"Press S to move down");
		outtextxy(1000,590,"Press D to move right");
		outtextxy(1000,610,"Press A to move left");
		
		setcolor(BLUE);
		settextstyle(3,0,3);
		sprintf(score, "Score=%d", count);
		outtextxy(1000,200,score);

		int catchob1=obstaclesLane1(ob1);
		int catchob2=obstaclesLane2(ob2);
		int catchob3=obstaclesLane3(ob3);
		if(catchob1>720)
		{
			ob1=1;
		}
		else
		{
			ob1=ob1+30;
		}
		if(catchob2>700)
		{
			ob2=-300;
		}
		else
		{
			ob2=ob2+35;
		}
		if(catchob3>700)
		{
			ob3=-50;
		}
		else
		{
			ob3=ob3+40;
		}
		
		lanes();
		
		checkKeyboardHit();
		
		setcolor(WHITE);
	    
		//Middle tracks
		
		rectangle(569+k,-201+l,574+k,-1+l);
		rectangle(699+k,-201+l,704+k,-1+l);
			
		rectangle(569+k,149+l,574+k,349+l);
		rectangle(699+k,149+l,704+k,349+l);
			
		rectangle(569+k,499+l,574+k,699+l);
		rectangle(699+k,499+l,704+k,699+l);

		setfillstyle(SOLID_FILL,WHITE);
		
		floodfill(570+k,l-3,WHITE);
		floodfill(702+k,l-3,WHITE);
			
		floodfill(570+k,151+l,WHITE);
		floodfill(702+k,151+l,WHITE);
			
		floodfill(570+k,502+l,WHITE);
		floodfill(702+k,503+l,WHITE);
			
		l=l+20;
			
		if(449+l>=690)
		{
			l=0;
		}
		car(i,j);
			
		delay(100);	
	} 

}

int main(void) 
{
	//Initialize windows resolution
	initwindow(1920,1080);

	firstScreen();
	
	secondScreen();
	
	midTracks();
	
    getch();
    closegraph();
    return 0;
}



