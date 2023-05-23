#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXTAM (800+2)

unsigned hash_string(void *str) {
    unsigned total = 2;
    for (char *reader = str; *reader; ++reader) {
        total += *reader;
        total *= 5;
    }
    return total;
}

int main(int argc, char *argv[]) {
    /*if (argc != 3) {
        perror("Solo debe ingresar dos parametros\n");
        exit(1);
    }*/ 
    printf("el numero de paramertos es: %d\n", argc);
    FILE *archivo;
    char *nombreArchivo = argv[1];

    //Ver si existe el archivo 
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("No se puede abrir el archivo\n");
        exit(1);
    }
    //Contar la cantidad de caracteres de la primera linea del archivo
    char linea[800];
    fgets(linea, sizeof(linea), archivo);
    int cantidadCaracteres = strlen(linea)+1;
    int byte = cantidadCaracteres *sizeof(char);
    printf("El tamano es: %d\n", byte);

    //Conocer el tamano del archivo
    fseek(archivo, 0, SEEK_END);
    int tamanoArchivo = ftell(archivo);
    if (tamanoArchivo == 0) {
        perror("el archivo esta vacio");
    }else {
        printf("El tamano del archivo es: %d\n", tamanoArchivo);

    }
    int CantidadLineas;
    if ((tamanoArchivo % cantidadCaracteres) == 0) {
        printf("%d es multiplo de %d\n",tamanoArchivo,cantidadCaracteres);
        CantidadLineas = tamanoArchivo / cantidadCaracteres;
        printf("la cantidad de lineas es: %d\n",CantidadLineas);
    } else {
            printf("%d no es multiplo de %d",tamanoArchivo,cantidadCaracteres);
            perror("Error");
    }
    int i = 0, j = tamanoArchivo-1;

    char myline[cantidadCaracteres];
    fseek(archivo,0,SEEK_SET);
 
    fgets(myline, sizeof(myline),archivo);
    printf("la llave es: %c\n", myline);
    printf("hash-string: %d\n",hash_string(argv[2]));


    archivo = fopen(nombreArchivo, "r");
    int k;
    fseek(archivo,cantidadCaracteres,SEEK_SET);
    //char myline[cantidadCaracteres];
    fread(myline, cantidadCaracteres,1,archivo);
    int line_pos = (hash_string(argv[2]) % CantidadLineas) * cantidadCaracteres;
     int lines_checked = 0;
    char *key, *value;
        while(lines_checked < CantidadLineas) {
            printf("line_pos:%d\n", line_pos);
        fseek(archivo, line_pos, SEEK_SET);
        if(fgets(myline, sizeof(myline), archivo) == NULL || (key = strtok(myline, ":")) == NULL) {
            fprintf(stderr, "Key not found in the file\n");
            fclose(archivo);
            exit(EXIT_FAILURE);
        }
        printf("myline: %c\n", myline);
        value = strtok(NULL, ":");
        if(strcmp(key, argv[2]) == 0) {
            printf("%s\n", value);
            fclose(archivo);
            exit(EXIT_SUCCESS);
        }
        lines_checked++;
        line_pos = (line_pos + cantidadCaracteres) % tamanoArchivo;
    } 
    fprintf(stderr, "Key not found in the file\n");
    fclose(archivo);
    exit(EXIT_FAILURE);
    return 0;
}
