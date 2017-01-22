void perform_call(double* args, int num_args)
{
  // declarations
  const int NUM_ARGS = 8; // replace -1 with correct value

  // check correct number of arguments
  if (num_args != NUM_ARGS) {
    native_error("Wrong number of generated inputs for line_intersect");
  }

  // test object calling code
  line_intersect(
    (int) args[0],
    (int) args[1],
    (int) args[2],
    (int) args[3],
    (int) args[4],
    (int) args[5],
    (int) args[6],
    (int) args[7]
  );
}
