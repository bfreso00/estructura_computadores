echo "Running tests..."
echo

output=$(./ej4.out)
expected_output="9  14  12  6  8\n" +
	      + "4  13  5  10  6\n" +
	      + "12  10  10  4  7\n" +
	      + "3  15  12  13  8\n" +
	      + "12  13  10  12  11\n"

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
