--CRIACAO DO SCRIPT

CREATE TABLE Produto(
    codigo SERIAL,
    descricao VARCHAR(300),
    cor VARCHAR(20),
    tamanho CHAR(2),
    quantidade INT,
    preco NUMERIC(10,2),
    PRIMARY KEY (codigo)
);

CREATE TABLE Cliente(
    cpf VARCHAR(11),
    nome VARCHAR(50),
    cidade VARCHAR(30),
    PRIMARY KEY(cpf)
)

CREATE TABLE Venda(

)
