/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define VERT 6

struct graph {
   int V; 
   int A; 
   float **adj; 
};

typedef struct graph *Graph;

static float **MATRIXint( int r, int c, int val) { 
   float **m = malloc( r * sizeof (float *));
   int i,j;
   for ( i = 0; i < r; ++i) 
   	   m[i] = malloc( c * sizeof (float));
   
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
float somar(Graph x){
	int j,i;
	float soma=0;
	for(i=0; i<VERT;i++)
	for(j=0; j<VERT;j++){
		if(x->adj[j][i]==1 && j>i){
			soma = soma + x->adj[i][j];
		}
	}
	return soma;
}

void op2(Graph x){
	int i,j;
	int y = 0;
	i=y;
	j=y;
	float soma=somar(x);
	for(i=0;i<VERT;i++){
		for(i=0;i<VERT;i++){
		
			 }		
	}	
}

void vizinhoMaisProximo(Graph x){
	int i,j;
	float menor;
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

int main()
{	
	
	Graph grafo = GRAPHinit(VERT);

	inserirBack(grafo);
		
	vizinhoMaisProximo(grafo);
	op2(grafo);
	int i;
	for (i=0;i<VERT;i++){
		free(grafo->adj[i]);
	}
    free(grafo->adj);
	return 0;
}
