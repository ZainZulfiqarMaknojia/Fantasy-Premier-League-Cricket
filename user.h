#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include"player.h"
#include<bits/stdc++.h>

using namespace std;

 int no=0;
//string line;
int temp5;
int addno()
{
	
	int temp;
	ifstream in;
	in.open("new.txt",ios::in);
	in>>temp;
	in.close();
	return temp;

}
void changeno()
{
	ifstream in;
	ofstream out;
	in.open("new.txt",ios::in);
	out.open("new1.txt",ios::out|ios::app);
	in>>temp5;
	temp5--;
	out<<temp5;
	in.close();
	out.close();
	remove("new.txt");
	rename("new1.txt","new.txt");
}
void swap(int *xp, int *yp)  
{	  
    		int temp = *xp;  
    		*xp = *yp;  
    		*yp = temp;  
		}    
void selectionSort(int arr[], int n,int arr1[])  
{	  
    		int i, j, min_idx;  
  
    		// One by one move boundary of unsorted subarray  
    		for (i = 0; i < n-1; i++)  
    		{  
        	// Find the minimum element in unsorted array  
        		min_idx = i;  
        		for (j = i+1; j < n; j++)  
        			if (arr[j] < arr[min_idx])  
            			min_idx = j;  
  
        			// Swap the found minimum element with the first element  
        		swap(&arr[min_idx], &arr[i]);
				swap(&arr1[min_idx],&arr1[i]);  
    		}  
}
	
class user
{
	private:
		string name;
		string teamname;
		string winingteam;
		int id;
		int score;
		player p[11];
	public:
		user()
		{	
			name="NULL";
			teamname="NULL";
			id=-1;
			score=0;
			
		}
		void signup()
		{
			bool chk;
			fashion();
			A:
			//cout<<"\nEnter ID: ";
			//fflush(stdin);
			//cin>>id;
			//extra();
			
				ifstream in;
				ofstream out;
				in.open("new.txt",ios::in);
				int temp;
				in>>temp;
				id = temp + 1;

			cout<<"\nEnter Name: ";
			fflush(stdin);
			getline(cin,name);
			extra();
			
			
			cout<<"\nEnter Team Name: ";
			fflush(stdin);
			getline(cin,teamname);
			extra();
			

			cout<<"\nEnter Wining Team: ";
			fflush(stdin);
			getline(cin,winingteam);
			extra();
			
			display();
			if(chk=check()!=true)
				goto A;
				
			extra();
			
			for(int i=0;i<11;i++)
			{
				
				p[i].add();
				extra();
			}	

			display();
			cout<<endl<<endl;
			
			for(int i=0;i<11;i++)
			{
				p[i].show();
			}
	
			file();
			file1();
			file2();

			in.open("new.txt",ios::in);
			out.open("new1.txt",ios::out|ios::app);

			in>>temp;
			temp += 1;
			out<<temp;
			in.close();
			out.close();
			remove("new.txt");
			rename("new1.txt","new.txt"); 
			cout<<endl<<endl;
			//system("PAUSE");
			//extra();
			fashion();
			
			
			
		}
		
		bool check()
		{
			char temp;
			cout<<"\n\nEnter 'Y' To Proceed 'N' For Changes: ";
			cin>>temp;
			if(temp=='Y'||temp=='y')
				return true;
			else 
			   	return false;		
		}
		
		void display()
		{
			extra();
			cout<<"ID: "<<id;
			cout<<"\n\nParticipant Name: "<<name;
			cout<<"\n\nTeam Name: "<<teamname;
			cout<<"\n\nWinning Team: "<<winingteam;	
		}
	
		void file()
		{
			ofstream out,out1;
			out.open("user.txt",ios::app|ios::out);
			out1.open("user.csv",ios::app|ios::out);
			if(!out)
				cout<<"\nNo File Exist";
			else
			{
				out<<id<<endl;out<<name<<endl;out<<teamname<<endl;out<<winingteam<<endl;
				out1<<id<<",";out1<<name<<",";out1<<teamname<<",";out1<<winingteam<<endl;
				//out<<score<<endl;	
			}
			out1.close();
			out.close();	
		}
		void file1()
		{
			ofstream out1,out;
			
			string *temp2;
			
			out1.open("user1.txt",ios::app|ios::out);
			out.open("user1.csv",ios::app|ios::out);
			if(!out1)
				cout<<"\nNo File Exist";
			else
			{
				out1<<id<<endl;
				out<<id<<endl;
				for(int i=0;i<11;i++)
				{
					temp2=p[i].info();
					out1<<temp2[0]<<endl;out1<<temp2[1]<<endl;out1<<temp2[2]<<endl;
					out<<temp2[0]<<",";out<<temp2[1]<<",";out<<temp2[2]<<endl;
				}
			}
			out.close();
			out1.close();
		}
		
		void file2()
		{
			
			ofstream out2,out;
			out2.open("user2.txt",ios::app|ios::out);
			out.open("user2.csv",ios::app|ios::out);
			if(!out2)
				cout<<"\nNo File Exist";
			else
			{
				out2<<id<<endl;out2<<score<<endl;
				out<<id<<",";out<<score<<endl;
			}
			out2.close();	
			out.close();	
		}		
		
		void finalize(int i)
		{
			no=addno();
			int finalscore=0;
			ifstream in,in1;
			int cnt=0;
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist";
			else
			{
				in1.open("user1.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist";
				else
				{

						while(!in.eof())
						{
							
							in>>id;	in>>name; in>>teamname;	in>>winingteam;
							
							if(i==id)
							{
							
								while(!in1.eof())
								{
	
									in1>>id;
									for(int a=0;a<11;a++)
									{
										in1>>p[a].key;	in1>>p[a].Name;	in1>>p[a].type;
									}								
									if(i==id)
									{
										for(int j=0;j<11;j++)
										{
											finalscore=finalscore+p[j].calculate(p[j].key);	
											cnt=1;
										}	
									}
									if(cnt==1)
										break;	
								}
								if(cnt==1)
									break;
							}
						}
					
					in1.close();	
				}
				in.close();		
			}	
			int cnt1=0;
			ofstream out,out5;
			in.open("user2.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				out.open("user3.txt",ios::out|ios::app);
				out5.open("user3.csv",ios::out|ios::app);
				if(!out)
					cout<<"\nNo File Exist: ";
				else
				{
					while(cnt1!=no)
					{
						cnt1++;
						in>>id;
						in>>score;
						
						if(i==id)
						{
							finalscore=finalscore+score;
							/*cout<<endl<<endl<<"Total Points: "<<finalscore<<endl<<endl;
							system("PAUSE");
							extra();*/
							
							out<<id<<endl;	
							out<<finalscore<<endl;
							out5<<id<<",";out5<<finalscore<<endl;
						}
						else
						{	
							out<<id<<endl;	
							out<<score<<endl;
							out5<<id<<",";out5<<score<<endl;
						}
						
					}
					cout<<no<<endl;
					out.close();
					out5.close();
					in.close();
				}
				remove("user2.txt");
				rename("user3.txt","user2.txt");
				
				
				remove("user2.csv");
				rename("user3.csv","user2.csv");		
			}	
				
		}
		
		void sort()
		{
			int cnt=0;
			int k=0;
			ifstream in;
			ofstream out,out1;
			no=addno();
			int arr[no];
			int arr1[no];
			in.open("user2.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist";
			else
			{
				while(cnt!=no)
				{
					cnt++;
					in>>id;
					in>>score;
					arr[k]=id;
					arr1[k]=score;
					k++;
				}
			//	cout<<no<<endl;
				in.close();	
			}
			selectionSort(arr1,no,arr);
			out.open("Final.txt",ios::out);
			out1.open("Final.csv",ios::out);
			out1<<","<<","<<","<<","<<","<<","<<"      RAHIMABAD YOUTH AND SPORT BOARD\n";
			out1<<","<<","<<","<<","<<","<<","<<"         DREAM TEAM COMPETITION\n";
			if(!out)
				cout<<"\nNo File Exist";
			out1<<"           Id No";out1<<","<<"       Name"<<","<<"Team Name"<<","<<"         Points\n";	
			int res=0;
		
				for(int i=no-1;i>=0;i--)
				{
					in.open("user.txt",ios::in);
					if(!in)
						cout<<"\nNo File Exist";	
					else
					{
						while(res!=no)
						{
							res++;
							in>>id;	in>>name;	in>>teamname;	in>>winingteam;
							if(id==arr[i])
							{
								out1<<arr[i]<<","<<name<<","<<teamname<<","<<arr1[i]<<endl;
							}
						
						}
						out<<arr[i]<<" "<<arr1[i]<<endl;
						in.close();
					}
					res=0;
				}
				out.close();
				out1.close();	
		}
		void search(int k)
		{
			no=addno();
			ifstream in,in1,in2;
			int cnt=0;
			int temp=0;
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				in1.open("user1.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist ";
				else
				{
					in2.open("user2.txt",ios::in);
					if(!in2)
						cout<<"\nNo File Exist ";
					else
					{
						while(cnt!=no)
						{
						
							in>>id;	in>>name;	in>>teamname; in>>winingteam;
							in1>>id;
							for(int i=0;i<11;i++)
							{
							
								in1>>p[i].key;
								in1>>p[i].Name;
								in1>>p[i].type;	
							}
							in2>>id;	in2>>score;
							if(k==id)
							{
								display();
								cout<<"\n\n";
								for(int i=0;i<11;i++)
								{
									p[i].show();
								}
								cout<<"Total Points: "<<score;
								temp=1;
								break;	
							}
							cnt++;
						}
						if(temp==0)
							cout<<"\nNo Such ID Found ";
					}
					in2.close();	
				}
				in1.close();		
			}
			in.close();	
		}
		void searchname(string n)
		{
			no=addno();
			ifstream in,in1,in2;
			int cnt=0;
			int temp=0;
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				in1.open("user1.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist ";
				else
				{
					in2.open("user2.txt",ios::in);
					if(!in2)
						cout<<"\nNo File Exist ";
					else
					{
						while(cnt!=no)
						{
						
							in>>id;	in>>name;	in>>teamname; in>>winingteam;
							in1>>id;
							for(int i=0;i<11;i++)
							{
							
								in1>>p[i].key;
								in1>>p[i].Name;
								in1>>p[i].type;	
							}
							in2>>id;	in2>>score;
							if(n==name)
							{
								display();
								cout<<"\n\n";
								for(int i=0;i<11;i++)
								{
									p[i].show();
								}
								cout<<"Total Points: "<<score;
								temp=1;
								break;	
							}
							cnt++;
						}
						if(temp==0)
							cout<<"\nNo Such ID Found ";
					}
					in2.close();	
				}
				in1.close();		
			}
			in.close();	
		}		
		void deleteuser(int num)
		{
			ifstream in,in1,in2;
			ofstream out,out1,out2,out3,out4,out5;		
			out3.open("user3.csv",ios::app|ios::out);
			out4.open("user4.csv",ios::app|ios::out);
			out5.open("user5.csv",ios::app|ios::out);
			
			no=addno();
			int cnt=0;
			int count=1;
			
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				in1.open("user1.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist ";
				else
				{
					in2.open("user2.txt",ios::in);
					if(!in2)
						cout<<"\nNo File Exist ";
					else
					{
						out.open("user3.txt",ios::app|ios::out);
						if(!out)
							cout<<"\nNo File Exist ";
						else
						{
							out1.open("user4.txt",ios::app|ios::out);
							if(!out1)
								cout<<"\nNo File Exist ";
							else
							{
								out2.open("user5.txt",ios::app|ios::out);
								if(!out2)
									cout<<"\nNo File Exist ";
								else
								{
												
									while(cnt!=no)
									{
										in>>id;	in>>name;	in>>teamname;	in>>winingteam;
										in1>>id;	
										for(int i=0;i<11;i++)
										{
											in1>>p[i].key;
											in1>>p[i].Name;
											in1>>p[i].type;	
										}
										in2>>id;	in2>>score;
										
										if(num!=id)
										{
											out<<count<<endl;	out<<name<<endl;	out<<teamname<<endl;	out<<winingteam<<endl;
											out1<<count<<endl;
											
											out3<<count<<",";	out3<<name<<",";	out3<<teamname<<",";	out3<<winingteam<<endl;
											out4<<count<<endl;
											for(int i=0;i<11;i++)
											{
												out1<<p[i].key<<endl;
												out1<<p[i].Name<<endl;
												out1<<p[i].type<<endl;
												
												
												out4<<p[i].key<<",";
												out4<<p[i].Name<<",";
												out4<<p[i].type<<endl;
											}
											out2<<count<<endl;	out2<<score<<endl;
											out5<<count<<",";	out5<<score<<endl;
											count++;
										}
										cnt++;	
									}
									out2.close();
								}
								out1.close();
							}
							out.close();
						}
						in2.close();
					}
					in1.close();		
				}
				in.close();
				out3.close();	out4.close();	out5.close();		
			}	
			remove("user.txt");
			remove("user1.txt");
			remove("user2.txt");
			
			rename("user3.txt","user.txt");
			rename("user4.txt","user1.txt");
			rename("user5.txt","user2.txt");
			
			
			remove("user.csv");
			remove("user1.csv");
			remove("user2.csv");
			
			rename("user3.csv","user.csv");
			rename("user4.csv","user1.csv");
			rename("user5.csv","user2.csv");
			
			
			changeno();
			sort();
			
		}
		void deleteusername(string num)
		{
			ifstream in,in1,in2;
			ofstream out,out1,out2,out3,out4,out5;
			out3.open("user3.csv",ios::app|ios::out);
			out4.open("user4.csv",ios::app|ios::out);
			out5.open("user5.csv",ios::app|ios::out);
			no=addno();
			int cnt=0;
			int count=1;
			
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				in1.open("user1.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist ";
				else
				{
					in2.open("user2.txt",ios::in);
					if(!in2)
						cout<<"\nNo File Exist ";
					else
					{
						out.open("user3.txt",ios::app|ios::out);
						if(!out)
							cout<<"\nNo File Exist ";
						else
						{
							out1.open("user4.txt",ios::app|ios::out);
							if(!out1)
								cout<<"\nNo File Exist ";
							else
							{
								out2.open("user5.txt",ios::app|ios::out);
								if(!out2)
									cout<<"\nNo File Exist ";
								else
								{
												
									while(cnt!=no)
									{
										in>>id;	in>>name;	in>>teamname;	in>>winingteam;
										in1>>id;	
										for(int i=0;i<11;i++)
										{
											in1>>p[i].key;
											in1>>p[i].Name;
											in1>>p[i].type;	
										}
										in2>>id;	in2>>score;
										
										if(num!=name)
										{
											out<<count<<endl;	out<<name<<endl;	out<<teamname<<endl;	out<<winingteam<<endl;
											out1<<count<<endl;
											
											out3<<count<<",";	out3<<name<<",";	out3<<teamname<<",";	out3<<winingteam<<endl;
											out4<<count<<endl;
											for(int i=0;i<11;i++)
											{
												out1<<p[i].key<<endl;
												out1<<p[i].Name<<endl;
												out1<<p[i].type<<endl;
												
												
												
												out4<<p[i].key<<",";
												out4<<p[i].Name<<",";
												out4<<p[i].type<<endl;
											}
											out2<<count<<endl;	out2<<score<<endl;
											out5<<count<<",";	out5<<score<<endl;
											count++;
										}
										cnt++;	
									}
									out2.close();
								}
								out1.close();
							}
							out.close();
						}
						in2.close();
					}
					in1.close();		
				}
				in.close();		
			}
			out3.close();	out4.close();	out5.close();	
			remove("user.txt");
			remove("user1.txt");
			remove("user2.txt");
			
			rename("user3.txt","user.txt");
			rename("user4.txt","user1.txt");
			rename("user5.txt","user2.txt");
			
			
			remove("user.csv");
			remove("user1.csv");
			remove("user2.csv");
			
			rename("user3.csv","user.csv");
			rename("user4.csv","user1.csv");
			rename("user5.csv","user2.csv");
			
			changeno();
			sort();
			
		}
		void wining(string abc)
		{
			int no=addno();
			int cnt=0;
			ifstream in,in1;
			ofstream out;
			in.open("user.txt",ios::in);
			if(!in)
				cout<<"\nNo File Exist ";
			else
			{
				in1.open("user2.txt",ios::in);
				if(!in1)
					cout<<"\nNo File Exist ";
				else
				{
					out.open("user6.txt",ios::out|ios::app)	;
					if(!out)
						cout<<"\nNo File Exist ";
					else
					{
						while(cnt!=no)
						{
							in>>id;	    in>>name;	in>>teamname;	in>>winingteam;
							in1>>id; 	in1>>score;
							
							if(abc==winingteam)
							{
								out<<id<<endl;
								score=score+300;
								out<<score<<endl;
							}
							else
							{
								out<<id<<endl;
								out<<score<<endl;
							}
							cnt++;
						}	
					}
					out.close();	
				}
				in1.close();		
			}
			in.close();	
			remove("user2.txt");
			rename("user6.txt","user2.txt");
			sort();
		}
};

