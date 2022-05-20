echo "Running tests..."
echo

output=$(./ej1.out  < entrada.txt)
expected_output="El jugador 3 es el mas alto del equipo.\nAlberto\n20\n1.820000\nEl jugador 1 es el mas viejo del equipo.\nBruno\n22\n1.720000"

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
