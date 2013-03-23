
void box(int a, int b, int x=0, int y=0, int ch=0)
{
	int i,j;
     if(ch==0)
     {
		gotoxy(x,y);
		for(i=1;i<=a;++i)
		{
			if(i==1)
				cout<<char(201);
			else if(i==a)
				cout<<char(187);
			else
				cout<<char(205);
		}
		for(j=2;j<b;++j)
		{	
			gotoxy(x,y-1+j);
			cout<<char(186);
			gotoxy(x-1+a,y-1+j);
			cout<<char(186);
		}
		gotoxy(x,y+b-1);
    		 for(i=1;i<=a;++i)
		{	
			if(i==1)
				cout<<char(200);
			else if(i==a)
				cout<<char(188);
			else
				cout<<char(205);
		}
     }
     
	else
     {
		gotoxy(x,y);
		for(i=1;i<=a;++i)
		{
			cout<<char(ch);
		}
		for(j=2;j<=b;++j)
		{	
			gotoxy(x,y-1+j);
			cout<<char(ch);
			gotoxy(x-1+a,y-1+j);
			cout<<char(ch);
		}
		gotoxy(x,y+b-1);
     for(i=1;i<a;++i)
		{	
     cout<<char(ch);
		}
     }
}
