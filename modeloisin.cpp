#include <stdio.h>
#include <cmath>
#include <time.h>
#define N 100




int main(){
    
    double T;
    int rep=100000*N*N;
    T=2.7;
    int spines[N][N];
    int random;
    int f, c, h;
    double Energia;
    double exponencial, p, epsilon;
    srand(time(NULL));

    FILE*valormatriz;

    h=0;
    //genero la red de spines aleatorios
/*
for (int i = 0; i < N; i++)
{
    //si es la ultima fila iguala a la ultima
    
        for (int j = 0; j < N; j++)
        {
                random=rand()%2;
               
                if (random==0)
                {
                    random=-1;
                 }

                spines[i][j]=random;
        }
            }
    



    //escribir la matriz
    //diferencia de energia
   */ 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j< N; j++)
        {
            spines[i][j]=1;
            
            //fprintf("%d\t", spines[i][j]);
        }
        printf("\n");
    }
    



//empezamos el bucle
    for (int k = 0; k < rep ; k++)
    {
    f=rand()%N; //posicion aleatoria de la matriz
    c=rand()%N;
    // printf("%d\t,%d\t", f,c);
    //calculamos la energia 

   if (f==N-1 && c==0)
   {
    Energia=2.0*spines[f][c]* (spines[0][c]+spines[f-1][c]+spines[f][c+1]+spines[f][N-1]);
   }
   else if (f==N-1 && c!=N-1 && c!=0)
   {
    Energia=2.0*spines[f][c]* (spines[0][c]+spines[f-1][c]+spines[f][c+1]+spines[f][c-1]);
   }
    else if (f==N-1 && c==N-1)
   {
    Energia=2.0*spines[f][c]*(spines[0][c]+spines[f-1][c]+spines[f][0]+spines[f][c-1]);
   }
   else if (f!=N-1 && c==N-1 && f!=0)
   {
    Energia=2.0*spines[f][c]* (spines[f+1][c]+spines[f-1][c]+spines[f][0]+spines[f][c-1]);
   }
     else if (f==0 && c==N-1)
   {
    Energia=2.0*spines[f][c]* (spines[f+1][c]+spines[N-1][c]+spines[f][0]+spines[f][c-1]);
   }
   else 
   {
    Energia=2.0*spines[f][c]* (spines[f+1][c]+spines[f-1][c]+spines[f][c+1]+spines[f][c-1]);
   }
   
    //printf("%lf\t", Energia);

    exponencial=exp(-Energia*1.0/T);

    //tenemos el minimo entre 1 y exponencial

   p=1.0;
   if (exponencial <1)
   {
        p=exponencial;
   }
   //printf("%lf\n", p);
   epsilon=(double)rand() / RAND_MAX;
   //printf("%lf\n", epsilon);

   //si es menor lo cambiamos
   if (epsilon<p)
   {
    spines[f][c]=-1*spines[f][c];
   }
   
    
    if (h==100*N*N)
    {
        valormatriz=fopen("matrices","a");

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j< N; j++)
            {
                if (j==N-1)
                {
                    fprintf(valormatriz,"%d", spines[i][j]);
                }
                else
                {
                     fprintf(valormatriz,"%d,", spines[i][j]);
                }
                        
            }
             fprintf(valormatriz,"\n");
        }
        fprintf(valormatriz,"\n");
        fclose(valormatriz);
        h=0;
    }
     else
    {
        h=h+1;
    }

}
   
    
    
    
    


      
    //E=2*spines[n][m]*(spines[n+1][m]+spines[n-1][m]+spines[n][m+1]+spines[n][m-1]);
    
    return 0;
}