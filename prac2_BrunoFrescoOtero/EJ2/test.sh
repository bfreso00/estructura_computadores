echo "Running tests..."
echo

output=$(./ej2.out  < EJ2/datos.txt)
expected_output="Las millas son: 6.25 Los pies son: 32808.39 Las yardas son: 10936.13"

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
