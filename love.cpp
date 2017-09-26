//Love.cpp
#include<iostream>
#include<ctime>
using namespace std;
#include"love.h"
//静态成员初始化
const int Love::days[ ]={0,31,28,31,30,31,30,31,
                         31,30,31,30,31};
//构造函数
Love::Love(int y,int m,int d){SetLove(y,m,d);}
Love::Love(int m,int d){SetLove(m,d);}
Love::Love( ){SystemLove( );}
void Love::SystemLove( )
{	//取得系统日期
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
 {	//重载+
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
  {	//重载-
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
  {	//递增
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
  	cout<<"请输入您的纪念日（月 日）：";
	cin>>mm>>dd;
	Love today(mm,dd);
	xx=today.Loveday(yy);
	if(xx==0)
		cout<<"纪念日快乐!"<<endl;
	else if(xx>0)
		cout<<"还有"<<xx<<"天是您的纪念日。 \n";
	else
	{
		cout<<"恭喜您，又度过一个纪念日。距离上次纪念日已经过去了"<<-xx<<"天，";
		cout<<"距离明年的纪念日您需要再等"<<yy<<"天。 \n"; 
		cout<<"相爱不易，且行且珍惜!";
	} 
	return 0;
  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
