void perform_call(double* args, int num_args)
{
	// declarations
	const int NUM_ARGS = 2; // replace -1 with correct value

	// check correct number of arguments
	if (num_args != NUM_ARGS) {
		native_error("Wrong number of generated inputs for month_days");
	}

	// test object calling code
	month_days(
		(int) args[0],
		(int) args[1]
    );
}
