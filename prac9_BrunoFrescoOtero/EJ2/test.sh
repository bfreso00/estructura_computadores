echo "Running tests..."
echo

output=$(./ej2.out  < entrada.txt)
expected_output="Datos del triangulo:\nPunto 1: (2,3)\nPunto 2: (0,0)\nPunto 3: (4,4)\nPerimetro: 12.128990\nArea: 4.000000\n"

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
