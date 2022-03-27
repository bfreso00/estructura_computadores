echo "Running tests..."
echo

output=$(./ej3.out "alumnos.txt")
expected_output="El alumno con mas media es el alumno 4.\nAlejandro\nGarcía Bajo\nPrimera nota: 9.380000\nSegunda nota: 8.200000\n"

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
