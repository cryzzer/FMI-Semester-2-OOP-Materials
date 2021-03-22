#pragma once
/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1
* @compiler VC
*/
class Date{
private:
	int day;
	int month;
	int year;

	int maxDaysInMonth();//helpful function for adding/removing days
	void checkChangingDate();//helpful function for adding/removing days

	//helping func for "daysTillXmas" , "daysTillNewYear" and "daysTillNextEvent"
	int countingDaysToCertainDate(int day_, int month_, int year_ = -1);

public:
	Date(int day_ = 1, int month_ = 1, int year_ = 2000);//constructor

	// returning true/false depending if the newDate is after the current one -> true, otherwise false
	bool dateAfterCurrDate(const Date& newDate);

	void addDays(int n);//adding days function
	void removeDays(int n);//removing days function
	bool ifLeapYear();// returning true/false if the year is a leap year or not
	int daysTillXmas();// returning how may days remain to Christmas
	int daysTillNewYear();// returning how may days remain to the end of the year
	int daysTillNextEvent(const Date& currEvent);// returning how may days remain to the next event(date)
	


	void print();
};

