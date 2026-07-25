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

-- exercicios de inserts e updates
INSERT INTO Cliente (cpf, nome, cidade) VALUES
    ('44444444444', 'Diego Alves', 'Uberlandia');

UPDATE Cliente
SET cidade = 'Patos de Minas'
WHERE cpf = '44444444444';

DELETE FROM Cliente
WHERE cpf = '44444444444';

--recriando o Diego porque eu tinha apagado ele
 INSERT INTO Cliente (cpf, nome, cidade) VALUES
    ('44444444444', 'Diego Alves', 'Uberlandia');

INSERT INTO Venda (cpf_cliente, data) VALUES
    ('44444444444', '2021-03-15');

-- exercicios de selects basicos
SELECT nome, cidade
FROM Cliente
WHERE cidade = 'Uberlandia';

SELECT *
FROM Produto
WHERE quantidade = 0
ORDER BY descricao;

SELECT cod_venda
FROM Venda
WHERE EXTRACT(YEAR FROM data) = 2021 AND EXTRACT(MONTH FROM data) = 03;

SELECT descricao, preco
FROM Produto
WHERE cor = 'Azul' OR cor = 'Preto';
--ou ainda:
SELECT descricao, preco
FROM Produto
WHERE cor IN ('Azul', 'Preto');

SELECT nome
FROM Cliente
WHERE cidade != 'Uberlandia';

SELECT *
FROM ItensVenda
WHERE qtde_vendida > 5;

SELECT cod_venda, data
FROM Venda
WHERE data BETWEEN '2020-01-01' AND '2020-12-31';

SELECT *
FROM Produto
WHERE tamanho = 'M' AND preco < 100;

SELECT COUNT(*)
FROM Produto;

SELECT SUM(quantidade)
FROM Produto;

SELECT MIN(preco)
FROM Produto
WHERE cor = 'Preto';

SELECT COUNT(cod_venda)
FROM Venda
WHERE cpf_cliente = '44444444444';
