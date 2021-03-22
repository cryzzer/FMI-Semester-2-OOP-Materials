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
#include "Date.hpp"

#include <iostream>
using namespace std;



Date::Date(int day_, int month_, int year_ ) {
	this->day = day_;
	this->month = month_;
	this->year = year_;
}

int Date::maxDaysInMonth() {
	int maxDays = 0;
	
	//deciding how many days each month has
	//these have 31
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		maxDays = 31;
	}

	//for February this algorithm decides if this year is a leap year
	else if (month == 2) {
		if (year % 4 == 0) {//must be divisible by 4 
			maxDays = 29;
			if (year % 100 == 0) {// NOT divisible by 100
				maxDays = 28;
				if (year % 400 == 0) {// and divisible by 400
					maxDays = 29;
				}
			}
		}
		else {// if its not a leap year it has 28 days
			maxDays = 28;
		}
	}
	else {//for all the remaining months, the max days are 30
		maxDays = 30;
	}
	return maxDays;
}

void Date::checkChangingDate() {
	//while date is not in certain format, do all these operations
	while (true) {
		int maxDaysInMonth = Date::maxDaysInMonth();//when month changes, checks again for max days in this month
		//if its in this format, break the loop
		if ((day >= 1 && day <= maxDaysInMonth) && (month >= 1 && month <= 12)) {
			break;
		}

		//ADDING DAYS
		if (day > maxDaysInMonth) {//basic conditions for adding days
			day -= maxDaysInMonth;//removing max days in this month
			month += 1;//then advance to the next month
		}
		//if month becomes greater than 12, set it to 1, by removing 12, and advance a year forward
		if (month > 12) {
			month -= 12;
			year += 1;
		}

		//REMOVING DAYS
		if (day < 1) {//same logic but this is for removing and everything is reversed
			month -= 1; 
			if (month < 1) {
				month += 12;
				year -= 1;
			}
			int maxDaysInMonth = Date::maxDaysInMonth();//when month changes, checks again for max days in this month
			day += maxDaysInMonth;
		}
		if (month < 1) {
			month += 12;
			year -= 1;
		}
	}
}


void Date::addDays(int n) {
	this->day += n;
	Date::checkChangingDate();//calling function for changing the date
}
void Date::removeDays(int n) {
	this->day -= n;
	Date::checkChangingDate();//calling function for changing the date
}
bool Date::ifLeapYear() {
	bool decision;//deciding if current year is leap year or not

	//to be leap year:
	if (year % 4 == 0) {//must be divisible by 4 
		decision = true;
		if (year % 100 == 0) {// NOT divisible by 100
			decision = false;
			if (year % 400 == 0) {// and divisible by 400
				decision = true;
			}
		}
	}
	else {
		decision = false;
	}
	return decision;
}

bool Date::dateAfterCurrDate(const Date& newDate) {
	bool decision = true;
	if (newDate.year < this->year) {//if date2.year is lower than the current one, return flase
		decision = false;
	}
	//looking at all available options available
	else if (newDate.year == this->year) {
		if (newDate.month < this->month && newDate.day < this->day) {
			decision = false;
		}
		else if (newDate.month < this->month && newDate.day >= this->day) {
			decision = false;
		}
		else if (newDate.month >= this->month && newDate.day <= this->day) {
			decision = false;
		}
		else if ((newDate.month >= this->month && newDate.day > this->day)) {
			decision = true;
		}
	}
	return decision;
}

int Date::countingDaysToCertainDate(int day_, int month_, int year_) {
	int counter = 0;

	//setting the current date, because it will be modified,
	//so it can be returned to this original date at the end
	int tempDay = day;
	int tempMonth = month;
	int tempYear = year;

	//looping until this day and month don't match with the date that we want to check

	//if we don't want to check the year
	if (year_ == -1) {
		while (day != day_ || month != month_) {
			addDays(1);//calling the adding function
			counter++;//adding 1 to counter
		}
	}
	else {
		while (day != day_ || month != month_ || year != year_) {
			addDays(1);//calling the adding function
			counter++;//adding 1 to counter
		}
	}
	
	//at the end change the current date to the old, original date
	day = tempDay;
	month = tempMonth;
	year = tempYear;

	return counter;//and return counter
}

int Date::daysTillXmas() {//25th of December
	const int dayOfXmas = 25;
	const int monthOfXmas = 12;
	int counter = countingDaysToCertainDate(dayOfXmas, monthOfXmas);//counting

	return counter;
}

int Date::daysTillNewYear() {//1st of January
	const int dayOfNewYear = 1;
	const int monthOfNewYear = 1;
	int counter = countingDaysToCertainDate(dayOfNewYear, monthOfNewYear);//counting

	return counter;
}
int Date::daysTillNextEvent(const Date& upcomingEvent) {//entered date
	bool decision = dateAfterCurrDate(upcomingEvent);//if the upcoming date is before the current one, give decision false
	if (decision == false) {
		//checking if these dates are equal, then return 0 days
		if (upcomingEvent.day == this->day && upcomingEvent.month == this->month && upcomingEvent.year == this->year) {
			return 0;
		}
		//otherwise return -1, because this date will never come after the current one
		return -1;
	}
	
	const int dayOfEvent = upcomingEvent.day;
	const int monthOfEvent = upcomingEvent.month;
	const int yearOfEvent = upcomingEvent.year;
	int counter = countingDaysToCertainDate(dayOfEvent, monthOfEvent, yearOfEvent);//counting

	return counter;
}


void Date::print() {
	cout << day << '.' << month << '.' << year << endl;
}