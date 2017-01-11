#include "is_leap_year.h"
#include "CTestObjectHandle.h"
JNIEXPORT void JNICALL Java_org_iguanatool_casestudies_calendar_testobjects_is_1leap_1year_call(JNIEnv *env, jobject jobj, jdoubleArray args)
{
	initialize_and_call(env, jobj, args);
}

int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int month_days(int month, int year) {
  int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return month == 2 && is_leap_year(year) ? 29 : month_days[month-1];
}

int days_between(int start_month, int start_day, int start_year,
                 int end_month, int end_day, int end_year) {
  int days = 0;    

  // sanitize month inputs
  if (start_month < 1) start_month = 1;
  if (end_month < 1) end_month = 1;
  if (start_month > 12) start_month = 12;
  if (end_month > 12) end_month = 12;

  // sanitize day inputs    
  if (start_day < 1) start_day = 1;
  if (end_day < 1) end_day = 1;
  if (start_day > month_days(start_month, start_year))
    start_day = month_days(start_month, start_year);
  if (end_day > month_days(end_month, end_year))
    end_day = month_days(end_month, end_year);
  
  // swap dates if start date before end date
  if ((end_year < start_year) || 
      	(end_year == start_year && end_month < start_month) || 
      	(end_year == start_year && end_month == start_month && 
						end_day < start_day)) {
    int t = end_month; end_month = start_month; start_month = t;
    t = end_day; end_day = start_day; start_day = t;
    t = end_year; end_year = start_year; start_year = t;
  }

  // calculate days
  if (start_month == end_month && start_year == end_year) {
    days = end_day - start_day;
  } else {
    days += month_days(start_month, start_year) - start_day;
    days += end_day;
    if (start_year == end_year) {
      int month = start_month + 1;
      while (month < end_month) {
        days += month_days(month, start_year); month ++;
      }
    } else {
      int year; int month = start_month + 1;
      while (month <= 12) {
        days += month_days(month, start_year); month ++;
      }
      month = 1;
      while (month < end_month) {
        days += month_days(month, end_year); month ++;
      }
      year = start_year + 1;
      while (year < end_year) {
        days += 365;
        if (is_leap_year(year)) days ++;
        year ++;
  } } }
  return days;
}

void perform_call(double* args, int num_args)
{
	// declarations
	const int NUM_ARGS = 1; // replace -1 with correct value

	// check correct number of arguments
	if (num_args != NUM_ARGS) {
		native_error("Wrong number of generated inputs for is_leap_year");
	}

	// test object calling code
    is_leap_year((int) args[0]);
}

