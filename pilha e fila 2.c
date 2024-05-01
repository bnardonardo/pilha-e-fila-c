
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

struct Fila {

	int tamanho;
	float*dados;
	int primeiro;
	int ultimo;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->tamanho = c;
	f->dados = (float*) malloc (f->tamanho * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->tamanho-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++;

}

int remover( struct Fila *f ) {

	int temp = f->dados[f->primeiro++];

	if(f->primeiro == f->tamanho)
		f->primeiro = 0;

	f->nItens--;
	return temp;

}

int estaVazia( struct Fila *f ) {

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) {

	return (f->nItens == f->tamanho);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%f\n\n",f->dados[i++]);

		if (i == f->tamanho)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int ch, tam;
	float valor;
	struct Fila umaFila;

	printf("\nTamanho da fila? ");
	scanf("%d",&tam);
	criarFila(&umaFila, tam);


	while( 1 ){

		printf("\n1 - Enfileirar\n2 - Desenfileirar\n3 - Mostrar Fila\n4 - Sair\n\nOpcao? ");
		scanf("%d", &ch);

		switch(ch){

			case 1:
				if (estaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nValor a ser enfileirado? ");
					scanf("%f", &valor);
					inserir(&umaFila,valor);

				}

				break;

			case 2:
				if (estaVazia(&umaFila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ;

				}
				break;

				case 3:
					if (estaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nFila...\n\n");
						mostrarFila(&umaFila);

					}
					break;

                case 4: exit(0);

                    default: printf("\nOpcao Invalida!!");



		}
	}
}
