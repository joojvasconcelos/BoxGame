#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define snakeValue 1
#define buttonValue 2
#define selectedBoxValue 3

bool theBoxIsSnake(int box){
	
	if(box != snakeValue){
		return false;
	}
	
	return true;
}
bool theButtonIsInTheBox(int box){
	
	if(box != buttonValue){
		return false;
	}
	return true;
}

bool isThisBoxSelected(int box){
	
	if(box != selectedBoxValue){
		return false;
	}
	return true;
}

void genereteBoxes(int boxes[], int quantityBoxes){
   int i;
    for( i = 0; i < quantityBoxes; i++){
        boxes[i] = 0;
    }
   
    int snakePosition = 0, buttonPosition = 0;
        srand(time(NULL));
    	while (snakePosition == buttonPosition){
        snakePosition = rand() % quantityBoxes;
        buttonPosition = rand() % quantityBoxes;
        boxes[snakePosition] = snakeValue;
        boxes[buttonPosition] = buttonValue;
    }
    
}

int main (){
	int roundPlayer, selectBox, quantityPlayers;
	
	bool theGameIsFinished = false;
	
	printf("bem-vindo a cobra na caixa!\nQuantos jogares irão jogar:");
    scanf("%d", &quantityPlayers);
	
	
	char players [quantityPlayers][100];
	int quantityBoxes = (quantityPlayers * 5) / 2,boxes[quantityBoxes];
	
int i;
    for(  i = 0; i < quantityPlayers; i++){
        
        printf("Digite o nome do jogadora numero %d", i + 1);
       scanf("%s", &players[i][100]);
        
        
    }
    
	roundPlayer = 1 + (rand() % quantityPlayers); //escolhe um player aleatório dentre os jogadores
	
    genereteBoxes(boxes, quantityBoxes);
	
	
	while (!theGameIsFinished){
		
		int i;
		for( i = 0; i < quantityPlayers; i++ ){
		    
		    printf("O jogador da rodada eh: %s\nEscolha uma caixa de 1 a %d\n", players[i], quantityBoxes);
		    scanf("%d", &selectBox);
		    
	    	int selectedOption;
    	    
    	    if(theBoxIsSnake(boxes[selectBox-1]) ){
				printf("O jogador %s selecionou a caixa com a cobra, PERDEU!\nDeseja comecar o jogo novamente?(1)\nou deseja ir pro menu?(2)", players[i]);
				scanf("%d", &selectedOption);
				theGameIsFinished = (selectedOption != 1)? true : false;
				genereteBoxes(boxes,quantityBoxes);
				break; 
			}
			else if(theButtonIsInTheBox(boxes[selectBox-1])){
            printf("O jogador %s selecionou a caixa com o botão, Venceu!\nDeseja comecar o jogo novamente?(1)\nou deseja ir pro menu?(2)", players[i]);			
                scanf("%d", &selectedOption);
				theGameIsFinished = (selectedOption != 1)? true : false;
				genereteBoxes(boxes,quantityBoxes);
				break;
			}else if( isThisBoxSelected(boxes[selectBox - 1])){
			    printf("Essa caixa ja foi selecionada. Escolha outra por favor");
			    --i;
			    continue;
			}
			
		    printf("A caixa que voce escolheu esta vazia.");
		    boxes[selectBox - 1] = selectedBoxValue;
		    
		}
	}
		
	return 0;
}
