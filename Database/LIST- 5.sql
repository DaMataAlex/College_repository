--A)
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


--1.
INSERT INTO Produto(descricao, cor, tamanho, quantidade, preco) VALUES
    ('Camiseta Basica', 'Azul', 'M', 30, 39.90),
    ('Meia Cano Curto', 'Preto', 'U', 60, 12.00),
    ('Jaqueta Jeans', 'Azul', 'G', 15, 189.90),
    ('Calca Social', 'Preto', 'M', 25, 149.90),
    ('Vestido Floral', 'Branco', 'P', 20, 129.90),
    ('Bermuda Moletom', 'Cinza', 'GG', 40, 69.90),
    ('Blusa de Frio', 'Vermelho', 'M', 18, 99.90);

INSERT INTO Cliente(cpf, nome, cidade) VALUES
    ('11111111111', 'Alex', 'Ibia'),
    ('22222222222', 'Manu', 'Uberlandia'),
    ('33333333333', 'Isabela', 'Tokyo'),
    ('44444444444', 'Otavio', 'Lagoa Formosa'),
    ('55555555555', 'Luana', 'Araxa'),
    ('66666666666', 'Thiago', 'Manaus'),
    ('77777777777', 'Pedro', 'Uberaba');

INSERT INTO Venda(cpf_cliente, data) VALUES
    ('11111111111', '2026-04-05'),
    ('11111111111', '2025-04-20'),
    ('22222222222', '2026-07-20'),
    ('33333333333', '2025-03-19'),
    ('55555555555', '2024-09-21'),
    ('66666666666', '2026-07-20'),
    ('77777777777', '2025-04-05');

INSERT INTO ItensVenda(cod_venda, cod_produto, qtde_vendida) VALUES
    (1, 1, 2),
    (1, 3, 1),
    (2, 2, 5),
    (3, 4, 1),
    (4, 5, 3),
    (5, 6, 2),
    (6, 7, 1);


--2.
UPDATE Produto
SET preco = 40.00
WHERE codigo = 1;

UPDATE Produto
SET descricao = 'Calca Cargo'
WHERE codigo = 4;

UPDATE Cliente
SET cidade = 'Osaka'
WHERE cpf = '33333333333';

UPDATE Cliente
SET cidade = 'Ibia'
WHERE cpf = '44444444444';

UPDATE Venda
SET data = '2020-04-29'
WHERE cpf_cliente = '11111111111'
AND cod_venda = 2;

UPDATE Venda
SET cpf_cliente = '22222222222'
WHERE cod_venda = 1;

UPDATE ItensVenda
SET qtde_vendida = 1
WHERE cod_venda = 1 AND cod_produto = 1;

UPDATE ItensVenda
SET cod_produto = 3
WHERE cod_venda = 1 AND cod_produto = 1;


--3
DELETE FROM Produto
WHERE codigo = 6;

DELETE FROM Cliente
WHERE cpf = '11111111111';

DELETE FROM Venda
WHERE cod_venda = 1;

DELETE FROM ItensVenda
WHERE cod_produto = 6;


--4
SELECT *
FROM Produto
ORDER BY preco ASC;


--5
SELECT cod_venda
FROM Venda
WHERE EXTRACT(YEAR FROM data) = 2021;


--6
SELECT Cliente.nome
FROM Venda
JOIN Cliente ON Venda cpf_cliente = Cliente.cpf
GROUP BY Cliente.nome
HAVING COUNT(*) > 3;


--7
SELECT *
FROM Produto
WHERE Preco BETWEEN 20 AND 50;


--8
-- --cliente----->venda--------->itensvenda----------->produto
--        cpf       cod_venda           cod_produto
SELECT Cliente.*
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
WHERE EXTRACT(YEAR FROM data) = 2020;


--9
SELECT cidade, COUNT(*)
FROM Cliente
GROUP BY cidade
HAVING COUNT(*) >= 2;


--10
SELECT codigo, descricao
FROM Produto
WHERE EXISTS(
    SELECT 1
    FROM ItensVenda
    WHERE ItensVenda.cod_produto = Produto.codigo
);


--11
SELECT descricao, cor
FROM Produto
JOIN ItensVenda ON Produto.codigo = ItensVenda.cod_produto
WHERE ItensVenda.cod_venda = 1;


12--
SELECT cod_produto, COUNT(*)
FROM ItensVenda
GROUP BY cod_produto;


13--
