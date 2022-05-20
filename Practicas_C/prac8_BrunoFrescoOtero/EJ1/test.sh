echo "Running tests..."
echo

output=$(./ej3.out 10 "Hola, buenos dias." < entrada.txt)
expected_output="Longitud de la cadena introducida: 18\n
Introduzca una cadena:Que tal estas?\n
La cadena concatenada es: Hola, buenos dias.Que tal estas?\n
La cadena indicada esta incluida en la cadena primaria.\n
Que tal estas?\n
El caracter en la posicion indicada es: n"

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
