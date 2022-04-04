# -*- coding: utf-8 -*-
#Ejercicio 1 => calcula_nota
def calcula_nota(nota):
    if nota<5:
        print(str("El alumno está suspenso."))
    elif nota==5 or nota==6:
        print(str("El alumno está aprobado."))
    elif nota==7 or nota==8:
        print(str("El alumno tiene un notable."))
    elif nota==9 or nota==10:
        print(str("El alumno tiene un sobresaliente."))
    else:
        print(str("Introduzca una nota valida."))

nota = int(input("Introduzca un número: "))
calcula_nota(nota)
