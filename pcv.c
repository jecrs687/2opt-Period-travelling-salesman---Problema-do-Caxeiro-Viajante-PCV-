/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#define VERT 6
#define MAX 10
struct graph {
   int V; 
   int A; 
   double **adj; 
};

typedef struct graph *Graph;

static double **MATRIXint( int r, int c, int val) { 
   double **m = malloc( r * sizeof (double *));
   int i,j;
   for ( i = 0; i < r; ++i) 
   	   m[i] = malloc( c * sizeof (double));
   
   for ( i = 0; i < r; ++i)
      for ( j = 0; j < c; ++j){
	  m[i][j]=0;

	  }
      	
   return m;
}

void GRAPHinsertArc( Graph G, int v, int w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] =1; 
      G->A++;
   }
}

void GRAPHremoveArc( Graph G, int v, int w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] =0; 
      G->A--;
   }
}


Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
  
   return G;
}

void inserirBack(Graph x){
	/*
	ordem:
	->terra
	->titan
	->Mimas
	->Io
	->Callisto
	->Ganymede
	*/
	x->adj[0][1]=8.1;
	x->adj[0][2]=8.2;
	x->adj[0][3]=3.6;
	x->adj[0][4]=3.1;
	x->adj[0][5]=3.2;
	x->adj[1][2]=0.6;
	x->adj[1][3]=5.1;
	x->adj[1][4]=5.6;
	x->adj[1][5]=5.9;
	x->adj[2][3]=4.7;
	x->adj[2][4]=5.2;
	x->adj[2][5]=5.7;
	x->adj[3][4]=0.8;
	x->adj[3][5]=1.1;
	x->adj[4][5]=1.5;	

	
}
double somar(Graph x){
	int j,i;
	double soma=0;
	for(i=0; i<VERT;i++)
	for(j=i+1; j<VERT;j++){
		if(x->adj[j][i]==1){
			soma = soma + x->adj[i][j];
		}
	}
		printf("\n%f\n\n", soma);
	return soma;
}
int verticeVizinho(Graph x, int i,int anterior){
	int j;

	for(j = 0; j<VERT; j++){
		if(x->adj[i][j]==1 && j<i){
			if(j!=anterior)
			return j;
			}
		
		if(x->adj[j][i]==1 && j>i){
			if(j!=anterior)
			   	return j;
			}
		}
		return -1;
}

void mostrarGrafo(Graph x){
	int v, k;
	printf("__________________________________________________________________________________________\n");
	 for(v=0; v<VERT;v++){
			for(k=0; k<VERT;k++){
				printf("   %f   |", x->adj[v][k] );	
	  		}
	  		printf("\n______________|______________|______________|______________|______________|______________|\n");	
	 }}


void op2(Graph x){
	int i,j;
	int anterior=-1;
	int proximo=0;
	int vizinho;
	int y = 0;
	i=y;
	j=y;
	double soma=somar(x);
	Graph aux;
	aux=x;

	 do{		  
	 	proximo = verticeVizinho(x,i, anterior);
		if(i>proximo){
			x->adj[i][proximo]=0;
	 	 }else{
			x->adj[proximo][i]=0;
		  }
		  anterior = i;
		  j=verticeVizinho(x,proximo,anterior);
		  vizinho = proximo;
		  anterior = proximo;
		  proximo = j;
		  
	 	for(j=verticeVizinho(x,proximo,anterior);y!=proximo && i!=verticeVizinho(x,proximo,anterior) ;j=verticeVizinho(x,proximo,anterior)){
		 	 printf("trocando  %d:%d por %d:%d anterior =%d \n", i,vizinho,j,proximo,anterior );
			  if(proximo>j){
				  x->adj[proximo][j]=0;
			  }else{
				  x->adj[j][proximo]=0;
			  }
 		 	 if(proximo>i){
				  x->adj[proximo][i]=1;
			  }else{
				  x->adj[i][proximo]=1;
			  }
			   	if(vizinho>j){
				  x->adj[vizinho][j]=1;
			  }else{
				  x->adj[j][vizinho]=1;
			  }
	
			  printf("soma anterior %f", soma);
			  if(soma>somar(x)){
			  	printf("valor será reduzido %f", soma);
				  soma = somar(x);
			  }else{
  		 	 if(proximo>j){
				  x->adj[proximo][j]=1;
			  }else{
				  x->adj[j][proximo]=1;
			  }	  
			   if(proximo>i){
				  x->adj[proximo][i]=0;
			  }else{
				  x->adj[i][proximo]=0;
			  }
			   	if(vizinho>j){
				  x->adj[vizinho][j]=0;
			  }else{
				  x->adj[j][vizinho]=0;
			  }
			if(i>vizinho){
				x->adj[i][vizinho]=1;
	 	 	 }else{
				x->adj[vizinho][i]=1;
		  	  }
			  }
			  
			  mostrarGrafo(x);
			  anterior = proximo;
			  proximo = j;
		 }
		 
		 anterior = i;
		 i = vizinho;
	 }while(verticeVizinho(x,verticeVizinho(x,i,anterior),i)!=y);}
	 	
	 	
void navegar(Graph x){
	int i,j;
	int anterior=-1;
	int proximo=0;
	int vizinho;
	int y = 0;
	i=y;
	j=y;
	double soma=somar(x);
	Graph aux;
	aux=x;

	 do{
	 	proximo = verticeVizinho(x,i, anterior);
		  anterior = i;
		  j=verticeVizinho(x,proximo,anterior);
		  vizinho = proximo;
		  anterior = proximo;
		  proximo = j;
	 	for(j=verticeVizinho(x,proximo,anterior);y!=proximo && i!=verticeVizinho(x,proximo,anterior) ;j=verticeVizinho(x,proximo,anterior)){
		 	 printf("navegando de  %d:%d para %d:%d anterior =%d \n", i,vizinho,j,proximo,anterior );
			  anterior = proximo;
			  proximo = j;
			  
		 }
		 anterior = i;
		 i = vizinho;
	 }while(verticeVizinho(x,i,anterior)!=y);}
	 	
	 	
	 	
	 	
	 	
	// metodo incorreto
	/*for(i=0;i<VERT;i++){
		for(j=0;j<i;j++){
			if(x->adj[i][j]==1){
				 for(w=i+1; w<VERT;w++){
					for(z=j+1; z<w;z++){
						if(z!=i && w!=j && x->adj[w][z]==1){
			   			 	 x->adj[i][j]=0;
			   			 	 x->adj[w][z]=0;
			   			 	 printf("%d:%d por %d:%d\n",i,j,w,z);
	
			   			 	 if(j<z){x->adj[z][j]=1; }else{x->adj[j][z]=1;}
    					     if(w<i){x->adj[i][w]=1; }else{x->adj[w][i]=1; }
 	   	   	   	   	   	   	   	   	   printf("__________________________________________________________________________________________\n");
							 for(v=0; v<VERT;v++){
									for(k=0; k<VERT;k++){
										printf("   %f   |", x->adj[v][k] );	
							  		}
							  		printf("\n______________|______________|______________|______________|______________|______________|\n");	
								}
							if(soma>somar(x)){
								soma = somar(x);
								aux=x;
							}
		   			 	 	 x->adj[i][j]=1;
			   			 	 x->adj[w][z]=1;
			   			 	 if(j<z){x->adj[z][j]=0; }else{x->adj[j][z]=0;}
    					     if(w<i){x->adj[i][w]=0; }else{x->adj[w][i]=0;}	 	 
						}	  		 
					}			 
				 }					
			}	
		 }		
	}*/	


void vizinhoMaisProximo(Graph x){
	int i,j;
	double menor;
	int y = 0;
	int v[VERT];
	i=y;
	do{
		x->adj[i][i] =1;
		menor = 9999;
		if(x->A+1==x->V){
				if(y<i){
				printf("%d:%d:%f:1 \n\n", i,y,x->adj[y][i] );
				x->adj[i][y]=1;}
				else{
				printf("%d:%d:%f:2 \n\n", i,y,x->adj[i][y] );
				x->adj[y][i]=1;
				}
				x->A=x->A+1;
				i=0;
				
			}else{
			for(j=0;j<VERT;j++){
				if((x->adj[i][j] < menor) && (x->adj[j][j] ==0) && (i<j)){
						menor = x->adj[i][j];
						v[i] = j;
					}
				if((x->adj[j][i] < menor) && (x->adj[j][j] ==0) && (j<i)){
						menor = x->adj[j][i];
						v[i] = j;
				}
				}
			if(v[i]>i){
				printf("%d:%d:%f:1  ", i,v[i],x->adj[i][v[i]] );
				x->adj[v[i]][i]=1;
			}else{
				printf("%d:%d:%f:2  ", i,v[i],x->adj[v[i]][i] );
				x->adj[i][v[i]]=1;
			}
			
			
			i = v[i];
			x->A=x->A+1;
			}
		}while(i!=y);
		
		for(i=0; i<VERT;i++){
			for(j=0; j<VERT;j++){
				printf("%f      ", x->adj[i][j] );	
	  		}
	  		printf("\n\n");	
		}
	}
void createTxt(char v1[][MAX], char v2[][MAX], double w[], int size){
	FILE *fp;
	fp = fopen("example.txt", "w");
	char buffer[2*MAX];
	int i;
	for(i=0; i < size;i++){
			strcpy(buffer, v1[i]);
			strcat(buffer, v2[i]);
       		fprintf (fp, "%s %s %s %f\n", v1[i], v2[i], buffer, w[i]);
   	}
	fclose(fp);
}

void gerarArquivo(Graph x){
	double vetor[VERT];
	char vetor1[VERT][MAX];
	char vetor2[VERT][MAX];
	int i,j;
	int k=0;
	for(i=0; i<VERT;i++)
	for(j=i+1; j<VERT;j++){
		if(x->adj[j][i]==1){
			printf("nome do vertices %d:", i);
			scanf("%s", vetor1[k]);
			printf("nome do vertices %d:", j);
			scanf("%s", vetor2[k]);
			vetor[k]=x->adj[i][j];
			k++;
		}
	}
		createTxt(vetor1, vetor2, vetor, x->V);

}

int main()
{	
	Graph grafo = GRAPHinit(VERT);

	inserirBack(grafo);
		
	vizinhoMaisProximo(grafo);
	op2(grafo);
	navegar(grafo);
	gerarArquivo(grafo);
	int i;
	for (i=0;i<VERT;i++){
		free(grafo->adj[i]);
	}
    free(grafo->adj);
	return 0;
}
