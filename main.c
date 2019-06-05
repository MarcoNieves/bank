#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/**
 * Autores:
 * 	- Marco Antonio Nieves Esquivel
 *  - Christofer Cervantes Trujillo
 * Carrera: IMAI (Ingenieria en Manufactura y Automatizacion Industrial)
 * Grado y Grupo: 2° "A"
 */

int mat[3][7], i, j, codigo;
float vec[3];
float deposito, s, p;
void llenado();
void mostrar();
void puntos();
float promedio_deposito();
int depmas();
int demenos();

void totalA();
void ordenamiento();


int main() {

  int opcion;
  printf("\n");
  printf("--------------BUENOS DIAS !!!, INGRESA LA OPCION PARA ANALIZAR LOS DEPOSITOS ESTADISTICAMENTE !!!---------------- \n");
  scanf("%i", & opcion);
  do {

    printf("\n \n \n");
    printf("---------- BANCO LOS BUCHONES------------\n");
    printf("--------ESTADISTICOS DE UN BANCO-------- \n");
    printf("\n");
    printf("Ingrese la opcion deseada \n");
    printf("\n");
    printf("(1).- LLENADO DE MATRIZ DE DEPOSITOS: \n");
    printf("(2).- MOSTRADO DE DATOS DE LA MATRIZ DADA: \n");
    printf("(3).- VISUALIZACION DE PUNTOS  PERSONAS QUE TENGAN DEPOSITOS MAS ALTOS \n");
    printf("(4).-(funcion float) PROMEDIO GENERAL DE LOS DEPSOSITOS QUE TENGAN ADENTRO DE LA MATRIZ \n");
    printf("(5).-(funcion int )CAPTURA DEL DEPOSITO MAS ALTO \n");
    printf("(6).-(funcion int)CAPTURA DEL DEPOSITO MAS BAJO \n");
    printf("(7).- SUMA TOTAL DE LA MATRIZ \n");
    printf("(*8).- ORDENAMIENTO DE MENOR A MAYOR DE LOS DEPOSITOS INGRESADOS \n");
    printf("(*9).- BUSQUEDA DEL VALOR DEL RESULTADO DE LA SUMA DE LO 3 CLIENTEs SI ESTA EL VALOR DEL DEPOSITO A ENCONTRAR \n");
    printf("(10).- Salir del menu \n ");
    printf("-------------------------------------------\n");

    printf("Ingrese la opcion: \n");
    scanf("%d", & opcion);
    printf("\n");

    switch (opcion) {

    case 1:
      printf("LLENADO DE LA MATRIZ DE DEPOSITOS: \n");
      printf("\n");
      llenado();
      break;

    case 2:
      printf("MOSTRADO DE  DEPOSITOS DE LA MATRIZ DADA:: \n");
      mostrar();
      break;

      puts("-----------------------------------------------------------------------------------------------------------------------------------------------------");

    case 3:
      printf("VISUALIZACION DE VALORES DE LA MATRIZ MAYORES A 5: \n"); //COMO SE ESTABLECE LA BUSQUEDA DE ESOS NUMEROS DE LA MATRIZ
      puntos();
      break;

      puts("---------------------------------------------------------------------------------------------------------------------------------------------------");

    case 4:
      printf("PROMEDIO DE LOS DEPOSITOS EN GENERAL DE LAS PERSONAS PARA AVERIGUAR EL COPORTAMIENTO DE LOS 7 ANIOS: \n ");

      float mat[3][7], suma, prom; //(4)
      int i, j;

      int hora = time(NULL);
      srand(hora);
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
          //scanf ("%f", &mat[i][j]);
          // printf ("%i,%i:", i,j);

          mat[i][j] = rand() % 100 + 50;
          suma += mat[i][j];
        }
      }

      printf("\n");
      printf("La suma total de la matriz es: %f \n", suma);
      printf("\n");
      prom = suma / 21;
      printf("\n");
      printf("El promedio total general de los depositos en general es: %f \n", prom);

      // return prom;

      break;

      puts("------------------------------------------------------------------------------------------------------------------------------------");

    case 5:
      printf(" OBTENCION DEL DEPOSITO MAS ALTO: \n"); //CORTA EL PROMEDIO EN EL CASO 5
      float s = 0;

      printf("\n");
      int hrs = time(NULL);
      srand(hrs);
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
          printf("\n");
          printf("%i,%i: ", i, j);
          mat[i][j] = rand() % 10 + 1;
          printf("-------------------\n");

        }
      }

      int max_i = 0, max_j = 0;
      for (i = 0; i < 3; i++) {
        puts("\n");
        s = 0;
        for (j = 0; j < 7; j++) {
          printf(" \t %.0f ", mat[i][j]);
          //s += mat[i][j];
          if (mat[i][j] > mat[max_i][max_j]) {
            max_i = i;
            max_j = j;
          }
        }
        //printf ("% \t %.0f  ", s);
      }
      printf("\n");
      printf(" \n EL DEPOSITO MAS GRANDE Y LA POSICION EN LA QUE SE ENCUENTRA ES: \n \n %.0f", mat[max_i][max_j]);
      printf(" \t (%i , %i)", max_i, max_j);

      return (max_i, max_j);

      break;

      puts("-----------------------------------------------------------------------------------------------------------------------------------------------------");

    case 6:

      printf(" OBTENCION DEL DEPOSITO MENOS ALTO: \n");
      float sum = 0;

      printf("\n");
      int h = time(NULL);
      srand(h);
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
          printf("\n");
          printf("%i,%i: ", i, j);
          mat[i][j] = rand() % 10 + 1;
          printf("-------------------\n");

        }
      }

      int min_i = 0, min_j = 0;
      for (i = 0; i < 3; i++) {
        puts("\n");
        sum = 0;
        for (j = 0; j < 7; j++) {
          printf(" \t %.0f ", mat[i][j]);
          //sum += mat[i][j];
          if (mat[i][j] < mat[min_i][min_j]) {
            min_i = i;
            min_j = j;
          }
        }
        //printf ("% \t %.0f  ", s);
      }
      printf("\n");
      printf(" \n EL VALOR MENOS GRANDE Y LA POSICION EN LA QUE SE ENCUENTRA ES: \n \n %.0f", mat[min_i][min_j]);
      printf(" \t (%i , %i)", min_i, min_j);

      return (min_i, min_j);
      break;

      puts("----------------------------------------------------------------------------------------------------------------------------------------------");

    case 7:
      printf("TOTAL DE LA SUMAS DE LAS 3 PERSONAS EN CADA ANIO PARA AVERIGUAR SU COMPORTAMIENTO DE LOS DEPOSITOS: \n");
      totalA();
      break;

      puts("-----------------------------------------------------------------------------------------------------------------------------------------------");

    case 8:

      printf("ACOMODO DE MENOR A MAYOR DE LOS DEPOSITOS DE TODA LA MATRIZ \n");
      // int arreglo1;
      ordenamiento();
      break;

      puts("-------------------------------------------------------------------------------------------------------------------------------------------------");

    case 9:

      printf("BUSQUEDA DEL VALOR EN DESPUES DE SACAR LA SUMA DE LOS 7 ANIOS DE LOS 3 CLIENTES \n");
      break;

      puts("--------------------------------------------------------------------------------------------------------------------------------------------------");

    case 10:

      printf("OPCION DE SALIR");

      break;

      puts("--------------------------------------------------------------------------------------------------------------------------------------------------");

      //pendiente con la opcion de salida
    default:
      printf("ERROR, OPCION NO DISPONIBLE \n");

    }
  } while (opcion != 12);

  printf("OPCION NO DISPONIBLE INGRESE OTRA OPCION \n");
  printf("\n \n");

  system("pause");
  return 0;

}

void llenado() { //(1)

  int i, j;
  int hora = time(NULL); // Semilla de rand();
  srand(hora);
  puts(" VALORES INGRESADOS CONTINUE: \n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 7; j++) {
      //printf(" Posicion %i,%i: ", i, j);
      mat[i][j] = rand() % 10 + 1;

    }
  }
}

void mostrar() { //(2)

  printf("\n");
  puts("\n");
  puts(" Acomodo de la matriz de los depositos capturados: \n ");
  for (i = 0; i < 3; i++) {
    puts("\n");
    for (j = 0; j < 7; j++) {
      printf("%i \t ", mat[i][j]); //muestra la matriz
    }
  }
}

void puntos() { //(3)

  printf("\n");
  float max = 0;
  int i, j;
  for (i = 0; i < 3; i++) {
    vec[i] = 0;
    for (j = 0; j < 7; j++) {
      vec[i] += mat[i][j];
    }
    max = vec[i] > max ? vec[i] : max;
	printf("%i: %f\n", i, vec[i]);
	
  }
  printf("El numero mas alto es para los 5 puntos es: %f \n", max);

} //como mostrar la matriz 3x7 y  con un vector que sume los tres renglones

void totalA() { //(7)

  int s = 0;
  int hora = time(NULL);
  srand(hora);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 7; j++) {
      //printf ("%i,%i: ",i,j);
      mat[i][j] = rand() % 10 + 1;
    }
  }

  for (i = 0; i < 3; i++) {
    puts("");
    s = 0;
    for (j = 0; j < 7; j++) {
      printf("\t \t %i", mat[i][j]);

    }
  }
  // suma por columna
  puts("\n");
  puts("\n Suma por columnas de los depositos por anio de los 3 clientes: \n");
  for (j = 0; j < 7; j++) {
    s = 0;
    for (i = 0; i < 3; i++) {
      s += mat[i][j];
      if (i == 2) {
        printf(" \t \t %i ", s); // porque no me uimprime la suma total de cada a�o de los 3 clientes si solo me suma los 2 primeros renglones
      }
    }
  }
}

/**
 * Usando el método burbuja un array es ordenado.
 *
 */
void ordenamiento() { //(8)
  int c, d, y = 3;
  float swap;
    for (c = 0 ; c < ( y - 1 ); c++) {
      for (d = 0 ; d < y - c - 1; d++) {
        if (vec[d] > vec[d + 1]) {
          swap = vec[d];
          vec[d] = vec[d + 1];
          vec[d + 1] = swap;
        }
    }
  }
  int i, j;
  for (i = 0; i < 3; i++) {
    printf("%f \n", vec[i]);
  }
}
  /*
  int i, j, c, k, aux;
  int arreglo[21];
  int hora = time(NULL);
  srand(hora);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 7; j++) {
      //printf ("%i,%i: ",i,j);
      mat[i][j] = rand() % 10 + 1;
    }
  }

  for (i = 0; i < 3; i++) {
    puts("");
    s = 0;
    for (j = 0; j < 7; j++) {
      printf("\t  %i", mat[i][j]);

      //Convertir el arreglo de dos dimensiones en uno de una sola dimensi�n.
      for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
          arreglo[k] = mat[i][j];
          k++;
        }
      }

      //Aplicaci�n del Ordenamiento Burbuja.
      for (i = 1; i < 21; i++) {
        for (j = 0; j < 21; j++) {
          if (arreglo[c] > arreglo[c + 1]) {
            aux = arreglo[c];
            arreglo[c] = arreglo[c + 1];
            arreglo[c + 1] = aux;

          }
        }
      }

      //Convertir el arreglo de una dimensi�n en una de dos dimensiones
      //como anteriormente estaba.
      k = 0;
      for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
          mat[i][j] = arreglo[k];
          printf("%i \n", arreglo[k]);
          k++;

        }
      }

    }
  }*/


//problemas del criterios de evaluacion 7,5,3
// a solucionarr 3,8,9 del programa
