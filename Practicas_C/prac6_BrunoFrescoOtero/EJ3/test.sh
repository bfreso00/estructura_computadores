echo "Running tests..."
echo

output=$(./ej3.out < entrada.txt)
expected_output="El minimo de la fila 1 es: -5\nEl minimo de la fila 2 es: 2\nEl minimo de la fila 3 es: -10"

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
