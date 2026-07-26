-- exercicios de fixacao com DDL
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

CREATE TABLE ItensVenda(
    cod_venda INT,
    cod_produto INT,
    qtde_vendida INT,
    PRIMARY KEY (cod_venda, cod_produto),
    FOREIGN KEY (cod_venda) REFERENCES Venda(cod_venda),
    FOREIGN KEY (cod_produto) REFERENCES Produto(codigo)
);

-- exercicios de fixacao com DML
INSERT INTO Cliente (cpf, nome, cidade) VALUES
    ('44444444444', 'Diego Alves', 'Uberlandia');

UPDATE Cliente
SET cidade = 'Patos de Minas'
WHERE cpf = '44444444444';

DELETE FROM Cliente
WHERE cpf = '44444444444';

 INSERT INTO Cliente (cpf, nome, cidade) VALUES
    ('44444444444', 'Diego Alves', 'Uberlandia');

INSERT INTO Venda (cpf_cliente, data) VALUES
    ('44444444444', '2021-03-15');

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

SELECT cor, COUNT(*)
FROM Produto
GROUP BY cor;

SELECT cor, SUM(quantidade)
FROM Produto
GROUP BY cor
HAVING SUM(quantidade) > 50;

SELECT cpf_cliente, COUNT(*)
FROM Venda
GROUP BY cpf_cliente;

SELECT cpf_cliente, COUNT(*)
FROM Venda
GROUP BY cpf_cliente
HAVING COUNT(*) >= 3;

SELECT Produto.descricao, Produto.cor, Cliente.nome, Venda.data
FROM Produto
JOIN ItensVenda ON Produto.codigo = ItensVenda.cod_produto
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
JOIN Cliente ON Venda.cpf_cliente = Cliente.cpf;

--cliente----->venda----------->itensvenda------------>produto
--        cpf        cod_venda             cod_produto
SELECT Cliente.nome
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
JOIN Produto ON ItensVenda.cod_produto = Produto.codigo
WHERE Produto.codigo = 1;

--itensvenda------------>produto
--           cod_produto
SELECT ItensVenda.cod_produto, Produto.descricao, SUM( ItensVenda.qtde_vendida)
From ItensVenda
JOIN Produto ON ItensVenda.cod_produto = Produto.codigo
GROUP BY ItensVenda.cod_produto, Produto.descricao;

--cliente----->venda--------->itensvenda----------->produto
--        cpf       cod_venda           cod_produto
SELECT nome
FROM Cliente
WHERE cpf IN(
    SELECT cpf_cliente
    FROM Venda
    WHERE cod_venda IN(
        SELECT cod_venda
        FROM ItensVenda
        WHERE cod_produto IN(
            SELECT codigo
            FROM Produto
            WHERE codigo = 2
        )
    )
);

SELECT nome
FROM Cliente
WHERE NOT EXISTS(
    SELECT 1
    FROM Venda
    WHERE Venda.cpf_cliente = Cliente.cpf
);

--cliente----->venda--------->itensvenda----------->produto
--        cpf       cod_venda           cod_produto
SELECT nome
FROM Cliente
WHERE NOT EXISTS(
    SELECT 1
    FROM Produto
    WHERE cor = 'azul' AND NOT EXISTS(
        SELECT 1
        FROM Venda
        JOINS ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda,
        WHERE Venda.cpf_cliente = Cliente.cpf AND ItensVenda.cod_produto = Produto.codigo
    )
);

SELECT nome
FROM Cliente
WHERE NOT EXISTS(
    SELECT 1
    FROM Produto
    WHERE preco < 50 AND NOT EXISTS(
        SELECT 1
        FROM Venda
        JOINS ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda,
        WHERE Venda.cpf_cliente = Cliente.cpf AND ItensVenda.cod_produto = Produto.codigo
    )
);

--cliente----->venda--------->itensvenda----------->produto
--        cpf       cod_venda           cod_produto
SELECT nome
FROM Cliente
WHERE NOT EXISTS(
    SELECT 1
    FROM Produto
    WHERE preco < 50 AND NOT EXISTS(
        SELECT 1
        FROM Venda
        JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
        WHERE Venda.cpf_cliente = Cliente.cpf AND ItensVenda.cod_produto = Produto.codigo
    )
);

SELECT descricao
FROM Produto
WHERE NOT EXISTS(
    SELECT 1
    FROM Cliente
    WHERE NOT EXISTS(
        SELECT 1
        FROM Venda
        JOIN ItensVenda on Venda.cod_venda = Cliente.cpf AND ItensVenda.cod_produto = Produto.codigo
    )
);

ALTER TABLE Cliente
ADD COLUMN email VARCHAR(100);

ALTER TABLE Cliente
RENAME COLUMN email TO email_contato;

ALTER TABLE Cliente
DROP COLUMN email_contato;

SELECT *
FROM Produto
WHERE descricao LIKE '%camisa%';

SELECT nome
FROM Cliente
WHERE nome LIKE 'M%';

SELECT *
FROM Produto
WHERE cor NOT LIKE '%o';

SELECT Cliente.nome
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
GROUP BY Clientes.nome
HAVING COUNT (DISTINCT ItensVenda.cod_produto) > 2;

SELECT Cliente.cpf, Cliente.nome
FROM Cliente
JOIN Venda on Cliente.cpf = Venda.cpf_cliente
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
GROUP BY Cliente.cpf, Cliente.nome
HAVING COUNT (DISTINCT ItensVenda.cod_produto) > 1;

--cliente----->venda--------->itensvenda----------->produto
--        cpf       cod_venda           cod_produto
SELECT Produto.descricao
FROM Produto
JOIN ItensVenda ON Produto.codigo = ItensVenda.cod_produto
JOIN Venda ON ItensVenda.cod_venda = Venda.cod_venda
JOIN Cliente ON Venda.cpf_cliente = Cliente.cpf
GROUP BY Produto.descricao
HAVING COUNT (DISTINCT Cliente.cpf) > 2;

SELECT Cliente.cpf
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
GROUP BY Cliente.cpf
HAVING SUM(ItensVenda.qtde_vendida) > 5;

SELECT cor, COUNT(*)
FROM Produto
GROUP BY cor
HAVING COUNT(*) >= 3;

SELECT tamanho, COUNT(*)
FROM Produto
GROUP BY tamanho
HAVING COUNT(*) > 1;

SELECT EXTRACT(YEAR FROM data), COUNT (*)
FROM Venda
GROUP BY EXTRACT(YEAR FROM data)
HAVING COUNT(*) >= 2;
