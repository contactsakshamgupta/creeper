
//***********header file ********************

#include"c:/creeper/troj/vipul.h"
		//*internally include all header file used here....*/


/*********...FUNCTION AND CLASS DECLARATIONS...........**********/
/*******calculator******/
class stack
{
	char ch[50];
	int top, bot,t,b;
	public:

	stack()
	{
		top =-1;
		bot =-1;
	}

	void push(char c)
	{
		if(top==49)
		{
			cout<<"EXPRESSION OVERFLOW";
			return;
		}
		ch[++top] = c;
		if(bot ==-1)
		bot++;
	}

	

void pop()
	{
		if(top==-1)
		{	cout<<"STACK UNDERFLOW";

			return;
		}
		top--;
	}

	float intopost(char st[]);
	float cal(char st[]);
} ;

float stack::intopost(char st[])
{
	 int a=0;
	 char str1[50]="(",str[50];
	strcat(st,",)");
	strcat(str1,st);
	for(int i=0;str1[i]!='\0';++i)
	{
		if(((str1[i] >=48 && str1[i]<58) )|| str1[i] == '.')
		{
			str[a++]=str1[i];
			if((str1[i+1]<48 || str1[1+i]>57) && str1[1+i]!='.')
			str[a++]=' ';
		}
		else
		{
			switch(str1[i])
			{
				case '(' : push('(') ;
						break;
				case '+' :
				


case '-' :
					if(ch[top] == '+' || ch[top] == '-' ||ch[top] == '*'||ch[top] == '/'||ch[top] == '^')
					{
						while(ch[top] == '+' || ch[top] == '-' ||ch[top] == '*'||ch[top] == '/'||ch[top] == '^')
						{
							str[a++]=ch[top];
							pop();
						}
					}
					push(str1[i]);
					break;
				case '*':
				case '/':
					if( ch[top] == '*'||ch[top] == '/'||ch[top] == '^'  )
					{
						while(ch[top] == '*'||ch[top] == '/'||ch[top] == '^')
						{
							str[a++]=ch[top];
							pop();
						}
					}
					push(str1[i]);
					break;
				case '^':
					if( ch[top] == '^'  )
					{
						while(ch[top] == '/'||ch[top] == '^')
						{
							str[a++]=ch[top];
							pop();
						}
					}
					push(str1[i]);
					break;
				case ')':       char c;
					  do
					  {
						c = ch[top];							c=ch[top];
						if(c!='(')
						str[a++]=c;
						pop();
							  }while(c!='(');
					  break;

			}
		}
	}
	str[a]='\0';

	float f= cal(str);
	return f;

}
float stack::cal(char st[])
{

	float f[50];
	int a=0;
	for(int i=0;st[i]!='\0';++i)
	{
		char ch[10];
		int j=0;
		if((st[i]>=48&&st[i]<=57)||st[i]=='.')
		{
			while((st[i]>=48&&st[i]<=57)||st[i]=='.')
			{
				ch[j++]=st[i++];
			}
			ch[j]='\0';
			f[a++]=atof(ch);
		}


		switch(st[i])
		{
			case '+':
				    f[a-2]=f[a-2]+f[a-1];
				    a--;
				    break;
			case '-':
				    f[a-2]=f[a-2]-f[a-1];
				    a--;
				    break;
			case '*':
				    f[a-2]=f[a-2]*f[a-1];
				    a--;
				    break;
			case '/':
				    f[a-2]=f[a-2]/f[a-1];
				    a--;
				    break;
			case '^':
				    f[a-2]=pow(f[a-2],f[a-1]);
				    a--;
				    break;

		}
	}
	return f[a-1];

}



class office
{
	protected:
	void of_beg();
	void calc();
	void calendar();
};

void office::of_beg()
{
	int i, v;
	do{
	textbackground(BLUE);
	textcolor(CYAN);
	_setcursortype(_NORMALCURSOR);
	clrscr();
	for(i=0;i<10;++i)
	{
		box(1+7*i,1+2*i,4,4);
		delay(80);
		box(1+7*i,1+2*i,4,4,int(' '));
	}
	box(74,22,4,4);
	gotoxy(25,2);
	textcolor(GREEN);
	cputs("WELCOME TO CREEPER OFFICE...");
	gotoxy(6,6);
	textcolor(CYAN);
	cout<<"1. CALCULATOR";
	gotoxy(6,12);
	cout<<"0. MAIN MENU";
	gotoxy(6,8);
	cout<<"2. CREEPER FILE EXPERT ";
	gotoxy(6,10);
	cout<<"3. CALENDAR ";
	gotoxy(25,22);
	cout<<"ENTER THE CHOICE NUMBER : ";
	v=int(getche()-48);
	delay(100);
	if(v)
	{ switch(v)
	 {
		case 1:
			calc();
			break;
		case 2:
		      class	File a;
			break;
		case 3:
			calendar();
			break;
		default:
			gotoxy(55,22);
			cputs("INVALID ENTRY");
			delay(1000);
			break;
	 }
	}
       }while(v!=0);
}

void office::calc()
{       char s[50];
	float f;
	stack p;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	cout<<"\n\t\t  --> THE CREEPULATOR <--";
	box(70,5,4,4, int('*'));
	gotoxy(3,19);
	cout<<"          INSTRUCTIONS: ";
	cout<<"\n\n*  SYMBOLS: ADD[+], SUBTRACT[-], MULTIPLY[*], DIVIDE[/], POWER[^],\n\t\t BRACKETS[ '(' AND ')' ]";
	cout<<"\n\n*  CAN EVALUTE LONG COMPLEX EXPRESSION UPTO 45 CHARACTERS";
	gotoxy(5,6);
	cout<<" ENTER EXPRESSION: ";
	gets(s);
	for(int i=0;s[i]!='\0';++i)
	{
		if(!(isdigit(s[i]))&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='^'&&s[i]!='.'&&s[i]!='('&&s[i]!=')')
		{
		     gotoxy(9,10);
		     cout<<"WRONG INPUT";
			delay(500);
			return;
		}
	}
	if(i==0)
	{
		return;
	}
	f=p.intopost(s);
	box(50,3,8,9, int('*'));
	gotoxy(9,10);
	cout<<"   RESULT =\t";
	cout<<f;
	gotoxy(15,12);
	cout<<"\n\n\t\tPRESS ANY KEY TO CREEP ON.. ";
	getch();
}


void office::calendar()
{

	int year;
	int month;
	int row;
	int col;
	int firstDay;
	int days;
	int day = 1;

	clrscr();
	do
	{
		printf("Please Enter Year (1582-4902): ");
		scanf("%d", &year);
	}
	while (year < 1582 || year > 4902);

	do
	{
		printf("Please Enter Month (1-12): ");
		scanf("%d", &month);
	}
	while (month < 1 || month > 12);

		int outValue;
	switch(month)
	{
		case 1:;
		case 3:;
		case 5:;
		case 7:;
		case 8:;
		case 10:;
		case 12: outValue = 31; break;
		case 4:;
		case 6:;
		case 9:;
		case 11: outValue = 30; break;
		case 2:
		{
			if (year % 4 == 0)
				outValue = 29;
			else
				outValue = 28;
		}
	}

	days = outValue;

	if (month == 1 || month == 2)
	{
		month = month + 12;
		year--;
	}

	firstDay = (1 + (((month + 1) * 26) / 10) + (year % 100) + ((year % 100) / 4) + ((year / 100) /4) - (2 * (year / 100))) % 7;
	if (firstDay < 0) firstDay = firstDay + 7;

	printf("\nSat  Sun  Mon  Tue  Wed  Thu  Fri\n");
	printf("---------------------------------\n");

	for (row = 1; row <= 6; row++)
	{
		for (col = 0; col < firstDay && row == 1; col++)
		{
			printf("     ");
		}

		for (; col <= 6 && day <= days; col++)
		{
			if (day > 9)
				printf("%d   ", day);
			else
				printf("%d    ", day);
			day++;
		}
		printf("\n\n");
	}
cout<<"\n\nPress ant key to creep on.....";
getch();
}









class funccall: public office
{
public:
funccall();
void intro();
void wel();
void pass();
void mmenu();
void contpan();
void chngpass();
void chngwel();
void ss();
void colbox();
void crepalltheway();
void entertainment();
};
/**************** MAIN FUNCTION *************************/

void main()
{
	funccall a;
}


/*********** FUNCTIONS **************/


funccall::funccall()  // calls other functions...
{
   intro();
   wel();
   pass();
   mmenu();
}


void funccall::intro()
{

	int i,j;

	_setcursortype(_NOCURSOR);	// THIS FUNCTION OMMITS THE CURSOR
	textcolor(GREEN);
	textbackground(BLACK);
	clrscr();

	textcolor(RED);

	for( j=0;j<51;j++)
	{
		gotoxy(j+21,22);
		cputs("°");
	}

	textcolor(WHITE);
	gotoxy(7,22);
	cputs("   % complete");

	textcolor(YELLOW);
	j=20;
	for( i=0;i<100;i++)
	{
		gotoxy(7,22);
		cout<<i;
		if(i%2==0)
		{
			textcolor(j);
			box(8,8,20,5);
			box(8,8,23,8);
			gotoxy(32,10);
			cputs("CREEPER");
			j++;
			gotoxy(j,22);
			textcolor(YELLOW);
			cputs("Û");
		}
		delay(70);
	}

	delay(1500);

}




void funccall::wel()

{
	 clrscr();
	_setcursortype(_NOCURSOR);
	textbackground(BLUE);
	textcolor(GREEN);


	fstream f("c:/creeper/sys/wel.txt",ios::in);

	//checking opening...................................
	if(!f)
	{
	    cout<<"\n\n\n\n\n\n\t\t****SYSTEM ERROR**CAN NOT OPEN WEL.TXT****\n\n\t\t****contact software technical expert*****";
	    getch();
	    return;
	}

	//**********************************************

	 char ch, st[100]="\0";
	 int i=0, x=25 ,y[]={22,20,3,19,4,18,5,17,6,16,7,15,8,14,9,13,10};

	 f.get(ch);
	   clrscr();
	  box(78,23,2,2,1);
	 while(f)
	 {
		for(int j=0; j<17;++j)
		{
			gotoxy(x,y[j]);
			cout<<ch;
			delay(17);
			gotoxy(x,y[j]);
			cout<<" ";
		}
		gotoxy(x,10);
		cout<<ch;
		x++;
		st[i++]=ch;
		st[i]='\0';
		f.get(ch);
	 }

	 f.close();
	 delay(2000);
}

void funccall::pass ()
{

	ifstream f("c:/creeper/sys/pass",ios::binary);

		textbackground(BLACK);
		textcolor(GREEN);
		clrscr();

	if(!f)
	{
		_setcursortype(_NOCURSOR);
		box(55,5,13,15);
		gotoxy(22,16);
		cout<<"*****PASS FILE NOT FOUND******";

		gotoxy(15,18);

		cout<<"YOUR CREEPER CAN NOT BE PROTECTED BY PASSWORD.....";
		delay(5500);
		return;
	}

	_setcursortype(_NORMALCURSOR);
	char c,p1[50],pass[50];
	int i,t=0;
	f.getline(pass,50);
	if(pass[0]!='\0')
	{
		while(t<3)
		{
	    clrscr();
			i=0;
			box(78,23,2,2,int('?'));

			gotoxy(4,18);
			cout<<"**** INSTRUCTIONS *********************";
			gotoxy(4,19);
			cout<<"# MAXIMUN LENGTH 50 CHARACTERS";
			gotoxy(4,20);
			cout<<"# DO NOT USE NAVIGATION KEYS USE BACKSPACE INSTEAD";
			gotoxy(4,21);
			cout<<"# PREASS ENTER WHEN PASSWORD COMPLETELY ENTERED";
			gotoxy(4,22);
			cout<<"# CASE SENSITIVE";

			gotoxy(22,10);
			cout<<"ENTER THE PASSWORD:";
			gotoxy(30,11);
			c=getch();
			while(c!='\r')
			{
				if(c=='\b'&& i!=0)
				{
		    cout<<"\b \b";
					i--;
				}
				else if(c!='\b')
				{
					cout<<"*";
					p1[i++]=c;
				}
				c=getch();

			}
			p1[i]='\0';
		t++;
		box(21,3,48,12);
		    gotoxy(50,13);

		    if(!strcmp(pass,p1))
		    {
		   cout<<"ACCESS GRANTED...";
			       delay(1500);
			       break;
	    }
		else
		    {
			     cout<<"ACCESS DENIED...";
			     delay(1500);
			     if(t==3)
			     {
				     _setcursortype(_NOCURSOR);
				     clrscr();
				     gotoxy(25,10);
				     cout<<"<<<<< TERMINATING >>>>>>";
				     delay(2000);
				     exit(0);
			      }
		   }
	}

	}

    f.close();

}


void funccall::mmenu()
{

	int v;
	struct dostime_t t;
	struct dosdate_t d;
	do
	{
		textbackground(BLUE);
		textcolor(MAGENTA);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN);
		box(4,4,4,4);
		box(4,4,6,6);
		textcolor(GREEN+BLINK);
		gotoxy(11,7);
		cputs("CREEPER");
		delay(502);
		_dos_gettime(&t);
		_dos_getdate(&d);
		box(21,6,52,4,222);
		gotoxy(54,6);
		printf("DATE:%2d/%02d/%02d\n",d.day,d.month,d.year);
		gotoxy(54,7);
		printf("Time:%2d:%02d:%02d.%02d\n",t.hour,t.minute,t.second,t.hsecond);

		gotoxy(29,9);
		textcolor(WHITE+BLINK);
		cputs(">>>> MENU >>>>");

		for(int i=0;i<13;++i)
		{
			box(1+(6*i),1+i,3,11);
			delay(70);
			box(1+6*i,1+i,3,11,int(' '));

		}
			box(76,14,3,11);
		textcolor(WHITE);
		gotoxy(5,12);
		cputs("1. CONTROL PANEL");
		gotoxy(5,14);
		cputs("2. SCREEN SAVERS");
		gotoxy(5,16);
		cputs("3. ENTERTAINMENT");
		gotoxy(5,18);
		cputs("4. OFFICE");
		gotoxy(28,20);
		cputs("0. EXIT");
		gotoxy(25,22);
		cputs("ENTER THE CHOICE NUMBER : ");
		v=int(getche()-48);
		delay(100);
		if(v)
		{ switch(v)
		 {
			case 1:
			      contpan();
			      break;
			case 2:
				ss();
				break;
			case 3:
				entertainment();
				break;

			case 4: of_beg();
				break;
			default:

				gotoxy(55,22);
				cputs("INVALID ENTRY");
				delay(1000);
				break;

		 }}
	}while(v!=0);
}


void funccall::contpan()
{

	int v;
	struct dostime_t t;
	struct dosdate_t d;
	do
	{
		textbackground(BLUE);
		textcolor(MAGENTA);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN);
		box(4,4,4,4);
		box(4,4,6,6);
		textcolor(GREEN+BLINK);
		gotoxy(11,7);
		cputs("CREEPER");
		delay(502);
		_dos_gettime(&t);
		_dos_getdate(&d);
		box(21,6,52,4,222);
		gotoxy(54,6);
		printf("DATE:%2d/%02d/%02d\n",d.day,d.month,d.year);
		gotoxy(54,7);
		printf("Time:%2d:%02d:%02d.%02d\n",t.hour,t.minute,t.second,t.hsecond);

		gotoxy(25,9);
		textcolor(WHITE+BLINK);
		cputs(">>>> CONTROL PANEL >>>>");
		box(35,10,20,11);
		textcolor(WHITE);
		gotoxy(22,12);
		cputs("1. CHANGE PASSWORD");
		gotoxy(22,14);
		cputs("2. CHANGE WELCOME NOTE");
		gotoxy(22,16);
		cputs("0. MAIN MENU");
		gotoxy(25,18);
		cputs("ENTER THE CHOICE NUMBER : ");
		v=int(getche()-48);
		delay(100);
		if(v)
		{ switch(v)
		 {
			case 1:
			      chngpass();
			      break;

			case 2:
				chngwel();
				break;
			default:

				gotoxy(27,20);
				cputs("INVALID ENTRY");
				delay(1000);
				break;

		 }}
	}while(v!=0);
}

void funccall::chngpass()
{
	char ch1[50],ch2[50];
	textbackground(BLACK);
	_setcursortype(_NORMALCURSOR);
	textcolor(GREEN);
	clrscr();
	box(78,23,2,2);
	delay(200);
	box(74,19,4,4);
	delay(200);
	box(70,15,6,6);
	delay(200);
	box(64,11,8,8);
	gotoxy(10,10);
	cout<<"ENETER NEW PASSWORD [MAX 50]: ";
	gets(ch1);
	gotoxy(10,13);
	cout<<"CONFIRM PASSWORD: ";
	gets(ch2);
	gotoxy(18,16);
	if(!strcmp(ch1,ch2))
	{
		ofstream f("c:/creeper/sys/pass",ios::binary);
		if(!f)
		{
			cout<<"PASS FILE DID NOT EXIST......";
			return;
		}
		f<<ch1;
		cout<<"PASSWORD CHANGED";
		f.close();
	}
	else
		cout<<"PASSWORD DID NOT MATCH";

	delay(1000);

}

void funccall::chngwel()
{
	char ch[100];
	textbackground(BLACK);
	textcolor(GREEN);
	_setcursortype(_NORMALCURSOR);
	clrscr();
	ofstream f("c:/creeper/sys/wel.txt");
	if(!f)
	{
		gotoxy(10,12);
		cout<<"WEL FILE NOT FOUND";
		return;
	}
	box(78,23,2,2);
	delay(200);
	box(74,19,4,4);
	delay(200);
	box(70,15,6,6);
	delay(200);
	box(64,11,8,8);
	gotoxy(10,10);
	cout<<"ENTER NEW NOTE [MAX 50]: ";
	gets(ch);
	f<<ch;
	gotoxy(10,13);
	f.close();
	cout<<"WELCOME NOTE CHANGED...HURAYY!!!!";
	delay(1500);

}


void funccall::ss()
{

	int v;
	struct dostime_t t;
	struct dosdate_t d;
	do
	{
		textbackground(BLUE);
		textcolor(MAGENTA);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN);
		box(4,4,4,4);
		box(4,4,6,6);
		textcolor(GREEN+BLINK);
		gotoxy(11,7);
		cputs("CREEPER");
		delay(502);
		_dos_gettime(&t);
		_dos_getdate(&d);
		box(21,6,52,4,222);
		gotoxy(54,6);
		printf("DATE:%2d/%02d/%02d\n",d.day,d.month,d.year);
		gotoxy(54,7);
		printf("Time:%2d:%02d:%02d.%02d\n",t.hour,t.minute,t.second,t.hsecond);

		gotoxy(25,9);
		textcolor(WHITE+BLINK);
		cputs(">>>> SCREEN SAVERS >>>>");
		box(35,10,20,11);
		textcolor(WHITE);
		gotoxy(22,12);
		cputs("1. COLOUR BOX");
		gotoxy(22,13);
		cputs("2. WELCOME NOTE");
		gotoxy(22,14);
		cputs("3. CREEPER BOOTING");
		gotoxy(22,15);
		cputs("4. CREEPER ALL THE WAY");
		gotoxy(22,16);
		cputs("0. MAIN MENU");
		gotoxy(25,18);
		cputs("ENTER THE CHOICE NUMBER : ");
		v=int(getche()-48);
		delay(100);
		if(v)
		{ switch(v)
		 {
			case 1:
			      colbox();
			      break;

			case 2:
				wel();
				break;
			case 3:
				intro();
				break;
			case 4:
				crepalltheway();
				break;
			default:

				gotoxy(27,20);
				cputs("INVALID ENTRY");
				delay(1000);
				break;

		 }}
	}while(v!=0);
}

void funccall::colbox()
{
	int i;
	for(i=1;i<6;++i)
	{
		_setcursortype(_NOCURSOR);
		textbackground(BLACK);
		textcolor(i);
		clrscr();
		box(77,23,2,2);
		delay(500);
		box(73,19,4,4);
		delay(500);
		box(69,15,6,6);
		delay(500);
		box(65,11,8,8);
		delay(500);
		textcolor(WHITE);
		gotoxy(10,10);
		cputs("CREEPER");
		gotoxy(64,10);
		cputs("CREEPER");
		gotoxy(10,16);
		cputs("CREEPER");
		gotoxy(64,16);
		cputs("CREEPER");
		gotoxy(36,13);
		cputs("CREEPER");
		delay(1000);
	}
}

void funccall::crepalltheway()
{
		int x, y;

		_setcursortype(_NOCURSOR);
		randomize();
		for(int i = 0; i<10; ++i)
		{       textbackground(BLUE);
			textcolor(MAGENTA);
			x=random(50)+4;
			y=random(15)+4;
			clrscr();
			textcolor(GREEN);
			box(4,4,x,y);
			box(4,4,x+2,y+2);
			textcolor(GREEN+BLINK);
			gotoxy(x+7,y+3);
			cputs("CREEPER");
			delay(2000);
		}
}




void funccall::entertainment()
{
	int v;
	struct dostime_t t;
	struct dosdate_t d;
	do
	{
		textbackground(BLUE);
		textcolor(MAGENTA);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN);
		box(4,4,4,4);
		box(4,4,6,6);
		textcolor(GREEN+BLINK);
		gotoxy(11,7);
		cputs("CREEPER");
		delay(502);
		_dos_gettime(&t);
		_dos_getdate(&d);
		box(21,6,52,4,222);
		gotoxy(54,6);
		printf("DATE:%2d/%02d/%02d\n",d.day,d.month,d.year);
		gotoxy(54,7);
		printf("Time:%2d:%02d:%02d.%02d\n",t.hour,t.minute,t.second,t.hsecond);

		gotoxy(25,9);
		textcolor(WHITE);
		cputs(">>> CREEPERTAINMENT >>>");
		textcolor(WHITE);
		gotoxy(2,2);
		cputs(">>>> LETS  TAKE ENTERTAINMENT TO NEXT LEVEL >>>>");
		box(35,10,20,11);
		textcolor(WHITE);
		gotoxy(22,12);
		cputs("1. MUSIC");
		gotoxy(22,14);
		cputs("2. GAMES");
		gotoxy(22,16);
		cputs("0. MAIN MENU");
		gotoxy(25,18);
		cputs("ENTER THE CHOICE NUMBER : ");
		v=int(getche()-48);
		delay(100);
		if(v)
		{ switch(v)
		 {
			case 1:
			      music();
			      break;

			case 2:
			       game();
				break;
			default:

				gotoxy(27,20);
				cputs("INVALID ENTRY");
				delay(1000);
				break;

		 }}
	}while(v!=0);
}


