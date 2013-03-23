
//declarations............

void airtel();
void saregama();
void musickeyboard();



void music(void)
{
		textbackground(BLUE);
		textcolor(WHITE);
		_setcursortype(_NOCURSOR);
		clrscr();
		int v;
		int pos[10][2] ={ {2,3},{4,10},{49,15},{9,6},{65,20},{24,5},{50,19},{42,3},{5,17},{68,6} };
		int i;
		for(i=0;i<10;++i)
		{
			gotoxy(pos[i][0],pos[i][1])  ;
			cout<<char (14);
			delay(800);
		}
		gotoxy(30,12);
		cputs("WELCOME !!!");
		delay(1200);
	do
	{
		textbackground(BLUE);
		textcolor(WHITE);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN+BLINK);


		box(35,5,25,3);
		gotoxy(29,5);
		textcolor(WHITE+BLINK);
		cputs(">>>> MUSIC PLAYER 1.1  >>>>");

		for(int i=0;i<13;++i)
		{
			box(1+(6*i),1+i,3,11,14);
			delay(80);
			box(1+6*i,1+i,3,11,(' '));

		}
			box(76,14,3,11,14);
		textcolor(WHITE);
		gotoxy(5,13);
		cputs("1. AIRTEL ");
		gotoxy(5,15);
		cputs("2. THE SA RE GA MA");
		gotoxy(5,17);
		cputs("3. MUSICAL KEYBOARD");
		gotoxy(28,21);
		cputs("0. EXIT");
		gotoxy(25,22);
		cputs("ENTER THE CHOICE NUMBER : ");
		v=int(getche()-48);
		delay(100);
		if(v)
		{ switch(v)
		 {
			case 1:
			airtel();
			      break;
			case 2:
				saregama();
				break;
			case 3:
				musickeyboard();
				break;
			default:

				gotoxy(55,22);
				cputs("INVALID ENTRY");
				delay(1000);
				break;

		 }}
	}while(v!=0);
}




void airtel()
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	clrscr();
	gotoxy(35,10);
	textcolor(WHITE);
	cputs("Air");
	textcolor(WHITE);
	cputs("tel");
	float A,Bb,D,G,F;
	A = 440;
	G = 780;
	Bb = 461;
	D = 586;
	F = 687;
	sound(G);
	delay(500);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(G);
	delay(500);
	nosound();
	sound(2*D);
	delay(500);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(2*Bb);
	delay(250);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(500);
	nosound();
	sound(2*A);
	delay(500);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(250);
	sound(G);
	delay(250);
	sound(2*A);
	delay(250);
	sound(2*Bb);
	delay(500);
	sound(2*A);
	delay(500);
	sound(G);
	delay(250);
	sound(F);
	delay(250);
	sound(D);
	delay(500);
	nosound();
	//end 1
	sound(G);
	delay(500);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(G);
	delay(500);
	nosound();
	sound(2*D);
	delay(500);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(2*Bb);
	delay(250);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(500);
	nosound();
	sound(2*A);
	delay(500);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(250);
	sound(G);
	delay(250);
	sound(2*A);
	delay(250);
	sound(2*Bb);
	delay(500);
	sound(2*A);
	delay(500);
	sound(G);
	delay(250);
	sound(F);
	delay(250);
	sound(D);
	delay(500);
	nosound();
	//end 2
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(250);
	sound(G);
	delay(250);
	sound(2*A);
	delay(250);
	sound(2*Bb);
	delay(500);
	sound(2*A);
	delay(500);
	sound(G);
	delay(250);
	sound(F);
	delay(250);
	sound(D);
	sound(2*A);
	delay(250);
	nosound();
	sound(G);
	delay(250);
	nosound();
	sound(F);
	delay(250);
	sound(G);
	delay(250);
	sound(2*A);
	delay(250);
	sound(2*Bb);
	delay(500);
	sound(2*A);
	delay(500);
	sound(G);
	delay(250);
	sound(F);
	delay(250);
	sound(D);
	delay(500);
	nosound();

}


void saregama()
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	textcolor(GREEN);
	clrscr();
	gotoxy(35,10);
	cputs("SA RE GA MA......");
	sound(261);delay(500);nosound();
	sound(277);delay(500);nosound();
	sound(293);delay(500);nosound();
	sound(311);delay(500);nosound();
	sound(329);delay(500);nosound();
	sound(349);delay(500);nosound();
	sound(370);delay(500);nosound();
	sound(392);delay(500);nosound();
	sound(415);delay(500);nosound();
	sound(440);delay(500);nosound();
	sound(466);delay(500);nosound();
	sound(494);delay(500);nosound();
	delay(800);
}

void musickeyboard()
{
    char ch='y';
    _setcursortype(_NOCURSOR);
    clrscr();
    gotoxy(25,12);
    cputs("MUSICAL KEYBOARD GIVES YOU FREEDOM");
    gotoxy(25,14);
     cputs("TO CREATE MUSIC WITH YOUR OWN KEYBOARD....");
    gotoxy(30,22);
    cputs("Press X to exit......");
    while(ch !='X'&&ch!='x')
   {
   ch = getch();
   sound(10*ch);
   delay(100);
   nosound();
   }
}

