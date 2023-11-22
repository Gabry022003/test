#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

unsigned int get_random()
{
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

typedef struct parametri
{
    int k;
    char w;
    int N;
    int M;
} Parametri;

Parametri readInput(int argc, char **argv)
{
    if (argc != 5)
    {
        fprintf(stdout, "Errore numero parametri\n");
        exit(EXIT_FAILURE);
    }

    Parametri par;
    char *end = NULL;
    par.k = (int)strtol(argv[1], &end, 10);

    if (*end)
    {
        fprintf(stdout, "Errore il primo parametro deve eseere un'intero\n");
        exit(EXIT_FAILURE);
    }

    if (par.k < 10 || par.k > 15)
    {
        fprintf(stdout, "Errore numero parametri\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(argv[2]) != 1)
    {
        fprintf(stdout, "Errore parametro deve eseere un carattere\n");
        exit(EXIT_FAILURE);
    }

    par.w = *argv[2];

    par.N = (int)strtol(argv[3], &end, 10);

    if (*end)
    {
        fprintf(stdout, "Errore il primo parametro deve eseere un'intero\n");
        exit(EXIT_FAILURE);
    }

    if (par.N < 4 || par.N > 8)
    {
        fprintf(stdout, "Errore numero parametri\n");
        exit(EXIT_FAILURE);
    }

    par.M = (int)strtol(argv[4], &end, 10);

    if (*end)
    {
        fprintf(stdout, "Errore il primo parametro deve eseere un'intero\n");
        exit(EXIT_FAILURE);
    }

    if (par.M < 4 || par.M > 8)
    {
        fprintf(stdout, "Errore numero parametri\n");
        exit(EXIT_FAILURE);
    }

    return par;
}

char ***allocateS(Parametri par)
{
    char ***matrice = malloc(sizeof(char **) * par.N);

    for (size_t i = 0; i < par.N; i++)
    {
        matrice[i] = malloc(sizeof(char *) * par.M);
    }

    return matrice;
}

char *genString(int max, int min, int k)
{
    char *stringa = malloc(sizeof(char) * (k + 1));
    for (size_t i = 0; i < k; i++)
    {
        stringa[i] = get_random() % (max - min + 1) + min;
    }

    return stringa;
}

void fillS(char ***matrice, Parametri par)
{
    int max = 'z';
    int min = 'a';
    for (size_t i = 0; i < par.N; i++)
    {
        for (size_t j = 0; j < par.M; j++)
        {
            matrice[i][j] = genString(max, min, par.k);
        }
    }
}

void sortS(char ***matrice, Parametri par)
{
    for (size_t j = 0; j < par.M; j++)
    {
        for (size_t p = 0; p < par.N - 1; p++)
        {
            for (size_t i = 0; i < par.N - 1 - p; i++)
            {
                if (strcmp(matrice[i][j], matrice[i + 1][j]) > 0)
                {
                    char *tmp = matrice[i][j];
                    matrice[i][j] = matrice[i + 1][j];
                    matrice[i + 1][j] = tmp;
                }
            }
        }
    }
}

void printMatrix(char ***matrice, Parametri par)
{
    puts(" ");
    for (size_t i = 0; i < par.N; i++)
    {
        for (size_t j = 0; j < par.M; j++)
        {
            printf("%s ", matrice[i][j]);
        }
        printf("\n");
    }
}

int conta(char *s, Parametri par)
{
    int c = 0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i] == par.w)
        {
            c++;
        }
    }

    return c;
}

void printMax(char ***matrice, Parametri par)
{
    int i_max = 0;
    int j_max = 0;
    int max = 0;

    for (size_t i = 0; i < par.N; i++)
    {
        for (size_t j = 0; j < par.M; j++)
        {
            int c = conta(matrice[i][j], par);
            if (c > max)
            {
                max = c;
                i_max = i;
                j_max = j;
            }
        }
    }
    
    printf("\nStringa con %d occorrenze di %c trovata agli indici %d %d: ", max, par.w, i_max, j_max);
    for (size_t i = 0; i < strlen(matrice[i_max][j_max]); i++)
    {
        char c = matrice[i_max][j_max][i];
        if (c == par.w)
        {
            printf("*");
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    Parametri par = readInput(argc, argv);
    printf("%d %c %d %d\n", par.k, par.w, par.N, par.M);
    char ***S = allocateS(par);
    fillS(S, par);
    sortS(S, par);
    printMatrix(S, par);
    printMax(S, par);
}
