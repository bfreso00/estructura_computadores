echo "Running tests..."
echo

output=$(./ej7.out)
expected_output="4  7  7\n" +
	      + "11 17 20\n" +
	      + "11 26 17\n"

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
