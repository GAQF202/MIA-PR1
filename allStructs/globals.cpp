#include "globals.h"
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

string format_day_prop(int field) {
  return (field < 10 ? "0" : "") + to_string(field);
}

string get_now() {
  time_t time_now = time(0);
  tm *now = localtime(&time_now);
  string current_date =
      format_day_prop(now->tm_mday) + "/" + format_day_prop(now->tm_mon + 1) +
      "/" + to_string(now->tm_year + 1900) + " " +
      format_day_prop(now->tm_hour) + ":" + format_day_prop(now->tm_min);
  return current_date;
}

vector<string> split(const string &s, char del){
  stringstream ss(s);
  string item;
  vector<string> tokens;

  while (getline(ss,item,del))
  {
    tokens.push_back(item);
  }

  return tokens;
}
