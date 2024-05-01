
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define MAX 1000

int topo=-1,acumulo[MAX];
void empilhar();
void desempilhar();
void mostrar_pilha();

void main()
{
int ch;
while(1)
{
printf("\n*** Menu de Escolha ***");
printf("\n\n1.Empilhar\n2.Desempilhar\n3.Mostrar Pilha\n4.Sair");
printf("\n\nDigite a opcao desejada: (1-4):");
scanf("%d",&ch);
switch(ch)
{
case 1: empilhar();
break;
case 2: desempilhar();
break;
case 3: mostrar_pilha();
break;
case 4: exit(0);
default: printf("\nOpcao Invalida!!");
}
}
}

void empilhar()
{
int val;
if(topo==MAX-1)
{
printf("\nPilha esta cheia!!");
}
else
{
printf("\nDigite o valor a empilhar:");
scanf("%d",&val);
topo=topo+1;
acumulo[topo]=val;
}
}

void desempilhar()
{
if(topo==-1)
{
printf("\nPilha esta vazia!!");
}
else
{
printf("\nO valor deletado foi: %d",acumulo[topo]);
topo=topo-1;
}
}

void mostrar_pilha()
{
int i;
if(topo==-1)
{
printf("\nPilha esta vazia!!");
}
else
{
printf("\nPilha...\n");
for(i=topo;i>=0;--i)
printf("%d\n",acumulo[i]);
}
}
