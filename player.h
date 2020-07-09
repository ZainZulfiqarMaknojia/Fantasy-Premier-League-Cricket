#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<bits/stdc++.h>
#include"fashion.h"
using namespace std;
string temp1[3];

class player
{
	public:
		string Name;
		string key;
		string type;
		int total;
	public:
		player()
		{
			Name="NULL";
			key="NULL";
			type="NULL";
			total=0;
		}	
		void add()
		{	
			top:
			string key1;
			int cnt=0;
			ifstream in;
			in.open("player.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist";
			else
			{
				cout<<"\nEnter Player ID: ";
				fflush(stdin);
				getline(cin,key1);
				while(!in.eof())
				{
					in>>key;	in>>Name;	in>>type;
				//	cout<<key<<endl;
					if(key==key1)
					{
						cnt++;
						break;	
					}	
					
				}
				if(cnt==0)
				{
					cout<<"\nNo Player Exist: Enter Again\n";
					goto top;
				}
				
				
			}
		}
	
		void show()
		{
			cout<<key<<"        "<<Name<<endl<<endl;
		}
		string *info()
		{
		
			temp1[0]=key;
			temp1[1]=Name;
			temp1[2]=type;
			return temp1;
			
		}

		void addpoints()
		{
			top:
			extra();	
			ifstream in;
			ofstream out4;
			ifstream out5;
			string key2;
			int cnt=0;
			int total2=0;
			int flag;
			
			
			in.open("player1.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist";
			else
			{
				out4.open("player2.txt",ios::out);
				if(!out4)
					cout<<"\nNo File Exist";
				else
				{
					cout<<"\n\nPlayer ID: ";
					cin>>key2;
					out5.open("player.txt",ios::out);
					if(!out5)
						cout<<"\nNo File Exist";
					else
					{
						while(!out5.eof())
						{
							out5>>key;		out5>>Name;		out5>>type;
							if(key==key2)
							{
								cnt++;
								break;
							}
						}
						if(cnt==0)
							goto top;
						out5.close();	
					}
					
					
					total2=entry();
					cout<<endl<<endl<<"Total Points: "<<total2;
					
					while(!in.eof())
					{
						in>>key;	in>>total;
						if(key==key2)
						{
							out4<<key<<endl;	total2=total2+total;	out4<<total2<<endl;	
						}
						else
						{
							out4<<key<<endl;	out4<<total<<endl;	
						}	
					}
						out4.close();
						in.close();	
					A:
					flag=remove("player1.txt");
					if(flag!=0)
						goto A;
					rename("player2.txt","player1.txt");
						
				}
			
			}
			
			
			
		}
		
		int entry()
		{
			
				int total1=0;
				int run;
				int out;
				char mom;
				//extra();
				if(type=="Batsman"||type == "BATSMAN")
					{
						cout<<"\n\nRuns: ";
						cin>>run;
						total1=0;
						total1=total1+run;
						if(run>=50&&run<100)
							total1=total1+25;
						if(run>=100)
							total1=total1+50;	
						cout<<"\n\nCatches: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
						out=0;
						cout<<"\n\nRunouts: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
						out=0;
						cout<<"\n\nMan OF The Match 'Y'/'N': ";
						cin>>mom;
						if(mom=='Y'||mom=='y')
							total1=total1+50;		
					}
					
					
					if(type=="Bowler"||type=="AllRounder"||type == "ALL-ROUNDER"||type == "BOWLER")
					{
						cout<<"\n\nRuns: ";
						cin>>run;
						total1=0;
						total1=total1+run;
					//		cout<<total1<<endl;
						if(run>=50&&run<100)
							total1=total1+25;
					//	cout<<total1<<endl;	
						if(run>=100)
							total1=total1+50;
					//	cout<<total1<<endl;	
								
						cout<<"\n\nCatches: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
					//	cout<<total1<<endl;
						
						out=0;
						cout<<"\n\nRunouts: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
					//	cout<<total1<<endl;
						
						out=0;
						cout<<"\n\nWickets: ";
						cin>>out;
						out=out*25;
						total1=total1+out;
					//	cout<<total1<<endl;
						
						if((out/25)>=5)
							total1=total1+50;
					//	cout<<total1<<endl;
						cout<<"\n\nMan OF The Match 'Y'/'N': ";
						cin>>mom;
						if(mom=='Y'||mom=='y')
							total1=total1+50;
					//	cout<<total1<<endl;			
					}
					
					if(type=="W.Keeper"||type =="W.KEEPER")
					{
						cout<<"\n\nRuns: ";
						cin>>run;
						total1=0;
						total1=total1+run;
						if(run>=50&&run<100)
							total1=total1+25;
						if(run>=100)
							total1=total1+50;	
						cout<<"\n\nCatches: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
						
						out=0;
						cout<<"\n\nRunouts: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
						
						out=0;
						cout<<"\n\nStumps: ";
						cin>>out;
						out=out*10;
						total1=total1+out;
						
						out=0;
						cout<<"\n\nMan OF The Match 'Y'/'N': ";
						cin>>mom;
						if(mom=='Y'||mom=='y')
							total1=total1+50;	
					//	extra();
	
					}
				return total1;	
		}
		int calculate(string key3)
		{
			ifstream in;
			in.open("player1.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				while(!in.eof())
				{
					in>>key;	in>>total;
					if(key==key3)
					{
						in.close();
						//cout<<total<<endl<<endl<<endl;
						return total;
						
					}
				}
				
			}	
		}
		
		void file4()
		{
			ifstream in;
			ofstream out;
			in.open("player1.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist";
			else
			{
				out.open("player3.txt",ios::app|ios::out);
				if(!out)
					cout<<"\nNo File Exist: ";
				else
				{
					while(!in.eof())
					{
						in>>key;	in>>total;
						if(total>0||total<0)
						{
							total=0;
							out<<key<<endl;	out<<total<<endl;	
						}
						else
						{
							out<<key<<endl;	out<<total<<endl;
						}	
					}
					out.close();
					in.close();	
				}
				remove("player1.txt");
				rename("player3.txt","player1.txt");		
			}	
		}
};

