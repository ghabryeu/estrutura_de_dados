#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

// Definição do tipo link como ponteiro para struct node
typedef struct node* link;

// Definição da estrutura node
struct node{ 
    int item; 
    link next; // Ponteiro para o próximo nó
};

// Estrutura chamada FILA para representar a fila
typedef struct{
  link inicio; // Ponteiro para o início da fila
  link final; // Ponteiro para o final da fila
} FILA;

// Função para inicializar a fila vazia
void inicializar(FILA *f){
  f->inicio = NULL; // Indica que a fila está vazia
  f->final = NULL; // O final da fila deve ser igual o início
}

// Função para enfileirar (enqueue) um elemento na fila
void enfileirar(FILA *f, int x){
  link novoNode = (link) malloc(sizeof(struct node)); // Aloca novo nó
  novoNode->item = x; // Armazena x no novo nó
  novoNode->next = NULL; // Novo nó aponta para NULL
  if (f->inicio == NULL) // Verifica se a fila está vazia
    f->inicio = novoNode; // início aponta para o novo nó
  else // A fila tem pelo menos um elemento
    f->final->next = novoNode; // Nó no final aponta para o novo nó 
  f->final = novoNode; // final aponta para o novo nó no final da fila
}

// Função para desenfileirar (dequeue) um elemento da fila
void desenfileirar(FILA *f, int *i){
  if (f->inicio == NULL) // Verifica se a fila está vazia
    printf("Fila Vazia!\n");
  else{ // A fila tem pelo menos um elemento
     *i = f->inicio->item; // Faz uma cópia do elemento no início
     link tmp = f->inicio; // Guarda o endereço do início
     f->inicio = f->inicio->next; // Atualiza o início para o próximo
     if (f->inicio == NULL) // Verifica se a fila ficou vazia 
       f->final = NULL; // final deve apontar para NULL
     free(tmp);
  }
}

// Função para imprimir os elementos da fila
void imprimir(FILA f){
  link p = f.inicio;
  printf("Fila: \" ");
  while (p != NULL) { // Percorre a fila do início até o final
    printf("%d ", p->item); // Exibe os elementos na ordem de enfileiramento
    p = p->next; // Avança para o próximo elemento da fila
  }
  printf("\"\n");
}

// Função para converter um número inteiro para binário
void int_to_bin(int n, FILA *f) {
    if (n == 0) return;
    enfileirar(f, n % 2);
    int_to_bin(n / 2, f);
}

// Função para imprimir o número binário armazenado na fila
void imprimir_binario(FILA *f) {
    int bit;
    if (f->inicio != NULL) {
        desenfileirar(f, &bit);
        imprimir_binario(f); // Chama recursivamente para imprimir os bits
        printf("%d", bit); // Imprime o bit
    }
}

int main(void){
  int i, n;
  FILA f; // Cria uma fila
  inicializar(&f); // Inicializa a fila vazia
  
  // Solicita ao usuário o valor de n
  printf("Digite o valor de n: ");
  scanf("%d", &n); // Lê o valor de n fornecido pelo usuário
  printf("\n");

  // Para cada número de 1 até n, converte e imprime o número binário
  for (i = 1; i <= n; i++) {
    printf("Número %d em binário: ", i);
    int_to_bin(i, &f); // Converte o número para binário e armazena na fila
    imprimir_binario(&f); // Imprime o número binário
    printf("\n");
  }

  return 0;
}
