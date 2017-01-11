#include "days_between.h"
#include "CTestObjectHandle.h"
JNIEXPORT void JNICALL Java_org_iguanatool_casestudies_calendar_testobjects_days_1between_call(JNIEnv *env, jobject jobj, jdoubleArray args)
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
  if (node(2,  less_than(0, start_month, 1) )) start_month = 1;
  if (node(4,  less_than(0, end_month, 1) )) end_month = 1;
  if (node(6,  greater_than(0, start_month, 12) )) start_month = 12;
  if (node(8,  greater_than(0, end_month, 12) )) end_month = 12;

  // sanitize day inputs    
  if (node(10,  less_than(0, start_day, 1) )) start_day = 1;
  if (node(12,  less_than(0, end_day, 1) )) end_day = 1;
  if (node(14,  greater_than(0, start_day, month_days(start_month, start_year)) ))
    start_day = month_days(start_month, start_year);
  if (node(16,  greater_than(0, end_day, month_days(end_month, end_year)) ))
    end_day = month_days(end_month, end_year);
  
  // swap dates if start date before end date
  if (node(18,  is_true(0, (end_year < start_year))  || is_true(1, (end_year == start_year && end_month < start_month))  || is_true(2, (end_year == start_year && end_month == start_month && end_day < start_day)) )) {
    int t = end_month; end_month = start_month; start_month = t;
    t = end_day; end_day = start_day; start_day = t;
    t = end_year; end_year = start_year; start_year = t;
  }

  // calculate days
  if (node(28,  equals(0, start_month, end_month)  && equals(1, start_year, end_year) )) {
    days = end_day - start_day;
  } else {
    days += month_days(start_month, start_year) - start_day;
    days += end_day;
    if (node(32,  equals(0, start_year, end_year) )) {
      int month = start_month + 1;
      while (node(34,  less_than(0, month, end_month) )) {
        days += month_days(month, start_year); month ++;
      }
    } else {
      int year; int month = start_month + 1;
      while (node(39,  less_than_or_equal(0, month, 12) )) {
        days += month_days(month, start_year); month ++;
      }
      month = 1;
      while (node(43,  less_than(0, month, end_month) )) {
        days += month_days(month, end_year); month ++;
      }
      year = start_year + 1;
      while (node(47,  less_than(0, year, end_year) )) {
        days += 365;
        if (node(49,  is_true(0, is_leap_year(year)) )) days ++;
        year ++;
  } } }
  return days;
}

void perform_call(double* args, int num_args)
{
	// declarations
	const int NUM_ARGS = 6; // replace -1 with correct value

	// check correct number of arguments
	if (num_args != NUM_ARGS) {
		native_error("Wrong number of generated inputs for days_between");
	}

	// test object calling code
	days_between(
		(int) args[0],
		(int) args[1],
		(int) args[2],
		(int) args[3],
		(int) args[4],
		(int) args[5]
	);
}

