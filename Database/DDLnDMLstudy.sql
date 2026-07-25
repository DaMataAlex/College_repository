--TABELAS PRINCIPAIS
CREATE TABLE Produto(
    codigo SERIAL,
    descricao VARCHAR(150),
    cor VARCHAR(15),
    tamanho CHAR(2),
    quantidade INT,
    preco NUMERIC(10,2),
    PRIMARY KEY (codigo)
);

CREATE TABLE Cliente(
    cpf VARCHAR(11),
    nome VARCHAR(60),
    cidade VARCHAR(25),
    PRIMARY KEY (cpf)
);

CREATE TABLE Venda(
    cod_venda SERIAL,
    cpf_cliente VARCHAR(11),
    data DATE,
    PRIMARY KEY (cod_venda),
    FOREIGN KEY (cpf_cliente) REFERENCES Cliente(cpf)
);

-- TABELAS DE RELACIONAMENTO
CREATE TABLE ItensVenda(
    cod_venda INT,
    cod_produto INT,
    qtde_vendida INT,
    PRIMARY KEY (cod_venda, cod_produto),
    FOREIGN KEY (cod_venda) REFERENCES Venda(cod_venda),
    FOREIGN KEY (cod_produto) REFERENCES Produto(codigo)
);

--treino de inserts e updates
INSERT INTO Cliente (cpf, nome, cidade) VALUES
    ('44444444444', 'Diego Alves', 'Uberlandia');

UPDATE Cliente
SET cidade = 'Patos de Minas'
WHERE cpf = '44444444444';

DELETE FROM Cliente
WHERE cpf = '44444444444';

--recriando o Diego porque eu tinha apagado ele
 INSERT INTO Clientes (cpf, nome, cidade) VALUESS
    ('44444444444', 'Diego Alves', 'Uberlandia');
