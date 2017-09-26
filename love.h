//love.h
//情书类定义
#ifndef LOVE_H
#define LOVE_H
#include <iostream>
using namespace std;
class Love {
	int day,month,year;
	void IncDay( );
	int DayCalc( ) const;
	static const int days[ ];
	public:
		Love(int y,int m,int d);
		Love(int m,int d);
		Love( );
		void SystemLove( );
		void SetLove(int yy,int mm, int dd);
		void SetLove(int mm,int dd);
		bool IsLeapYear(int yy) const;
		bool IsEndoMonth( ) const;
		void print_ymd( ) const;
		void print_mdy( ) const;
		const Love &operator+(int days);
		const Love &operator+=(int days);
		int operator-(const Love& ymd)const;
		int Loveday(int &);
}; 
#endif
