//Love.cpp
#include<iostream>
#include<ctime>
using namespace std;
#include"love.h"
//��̬��Ա��ʼ��
const int Love::days[ ]={0,31,28,31,30,31,30,31,
                         31,30,31,30,31};
//���캯��
Love::Love(int y,int m,int d){SetLove(y,m,d);}
Love::Love(int m,int d){SetLove(m,d);}
Love::Love( ){SystemLove( );}
void Love::SystemLove( )
{	//ȡ��ϵͳ����
	tm *gm;
	time_t t =time(NULL);
	gm =gmtime(&t);
	year=1900+gm->tm_year;
	month=gm->tm_mon+1;
	day=gm->tm_mday;
 } 
 void Love::SetLove(int yy,int mm,int dd)
 {
 	month=(mm>=1&&mm<=12) ?mm:1;
 	year=(yy>=1900&&mm<=2900) ?yy:1900;
 	if( month == 2 && IsLeapYear(year) )
 	   day = ( dd>=1 && dd<=29 ) ?dd:1;
 	else
 	   day = ( dd>=1 && dd<=days[month] ) ?dd:1;
 }
 void Love::SetLove(int mm,int dd)
 {
 	tm *gm;
	time_t t =time(NULL);
	gm =gmtime(&t);	
	month=(mm>=1&&mm<=12) ?mm:1;
	year=1900+gm->tm_year;
	if( month == 2 && IsLeapYear(year) )
 	   day = ( dd>=1 && dd<=29 ) ?dd:1;
 	else
 	   day = ( dd>=1 && dd<=days[month] ) ?dd:1;
 }
 const Love &Love::operator +(int days)
 {	//����+
 	for (int i=0;i<days;i++)
	    IncDay( );
	return *this; 
 }
 const Love &Love::operator +=(int days)
 {
 	for (int i=0;i<days;i++)
	    IncDay( );
	return *this; 
  }
  int Love::operator-(const Love& ymd)const
  {	//����-
  	int days;
	days=DayCalc( )-ymd.DayCalc( );
	return days; 
   }
  bool Love::IsLeapYear(int y) const
  {
  	if( y%400 == 0 ||(y%100 !=0 && y%4 == 0) )
  		return true;
  		return false;
  }
  bool Love::IsEndoMonth( ) const
  {
  	if( month == 2 && IsLeapYear(year))
  		return day == 29;
  	else
  		return day == days[month];
  }
  void Love::IncDay( )
  {	//����
  	if(IsEndoMonth( )) 
  		if(month ==12){
  			day=1;
  			month=1;
  			year++;
		  }
		  else{
		  	day=1;
		  	month++;
		  }
		  else day++;
   } 
   int Love::DayCalc( ) const
  {
   	 int dd;
   	 int yy=year-1900;
   	 dd=yy*365;
   	 if(yy)dd+=(yy-1)/4;
   	 for(int i=1;i<month;i++)
   	 	dd += days[i];
   	 if(IsLeapYear(year) && (month>2))
   	 	dd ++;
   	 dd += day;
   	 return dd;
  }
  void Love::print_ymd( ) const
  {
  	cout<<year<<"-"<<month<<"-"<<day<<endl;
  }
  void Love::print_mdy( ) const
  {
  	const char *monthName[12]={"January","February","March","April","May","June","July",
	  						   "Auguest","September","Octorber","November","December"};
  	cout<<monthName[month-1]<<' '<<day<<","<<year<<endl;
  }
  int Love::Loveday(int& y)
  {
  	tm *gm;
  	int yy,mm,dd;
  	time_t t=time(NULL);
  	gm=gmtime(&t);
  	yy=1900+gm->tm_year;
  	mm=gm->tm_mon+1;
  	dd=gm->tm_mday;
  	Love today(yy,mm,dd);
  	int x=DayCalc( )-today.DayCalc( );
	year+=1;
	y=DayCalc( )-today.DayCalc( );
	year-=1;
	return x; 
  }
  #include<iostream>
  using namespace std;
  #include"love.h"
  int main( )
  {
  	int mm,dd,xx,yy;
  	cout<<"���������ļ����գ��� �գ���";
	cin>>mm>>dd;
	Love today(mm,dd);
	xx=today.Loveday(yy);
	if(xx==0)
		cout<<"�����տ���!"<<endl;
	else if(xx>0)
		cout<<"����"<<xx<<"�������ļ����ա� \n";
	else
	{
		cout<<"��ϲ�����ֶȹ�һ�������ա������ϴμ������Ѿ���ȥ��"<<-xx<<"�죬";
		cout<<"��������ļ���������Ҫ�ٵ�"<<yy<<"�졣 \n"; 
		cout<<"�మ���ף���������ϧ!";
	} 
	return 0;
  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
