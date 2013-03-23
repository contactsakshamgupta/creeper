

/********************************tic tac toe************************/

void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
int win=0,wrong_X=0,wrong_O=0,chk=0;

char name_X[30];
char name_O[30];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

void ttt()
{
	int i,ch,j;
	char ans;

	do
	{
		clrscr();
		printf("\n\t\t\t\tTIC TAC TOE");
		printf("\n\t\t\t\t");
		for(i=1;i<=11;i++)
		{
			delay(100);
			printf("*");
		}
		printf("\n1.Start The Game");
		printf("\n2.Quit The Game");
		printf("\nEnter your choice(1-2) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				chk=0;
				win=0;
				for(i=1;i<=3;i++)
				{
					for(j=1;j<=3;j++)
					{
						pos_for_X[i][j]=0;
						pos_for_O[i][j]=0;
						pos_marked[i][j]=0;
					}
				}
				printf("\n\n");
				clrscr();
				printf("\nEnter the name of the player playing for \'X\': ");
				fflush(stdin);
				gets(name_X);
				printf("\nEnter the name of the player playing for \'O\': ");
				fflush(stdin);
				gets(name_O);
				Board();
				for(;;)
				{
					if(win==1)
						break;
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS!!");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_X);
					PlayerX();
					do
					{
						if(wrong_X!=1)
							break;
						wrong_X=0;
						printf("\nTURN FOR %s:",name_X);
						PlayerX();
					}while(wrong_X==1);
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_O);
					PlayerO();
					do
					{
						if(wrong_O!=1)
							break;
						wrong_O=0;
						printf("\nTURN FOR %s:",name_O);
						PlayerO();
					}while(wrong_O==1);

					}
				Board();
				if(win!=1)
				{
					printf("\n\t\t\tMATCH DRAWS!!");
					printf("\nPress any key.......");
				}
				getch();
				break;
			case 2:
				printf("\n\n\n\t\t\tThank You For Playing The Game.");
				printf("\n\t\t\t###############################");
				getch();
				exit(1);
				break;
		}
		printf("\nWant To Play(Y/N) ? ");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
}


void Board()
{
	int i,j;
	clrscr();
	printf("\n\t\t\t\tTIC TAC TOE BOARD");
	printf("\n\t\t\t\t*****************");
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3");
	for(i=1;i<=3;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\tบ\t  บ\t   บ\t     บ");
		printf("\n\t\t%d\t",i);
		for(j=1;j<=3;j++)
		{

			if(pos_for_X[i][j]==1)
			{
				printf("    X");
				printf("     ");
			}
			else if(pos_for_O[i][j]==1)
			{
				printf("    O");
				printf("     ");
			}
			else
			{
				printf("          ");
				continue;
			}
		}
		printf("\n\t\t\tบ\t  บ\t   บ\t     บ");
	}
	printf("\n\t\t\t------------------------------");
	Player_win();
}


void PlayerX()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	fflush(stdin);
	scanf("%d",&row);
	printf("Enter the column no. : ");
	fflush(stdin);
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key.....");
		wrong_X=1;
		getch();
		Board();
	}
	else
	{
		pos_for_X[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void PlayerO()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	scanf("%d",&row);
	printf("Enter the column no. : ");
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key....");
		wrong_O=1;
		getch();
		Board();
	}
	else
	{
		pos_for_O[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void Player_win()
{
	int i;
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[i][1]==1 && pos_for_X[i][2]==1 && pos_for_X[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[1][i]==1 && pos_for_X[2][i]==1 && pos_for_X[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	if(pos_for_X[1][1]==1 && pos_for_X[2][2]==1 && pos_for_X[3][3]==1)
	{
		win=1;
		printf("\n\nRESULTL: %s wins!!",name_X);
		printf("\nPress any key......");
		return;
	}
	else if(pos_for_X[1][3]==1 && pos_for_X[2][2]==1 &&
pos_for_X[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_X);
		printf("\nPress any key.....");
		return;
	}

	for(i=1;i<=3;i++)
	{
		if(pos_for_O[i][1]==1 && pos_for_O[i][2]==1 && pos_for_O[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_O[1][i]==1 && pos_for_O[2][i]==1 && pos_for_O[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	if(pos_for_O[1][1]==1 && pos_for_O[2][2]==1 && pos_for_O[3][3]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
	else if(pos_for_O[1][3]==1 && pos_for_O[2][2]==1 &&
pos_for_O[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
}
void check()
{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(pos_marked[i][j]==1)
				chk++;
			else
				continue;
		}
	}
}


/*********************************************************************/


/**************************QUIZ******************************/


char a,b,c,d[5];
int i=0,j=0,z=0,f=10,A=0,W=0,ro=0,v=0;
void check(char a,char g)
{
int q;					      //Starting of the function
cout<<"Your answer is-";delay(500);
gets(d);
b=d[0];
if(b=='q' || b=='Q')
{if(ro<=3)
sound(500);
delay(1000);
nosound();
clrscr();
cout<<"\n\n\n\n\n\n";
cout<<"\t\t    ษออออออออออออออออออออออออออออออป \n";
cout<<"\t\t    บ   Come prepared next time    บ \n";
cout<<"\t\t    ศออออออออออออออออออออออออออออออ1/4 \n";
delay(2000);
exit(0);}
else
{
if(b=='h'||b=='H')
{if(f==0)
{cout<<"You finished your help cards\n";delay(500);
cout<<"No further help can be provided\n";delay(1000);}
else
{
cout<<"Help Card Used\n";
cout<<"ฺฤฤฤฤฤฤฤฟ\n";
cout<<"ณ       ณ\n";
cout<<"ณ   H   ณ\n";
cout<<"ณ       ณ\n";
cout<<"ภฤฤฤฤฤฤฤู\n";
cout<<"Option "<<g<<" is not the correct one\n";
delay(500);
f--;
cout<<"Your answer is-";delay(500);
gets(d);
b=d[0]; }}
cout<<"checking";delay(200);
for(q=0;q<=3;q++)
{cout<<".";delay(500);}
cout<<"\n";
if(b==a||b==a+32)
{
i++;
A++;
if(A%3==0&&A%6!=0||A==0)
{cout<<"Oops!\n";delay(2000);}
else
if(A%4==0||A==1)
{cout<<"Oh!no \n";delay(2000); }
else
if(A%2==0&&A%5!=0)
{cout<<"Oh!\n";delay(2000);     }
else
if(A%5==0)
{cout<<"Luck!\n";delay(2000);  }
cout<<"Its the Correct answer \n";
delay(1000);
}
else
{
W++;

if(W%4==0||W==0)
{cout<<"Gone wrong this time \n";delay(2000); }
else
if(W%2==0&&A%5!=0)
{cout<<"Oh!no\n";delay(2000);       }
else
if(W%5==0)
{
cout<<"Bad luck\n";delay(2000);   }
for(int q=500;q<1000;q=q+500)
{ sound(q);
delay(500);}
nosound();
cout<<"Its the Wrong answer \n";
delay(1000);
cout<<"Option ("<<a<<") is the correct option\n";
j++; }
cout<<"ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
}}                                                   //Ending of the function
void con()
{ cout<<"\t\t ษออออออออออออออออออป \n";
  cout<<"\t\t บ Congratulations! บ \n";
  cout<<"\t\t ศออออออออออออออออออ1/4 \n";delay(1000);
  }
void quiz()
{clrscr();
delay(2000);
cout<<"\n\n\n\n\t\t    ฐ Welcome";delay(1000);
cout<<" to";delay(1000);
cout<<" the";delay(1000);
cout<<" Quiz";delay(1000);
cout<<" World ฐ "; delay(1000);
cout<<"\n\t\t   อออออออออออออออออออออออออออออออ";delay(1000);
clrscr();
cout<<"Enter 'i' for the instructions and 'f' for getting started with the             introductry round-";delay(2000);
cin>>c;
if(c=='I'||c=='i')
{
clrscr();

delay(2000);
cout<<"\n\t\t\t  ษออออออออออออออป  ";
cout<<"\n\t\t\t  บ Instructions บ  ";
cout<<"\n\t\t\t  ศออออออออออออออ1/4  \n";
cout<<"ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n";delay(1000);
cout<<"1ฏ You have to answer each question by typing the correct option                \n";delay(1000);
cout<<"2ฏ Each correct question will earn 1 mark for you                               \n";delay(1000);
cout<<"3ฏ To continue with the game you have to qualify each round by scoring the      appropriate marks \n\n";delay(1000);
cout<<"4ฏ The no. of questions in each round vary from 5-10 and so does the qualifing     marks           \n\n";delay(1000);
cout<<"5ฏ Whenever you want to quit just enter q or Q in place of option                \n";delay(1000);
cout<<"6ฏ You can ask for different types of helps 10 times throughout the quiz just by pressing 'h'or'H'	\n";delay(1000);
cout<<"7ฏ Help or Quit options can be used only in the first try of the question	\n";delay(1000);
cout<<"8ฏ Scores will be displayed before entering the next round                       \n";delay(1000);
cout<<"ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n";delay(1000);
delay(8000);}
clrscr();
cout<<"\n\t\t   ษออออออออออออออออออออออออออออออออออออป";
cout<<"\n\t\t   บ            Welcome                 บ";
cout<<"\n\t\t   บ              to 		        บ";
cout<<"\n\t\t   บ             the                    บ";
cout<<"\n\t\t   บ         selection round	        บ";
cout<<"\n\t\t   ศออออออออออออออออออออออออออออออออออออ1/4\n";delay(3000);
cout<<"Qualifying score-7 out of 10\n";delay(2000);z=3;
cout<<"ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n";
cout<<"Your first question is- \n";
cout<<"In what age did sachin tendulkar started his career?\n";
cout<<"options-"<<"\n a)17 \t b)16 \nc)18 \td)19\n";
check('b','c');
cout<<"\nYour second question is-\n";
cout<<"Who is the longest living animal among these(150 years)?\n";
cout<<"options-"<<"\n a)elephant \tb)man \nc)blue whale\t d)tortoise\n";
check('d','b');
cout<<"\nYour third question is-\n";
cout<<"Which golfer won the USA-PGA title 2004?\n";
cout<<"options-"<<"\n a)Dig vijay singh \t b)Donald Rudolf \n c)Tiger Woods \t d)Jaws Jacob \n";
check('a','d');
cout<<"\nYour Fourth question is-\n";
cout<<"Which of these won the noble prize for peace 2004?\n";
cout<<"options-"<<"\n a)Linda B Buck \t b)David J Gross \n c)Wangari mathaai \t d)Irwin Rose \n";
check('c','b');
cout<<"\nYour Fifth question is-\n";
cout<<"Name the recent satellite launched by India\n";
cout<<"options-"<<"\n a)Virgin \t b)Insat5 \n c)Agni 2 \t d)Edusat \n";
check('d','a');
cout<<"\nYour sixth question is-\n";
cout<<"Which is the largest effected country by Tsunami waves \n";
cout<<"options-"<<"\na)Indonasia \tb)India \n c)SriLanka \t d)Maldwip \n";
check('a','b');
cout<<"\nYour Seventh question-\n";
cout<<"What is Graphology?\n";
cout<<"options-\n a)Representing a data in Graphics \t b)Study of hand writing \n c)Study of ancient inscriptures \t d)Study of Computer graphics \n";
check('b','d');
cout<<"\nEigth question-\n";
cout<<"Which of these won the Olympic Gold medal in 2004 for Long jump(Females)\n";
cout<<"options-\na)Yokohama \t b)Tatyana Lebedeva \n c)Heike Drechsler \t d)Gennady Chernoval \n";
check('b','c');
cout<<"\nNinth question\n";
cout<<"Where was the first Asian-All-Star Championship held?\n";
cout<<"options\na)New Delhi \t b)Bangkok \n c)Tokyo \t d)Singapore \n";
check('d','a');
cout<<"\n Last question to pass to the second round \n";
cout<<"Which of these Authors won the noble prize in literature  for India\n";
cout<<"options-"<<"\n a)R.K Narayan \t b)Rabindra nath tagore \n c)R.c.Lahoti \t d)R.C Nath \n";
check('b','c');
ro++;
if(i>=7)
{
clrscr();
con();
clrscr();
cout<<"\tYou scored-"<<i<<"\n";i=0;
delay(1000); clrscr();
cout<<"\n\n\n\n";
cout<<"\t\t\tษออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the first round  บ\n";
cout<<"\t\t\tศออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"	Qualifying score- 7 out of 10\n";delay(1000);
z=2;
delay(1000);
clrscr();
cout<<"\nFirst question-\n";
cout<<"At which play ground did anil kumble took his 434th wicket\n";
cout<<"options-"<<"\n a)Oval stadium \t b)Edden Gardens \n c)National stadium  \t d)Nehru stadium \n";
check('b','c');
cout<<"\nSecond question\n";
cout<<"Which motor company got the contract of desighning the Ferarri race car engines ";
cout<<"options-"<<"\na)Toyota \t b)Yamaha \n c)Tata \t d)Mistubushi \n";
check('c','d');
cout<<"\nThird question\n";
cout<<"Who is the president of South Africa\n";
cout<<"options-"<<"\n a)Avram Hershko \tb)H.David Politzer \n c)Frank Wilczek \t d)Thabo Mbeki \n";
check('d','b');
cout<<"\nFourth question is-\n";
cout<<"When was the World Trade Centre slammed by aeroplanes by Al-qaeda?\n";
cout<<"options-"<<"\n a)11.9.2001 \t b)9.11.2001 \n c)8.10.200\t d)11.8.2001 \n";
check('a','c');
cout<<"\nFifth question is-";
cout<<"\nWhich company owns India's first offshore drilling rig ?\n";
cout<<"options-"<<"\n a)Indian oil \tb) ONGC \n c)HP \t d)Bharat Petroleum \n";
check('b','c');
cout<<"\nSixth question is-\n";
cout<<"What is the fullform of AAG\n";
cout<<"options-\n a)Airport Authority General \t b)American Association of Global issues \n c)Army Authority General \t d)Afro Asian Games \n";
check('d','b');
cout<<"\nSeventh question is-\n";delay(500);
cout<<"Which American President won the Presidential election with the maximum number    of votes?\n";
cout<<"options-\n a)George W Bush \t b)Bill Clinton \n c)A.Lincon \t d)Washington Bush\n";
check('a','b');
clrscr();
cout<<"\nEigth question is-\n";delay(500);
cout<<"In which year did Pakistan joined the UN?\n";
cout<<"options-\n a)1980 \t b)1960 \n c)1950\t d)1947\n";
check('d','a');
cout<<"\nNinth question is-\n";delay(500);
cout<<"On which planet is the lagest volcano of the solar system?\n";
cout<<"options-\n a)Jupiter \t b)Mars\n c)Saturn\t d)Earth\n";
check('b','d');
cout<<"\nLast question is-\n";delay(500);
cout<<"In which sport India won a gold medal in Para olympics?\n";
cout<<"options-\n a)Wheel chair racing\t b)Long jump\n c)Javelin throw\t d)100-meter race\n";
check('b','d');
if(i>=7)
{
clrscr();
con();
clrscr();
cout<<"\n\n\n\n";
cout<<"\t\t\tษอออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the second round  บ\n";
cout<<"\t\t\tศอออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"You entered the second round scoring-"<<i;i=0;delay(1000);
cout<<"\nQualifying score-7 out of 10 \n";delay(1000);
z=3; clrscr();
cout<<"\nFirst question is-\n";
cout<<"Which team won the champians trophy -2004";
cout<<"\noptions-"<<"\n a)Australia \t b)England \n c)West Indies \t d)Newzealand\n";
check('c','d');
cout<<"\nSecond question is-\n";
cout<<"How many players does a team have in rugby Football\n";
cout<<"options-"<<"\n a)12 \t b)16 \n c)10 \t d)15\n";
check('d','a');
cout<<"\nThird question is-\n";
cout<<"With which game is Naidu Trophy associated \n";
cout<<"options-\n a)Chess \t b)Air Racing \n c)Boat rowing \t d)Hockey \n";
check('a','d');
cout<<"\nFourth question is -\n";
cout<<"How many players does a team have in baseball \n";
cout<<"options-\n a)4 \t b)9 \n c)6 \t d)7\n";
check('b','d');
cout<<"\nFifth Questions-\n";
cout<<"After how many years are asian games held\n";
cout<<"options-\n a)3 \t b)5 \n c)2 \t d)4\n";
check('d','b');
cout<<"\nSixth question is-\n";
cout<<"What is the maximum length of a cricket bat\n";
cout<<"options-\n a)26 \t b)36 \n c)38 \t d)30 \n";
check('c','a');
cout<<"\nSeventh question-\n";
cout<<"With which sport is the term 'Spot Stroke' associated\n";
cout<<"options-\n a)Billiards \t b)Golf \n c)Swimming \t d)Rowing\n";
check('a','b');
cout<<"\nEigth question\n";
cout<<"Where were the 2000 olympics held?\n";
cout<<"options-\n a)Los Angeles \t b)Sydney \n c)Beijing \t d)Berlin\n";
check('b','a');
cout<<"\nNinth question-\n";
cout<<"In which country is the Oval stadium situated\n";
cout<<"options-\n a)Australia \t b)South Africa \n c)West Indies \t d)England\n";
check('d','c');
cout<<"\nLast question of the round\n";
cout<<"Where were the first Afro-Asian Games held?\n";
cout<<"options-\n a)Tokyo \t b)Bangkok \n c)Beijing \t d)New Delhi\n ";
check('d','b');ro++;
if(i>=7)
{clrscr();
con();
clrscr();
cout<<"\t\t\tษออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the third round  บ\n";
cout<<"\t\t\tศออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"You entered the Third round by scoring-"<<i;delay(1000);
i=0;
delay(1000);
cout<<"\nQualifying score-7 out of 10\n";delay(1000);
clrscr();
cout<<"\n First question of the round\n";z=3;
cout<<"Which Indian Nuclear Scientist died in the year 2004?\n";
cout<<"options-\n a)Dr.Homi.J.Bhabha \t b)Dr.Anil Kakodkav \n c)Dr.Ramanna \t d)P.K.Iyengar\n";
check('c','b');
cout<<"\nSecond question is-\n";
cout<<"Who is the father of nuclear physics?\n";
cout<<"options-\n a)Ernst Rutherford \t b)Neils Bohr \n c)Micheal Faraday \t d)Einstein \n";
check('a','c');
cout<<"\nThird question is-\n";
cout<<"Which scientist has been conferred the International Committee for             Non-Destructive Testing(ICNDT)research?\n";
cout<<"options-\n a)Richard Axel(USA) \t b)Dr.Baldev Raj(INDIA) \n C)Frank Wilczek(USA) \n d)Irwin Rose(UK)\n";
check('b','c');
cout<<"\nFourth question \n";
cout<<"Which instrument is used to measure the relative humidity of atmosphere?\n";
cout<<"options-\n a)Hygroscope \t b)Barometre \n c)Quartzmeter \t d)Hygrometer \n";
check('d','a');
cout<<"\nFifth question \n";
cout<<"Which civilization is regarded as the inventer of the wheel?\n";
cout<<"options-\n a)Egyptian \t b)Sumerian \n c)Roman \t d)Indus valley\n";
check('b','d');
cout<<"\nSixth question-\n";
cout<<"Which country has the largest constellation of remote-sensing satellites in orbit?\n";
cout<<"options-\n a)USA \t b)Russia \n c)India \t d)Britain\n";
check('c','d');
cout<<"\nSeventh question-";
cout<<"Who invented Telephone?\n";
cout<<"options-\n a)Alexander Grahmbell \t b)John Bardeen\n c)Alexander Gutenburg \t d)John Froclich\n";
check('a','b');
cout<<"\nEigth question is-\n";
cout<<"Which country's scientist bagged 3 noble prizes in the year-2004\n";
cout<<"options-\n a)Russia \t b)Israel \n c)USA\t d)UK\n";
check('c','b');
cout<<"\nNinth question-\n";
cout<<"Which scientist gave the general relativity theory?\n";
cout<<"options-\n a)Neils Bohr \t b)Micheal Faraday \n c)Ernst Rutherford \t d)Albert Einstein\n";
check('d','a');
cout<<"\nTenth question-\n";
cout<<"Steam engine was invented by which of these ?\n";
cout<<"options-\n a)Thomas Savery\t b)James Watt \n c)Thomas Newcom\t d)Alexender Grahmbell\n";
check('b','d');
ro++;
if(i>=7)
{clrscr();
con();
clrscr();
cout<<"\t\t\tษอออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the fourth round  บ\n";
cout<<"\t\t\tศอออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"\n You entered the Fourth round by scoring-"<<i;delay(1000);
cout<<"\n Qualifying score-7 out of 10\n";
z=3;delay(1000);
clrscr();
cout<<" Are you aware about the present situation of our Economy\n";delay(1000);
cout<<"If no then it is a real bad luck for you!Because this round is based on the same feild\n";delay(1000);
clrscr();i=0;
cout<<"\nFirst question of the round";
cout<<"\n Which of the following Buissnessmen was honoured as the CEO of the year at the International level?\n";
cout<<"options-\n a)Richard Ferrari \t b)R.Frankson \n c)Anil Ambani \t d)R.Frank Toyota \n";
check('c','b');
cout<<"\nSecond question is-\n";
cout<<"Which of the following Indians won the South-Asean Buissnessman of the year\n";
cout<<"options-\na)Ratan Tata \t b)Mukesh Ambani \n c)Arun Birla \t d)Azim H Premji\n";
check('a','d');
cout<<"\nThird question-\n";
cout<<"Which Steel Corporation is the World's largest steel producing company\n";
cout<<"options-\n a)Tata steel plant\t b)Mittal steel corp.\n c)The US steels corp.\t d)The U.K steels\n";
check('b','a');
cout<<"\Fourth question-\n";
cout<<"Which is the richest Indian according to the Forbes Maiden List\n";
cout<<"options-\n a)Azim H Premji \t b)Mukesh Ambani \n c)Kumar M Birla \t d)Sunil Mittal\n";
check('d','c');
cout<<"\nFifth question-\n";
cout<<"Which company has been addressed as the best employer in India\n";
cout<<"options-\n a)Bharti Televentures(BT) \t b)National Thermal Power Corporastion(NTPS) \n c)Tata Consultancy Services(TCS) \t d)Godrej Consumer Products(GCP)\n";
check('c','b');
cout<<"\nSixth question is-\n";
cout<<"India's share of World's GDP is-(5.7%).What is its position as a Global economy?\n";
cout<<"options-\n a)4th \t b)6th \n c)7th \t d)9th\n";
check('a','c');
cout<<"\nSeventh question is-\n";
cout<<"With which country's Space Organisation had ISRO sighned an Agreement to form a Joint Venture company?\n";
cout<<"options-\n a)Russia \t b)Malaysia \n c)USA \n d)Sri Lanka\n";
check('b','c');
cout<<"\nEigth question-\n";
cout<<"Who awarded the Citizen of the world award?\n";
cout<<"options-\na)Ariel Sharon \tb)George W Bush \nc)Kofi Anann d)Yaseer Arafat\n";
check('c','d');
cout<<"\nNinth question is-\n";
cout<<"Which company won the Golden Peacock award-2004 for corporate social responsibility?\n";
cout<<"options-\n a)Reliance Industries \t b)Birla Group \n c)Tata Motors \t d)Indian Oil \n ";
check('c','d');
cout<<"\nTenth question is-\n";
cout<<"Who was the Indian Buisness leader of the year 2004?\n";
cout<<"options-\n a)Rahul Bajaj(Bajaj Auto) \t b)Subir Rana(CMD,ONGC) \n c)Anil Ambani(RIL) \td)Azim H Premji\n";
check('d','a');
ro++;
if(i>=6)
{ clrscr();
con();
clrscr();
cout<<"\t\t\tษออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the fifth round  บ\n";
cout<<"\t\t\tศออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"You entered the Fifth round scoring"<<i<<"\n";delay(1000);
cout<<"Qualifying score-7 out of 10\n";delay(1000);
i=0;
z=3;
cout<<"You may be interested in the various Automobiles either luxurious or sports \n";delay(1000);
cout<<"This is the correct round to check the depth of your intrest";i=0;delay(1000);
clrscr();
cout<<"\n First question of the round-\n";
cout<<"Cielo (car) is a product of which company?\n";
cout<<"options-\na)Hyundai \t b)Daewoo\n c)Mistibushi \t d)Maruti-Suzuki\n";
check('b','d');
cout<<"\nSecond question-\n";
cout<<"Which company is planning to produce a One-Lakh car in India?\n";
cout<<"options-\n a)Maruti-Suzuki \t b)Honda \n c)Tata \t d)Hyundai \n";
check('c','b');
cout<<"\nThird question-\n";
cout<<"Matiz(car) is a product of which company?\n";
cout<<"options-\n a)Daewoo \t b)Suzuki \n c)Tata \t d)Hyundai \n";
check('a','c');
cout<<"\nFourth question-\n";
cout<<"Which country got the contract of designing the Farrari race-car engines recently?\n";
cout<<"options-\n a)Toyota \t b)Mistibushi \n c)Honda t d)Tata \n";
check('d','b');
cout<<"\nFifth question-";
cout<<"In the year 2004 an Indian company sold 10000 cars of same model to Bangladesh.\n Name the car.";
cout<<"options-\n a)IndicaV-2 \t b)Maruti 800 \n c)Santro Xing \t d)Sonata\n";
check('a','c');
cout<<"\nSixth question-\n";
cout<<"Palio is the product of which company?\n";
cout<<"options-\n a)Daewoo \t b)Tata \n c)Fiat \t d)Maruti-Suzuki\n";
check('c','d');
cout<<"\nSeventh question-\n";
cout<<"Unicorn(Bike) is the product of which company?\n";
cout<<"options-\n a)Yamaha \t b)HeroHonda \n c)Kinetic \t d)T V S \n";
check('b','a');
cout<<"\nEigth question-\n";
cout<<"Crolla is the product of which company?\n";
cout<<"options-\na)Mistibushi \t b)Chevrolet \n c)Tata \t d)Toyota \n";
check('d','c');
cout<<"\nNinth question-\n";
cout<<"Accent is the product of which company?\n";
cout<<"options-\n a)Hyundai \t b)Daewoo \n c)Honda \t d)Mahindra\n";
check('a','d');
cout<<"\nLast question-\n";
cout<<"Scorpio is the product of which company ?\n";
cout<<"options-\n a)Tata \t b)Toyota \n c)Mahindra \t d)Honda\n";
check('c','a'); ro++;
cout<<"Got bored of the names of the cars and company\n";delay(1000);
cout<<"Here is a round about Politics which would break away your sleep by the means of tension\n";delay(1000);
if(i>=7)
{clrscr();
con();
cout<<"\t\t\tษออออออออออออออออออออออออออออออป\n";
cout<<"\t\t\tบ   Welcom to the sixth round  บ\n";
cout<<"\t\t\tศออออออออออออออออออออออออออออออ1/4\n";delay(1000);
cout<<"You scored" <<i<<"in the previous round\n";delay(1000);
cout<<"Qualifying score is 7 out of 10 \n";delay(1000);i=0;z=3;
cout<<"\nFirst question-\n";
cout<<"Who is the Defence minister of India?\n";
cout<<"options-\n a)B.K Mishra\t b)Pranab Mukherjee \n c)B.K Chaturvedi \t d)G.C Malhotra\n";
check('b','d');
cout<<"\nSecond question-\n";
cout<<"Ram Vilas paswan is the minister of which of the following-?\n";
cout<<"options-\n a)Communication and IT \tb)Water Resources \n c)Rural Development \t d)Chemicals and Fertilizers \n";
check('d','a');
cout<<"\nThird question-\n";
cout<<"Who is the minister of Mines and Minerals?\n";
cout<<"options-\n a)Shivraj Patil \tb)Jaipal Reddy\nc)Shibu Soren\t d)H.R Bhardwaj\n";
check('c','a');
cout<<"\nWho is the Minister ofYouth affairs and sports?\n";
cout<<"options-\n a)Sunil Dutt\tb)M.S Aiyar\nc)P.M Sayeed\t d)Kamal Nath\n";
check('a','c');
cout<<"Fourth question-\n";
cout<<"\nWho is the Chief Justice of India?\n";
cout<<"options-\n a)Milon Kumar Banerjee \tb)R.C Lahoti \n c)Ashok Aggarwal\t d)B.I Dutta\n";
check('b','d');
cout<<"\nFifth question-\n";
cout<<"Who is the Railway Minister of India?\n";
cout<<"options-\n a)Meira Kumar \tb)A.Raja \n c)Laloo Prasad Yadav\t d)Akhilesh Singh\n";
check('c','a');
cout<<"\nSixth question-\n";
cout<<"Who is the Vice-President of India?\n";
cout<<"options-\n a)L.K Advani\tb)Natwar Singh \n c)Arjun Singh\t d)Bhairon Singh Shekhawat\n";
check('d','b');
cout<<"\nSeventh question-\n";
cout<<"Who is the speaker of Lok Sabha of India?\n";
cout<<"options-\n a)Sharad Pawar \tb)Suryakant Patil\n c)Prem Chand Gupta \t d)Somnath Chatterjee \n";
check('d','a');
cout<<"\nEigth question-\n";
cout<<"Who is the speaker of Lok Sabha of India?\n";
cout<<"options-\n a)Sharad Pawar \tb)Suryakant Patil\n c)Prem Chand Gupta \t d)Somnath Chatterjee \n";
check('d','a');
cout<<"\nNinth question-\n";
cout<<"Who is the Home minister of India\n";
cout<<"options-\n a)Shivraj Patil \t b)Bhairon singh shekhawat \n c)Akhilesh Singh \t d)Arjun singh rana \n";
check('a','d');
cout<<"\nTenth question-\n";
cout<<"Who is the Lt.Governor of Delhi\n";
cout<<"options-\n a)Somnath Chaterjee \t b)BL Joshi\nc)Rajan Pandey\t d)Akhilesh Pandit\n";
ro++;
if(i>=7)
{  con();
   cout<<"\t\t ษอออออออออออออออป \n";
   cout<<"\t\t บ    You Won    บ \n";
   cout<<"\t\t ศอออออออออออออออ1/4 \n";delay(1000);
   cout<<"\t\t ษอออออออออออออออป \n";
   cout<<"\t\t บ   Game over   บ \n";
   cout<<"\t\t ศอออออออออออออออ1/4 \n";delay(1000);     }
else
 f:{  clrscr();
   cout<<"\t\t\t ษออออออออออออออออป \n";
   cout<<"\t\t\t บ    You lost    บ \n";
   cout<<"\t\t\t ศออออออออออออออออ1/4 \n";delay(1000); }
}
else
goto f;}
else
goto f;}
else
goto f;}
else
goto f;}
else
goto f;}
else
goto f;
getch();

}


/***************************************************************/





void game()
{
		textbackground(BLACK);
		textcolor(WHITE);
		_setcursortype(_NOCURSOR);
		clrscr();
		int v;
		int pos[10][2] ={ {2,3},{4,10},{49,15},{9,6},{65,20},{24,5},{50,19},{42,3},{5,17},{68,6} };
		int i;
		for(i=0;i<10;++i)
		{
			gotoxy(pos[i][0],pos[i][1])  ;
			cout<<char (1);
			delay(800);
		}
		gotoxy(30,12);
		cputs("WELCOME !!!");
		delay(1200);
	do
	{
		textbackground(BLACK);
		textcolor(WHITE);
		_setcursortype(_NORMALCURSOR);
		clrscr();
		textcolor(GREEN+BLINK);


		box(35,5,22,3);
		gotoxy(29,5);
		textcolor(WHITE);
		cputs(">>>> GAME ZONE  >>>>");

		for(int i=0;i<13;++i)
		{
			box(1+(6*i),1+i,3,11,1);
			delay(80);
			box(1+6*i,1+i,3,11,(' '));

		}
			box(76,14,3,11,1);
		textcolor(WHITE);
		gotoxy(5,13);
		cputs("1. TIC TAC TOE ");
		gotoxy(5,15);
		cputs("2. QUIZ");
		gotoxy(5,17);

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
				ttt();
			      break;
			case 2:
				quiz();
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
