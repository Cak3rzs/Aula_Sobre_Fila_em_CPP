
#include <iostream>
#include <string.h>
#define MAX_FILA 5

using namespace std;
struct DADOS_ALUNOS{
	int CodAluno;
	char nome[100];
	int turma;
};

bool enfileirar(DADOS_ALUNOS fila[], int CodAluno,
char nome[], int turma, int &FimFila);

bool exibirprimeiro(DADOS_ALUNOS fila[], int IniFila, int &FimFila);
bool desenfileirar(DADOS_ALUNOS fila[], int &posicaofim);

main(){
	struct DADOS_ALUNOS filaAluno[MAX_FILA];
	int IniFila = 0;
	int FimFila = 0;
	bool Ret; int CodAluno, turma;
	char nome[100];
	
	cout <<"Inserção: " <<endl;
	cout << "Digite o código do aluno: ";
	cin >> CodAluno;
	cout <<"Digite o nome do aluno: ";
	cin >> nome;
	cout <<"Digite a turma do aluno: ";
	cin >> turma; 
	Ret = enfileirar(filaAluno,CodAluno, nome, turma, FimFila);
	if(Ret == true){
		cout << "Inserção efetuada com sucesso!" << endl;
	}
	Ret = exibirprimeiro(filaAluno, IniFila, FimFila);
	if(Ret == false){
		cout << "Não foi possivel exibir a fila" <<endl;
	}
	
	Ret = desenfileirar (filaAluno, FimFila);
	if(Ret == false){
		cout << "Não foi possivel desenfileirar a fila." << endl;
	}
	else {
		cout << "Primeiro da fila desenfileirando com sucesso!!!";
	}
	
}

bool enfileirar (DADOS_ALUNOS fila[], int CodAluno,char nome[], int turma, int &FimFila){
	if (FimFila == MAX_FILA){
			printf("Error: Fila Cheia");
			return false;
	}
	else{
		fila[FimFila].CodAluno = CodAluno;
		strcpy(fila[FimFila].nome, nome);
		fila[FimFila].turma = turma;
		FimFila++;
	}
	return true;
} 

bool exibirprimeiro(DADOS_ALUNOS fila[], int IniFila, int &FimFila){
	if(FimFila == 0){
		cout << "Erro: Fila Vazia";
		return false;
	}
	cout << "\n Codigo do Aluno:  " << fila[IniFila].CodAluno <<endl;
	cout << "\n Nome: " << fila[IniFila].nome <<endl;
	cout << "\n Turma:" << fila[IniFila].turma <<endl;
	return true;
	
}

bool desenfileirar(DADOS_ALUNOS fila[], int &posicaofim){
	int ind; int posrem;
	if(posicaofim == 0 ){
		cout << "Erro: Lista Vazia";
		return false;
	}
	for (ind = 0; ind < posicaofim; ind++){
		fila[ind] = fila[ind+1];
	}
posicaofim--;
return true;
}



