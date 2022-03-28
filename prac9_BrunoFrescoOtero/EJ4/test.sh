echo "Running tests..."
echo

output=$(./ej4.out "coordenadas.txt")
expected_output="El triangulo con mas perimetro es el numero 3.\nPuntos:\nPunto 1: (0,0,0)\nPunto 2: (3,0,0)\nPunto 3: (10,15,0)\nPerimetro: 37.580702\nArea: 22.500000\n" +
		+"El triangulo con mas area es el numero 3.\nPuntos:\nPunto 1: (0,0,0)\nPunto 2: (3,0,0)\nPunto 3: (10,15,0)\nPerimetro: 37.580702\nArea: 22.500000"

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
