#define MAX 1000

//Structs acessorias
typedef struct{
    char rua[MAX];
    char bairro[MAX];
    char CEP[10];
    int numnero;
    char complemento[MAX];

}Endereco;

typedef struct{
    int dia;
    int mes;
    int ano;

}Data;

//Structs principais
typedef struct{
    char nome_aluno[MAX];
    char id_aluno[12];
    int idade_aluno;
    char telefone_aluno[16];
    Endereco endereco_aluno;
    Data data_nascimento_aluno;
     
}Aluno;

typedef struct{
    char nome_disciplina[MAX];
    char id_disciplina[MAX];
    char professor_cadastrado[MAX];
    int carga_horaria;
    char turno;
    int limites_alunos;

}Disciplina;

typedef struct{
    char id_aluno_matriculado[12];
    char id_disciplina[MAX];
    Data data_matricula;

}Matricula;