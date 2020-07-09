#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include"user.h"
#include<windows.h>
#include <time.h>
#include<unistd.h>
#include<MMsystem.h>
using namespace std;
void menu();
time_t now, later;
int number;
int main()
{	
	system("COLOR F3");
	system("CLS");
	cout<<"\t\tWELCOME TO CRICKET WORLD CUP FANTASY PREMIER LEAGUE\n";
	cout<<"\t\t***************************************************\n\n\n\n\n\n\n\n";
	
	system("Color 2F");
	char e=177,f=219;
	cout<<"\t\t\tLoading...\n\n\t\t\t";
	for(int i=0;i<=30;i++)
		cout<<e;
	sleep(1);
	cout<<"\r\t\t\t";
	int y=400;

	for(int i=0;i<=30;i++)
	{
		cout<<f;
		usleep(999999999);
	}
	

	cout<<"\n\n\t\t\t";
	//system("PAUSE");
	extra();	
	
//	PlaySound(TEXT("C:\\Users\\zain\\Desktop\\Dream Team\\pak.wav"),NULL,SND_SYNC);
	
	
	menu();
}



void menu()
{
	char a;int b=0;
	string c;

	cout<<"\n\n\t\t\t1)Enter User\n\n\t\t\t2)Add Players Point\n\n\t\t\t3)Calculate User Score\n\n\t\t\t4)Points Table\n\n\t\t\t5)Search By ID\n\n\t\t\t6)Search By Name\n\n\t\t\t7)Delete By ID\n\n\t\t\t8)Delete By Name\n\n\t\t\t9)Wining Team\n\n\t\t\tPress Any Key To Exit\n\n\t\t\t";
	user u1;
	player u2;
	a=getche();
	number=addno();
	while(1)
	{
		switch(a)
		{
			case '1':
			{
				//fashion();
				u1.signup();
				fashion();		
				break;
			}

			case '2':
			{
				
				//fashion();
				u2.addpoints();
				fashion();
				break;
			}
				
			case '3':
			{
			
				extra();
				for(int i=1;i<=number;i++)
					u1.finalize(i);
				u2.file4();	
				cout<<"\nScores Are Updated\n";
				fashion();	
				break;	
			}
			case '4':
			{
				extra();
				u1.sort();
				extra();
				break;
			}
			case '5':
			{
				extra();
				cout<<"\nEnter Any Id To Search: ";
				cin>>b;
				extra();
				u1.search(b);
				fashion();
				break;	
			}
			case '6':
			{
				extra();
				cout<<"\nEnter Any Name To Search: ";
				fflush(stdin);
				getline(cin,c);
				extra();
				u1.searchname(c);
				fashion();
				break;
			}
			case '7':
			{
				extra();
				cout<<"\nEnter Id To Delete: ";
				fflush(stdin);
				cin>>b;
				extra();
				u1.deleteuser(b);
				fashion();
				break;
			}
			case '8':
			{
				extra();
				cout<<"\nEnter Name Of Participant To Delete It: ";
				fflush(stdin);
				getline(cin,c);
				extra();
				u1.deleteusername(c);
				fashion();
				break;
			}
			case '9':
			{
				extra();
				cout<<"\nEnter The Name Of The Wining Team: ";
				fflush(stdin);
				getline(cin,c);
				extra();
				u1.wining(c);
				fashion();
				break;	
			}		
	
			default:
			{
				exit(0);
				break;
			}
		}
		
		cout<<"\n\n\t\t\t1)Enter User\n\n\t\t\t2)Add Players Point\n\n\t\t\t3)Calculate User Score\n\n\t\t\t4)Points Table\n\n\t\t\t5)Search By ID\n\n\t\t\t6)Search By Name\n\n\t\t\t7)Delete By ID\n\n\t\t\t8)Delete By Name\n\n\t\t\t9)Wining Team\n\n\t\t\tPress Any Key To Exit\n\n\t\t\t";
		a=getche();
	}
}
