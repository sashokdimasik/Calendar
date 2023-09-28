/*******************************
 * Author:       Platonov A.A. *
 * Group:        ПИ-231        *
 * Date:         28.09.2023    *
 * Project name: Calendar      *
 * OnlineGDB:  *
 *******************************/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
  int year, currWeekDay;
  int daysAmount[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  
  cout << "Enter a year: ";
  cin >> year;
  
  //Zeller's congruence
  int k = year % 100;
  int j = year / 100;
  int kDiv4 = k / 4;
  int jDiv4 = j / 4;
  currWeekDay = int(1 + floor(13 * (13 + 1) / 5) + k + kDiv4 + jDiv4 - 2 * j) % 7 - 3;
  if (year % 4 == 0 && !(year % 100 == 0 && year % 400 == 0)) {
    daysAmount[1]++;
    currWeekDay--;
  }
  if (currWeekDay < 0) currWeekDay += 7;
  
  for (int i = 0; i < 12; i++) {
    cout << "\n\n" << month[i] << '\n';
	for (int i = 0; i < currWeekDay; i++) cout << "   ";
	for (int currDay = 1; currDay <= daysAmount[i]; currDay++) {
      if (currDay < 10) cout << ' ';
      cout << currDay << ' ';
	  currWeekDay++;
	  if (currWeekDay == 7) {
        currWeekDay = 0;
        if (currDay != daysAmount[i]) cout << '\n';
      }
    }
  }
}
