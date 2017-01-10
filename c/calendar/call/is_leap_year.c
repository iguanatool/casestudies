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
