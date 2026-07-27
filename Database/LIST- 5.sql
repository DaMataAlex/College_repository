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
--        cpf           cod_venda           cod_produto
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


--12
SELECT cod_produto, COUNT(*)
FROM ItensVenda
GROUP BY cod_produto;
--ou ainda
SELECT Produto.codigo, ItensVenda.qtde_vendida
FROM Produto
LEFT JOIN ItensVenda ON Produto.codigo = ItensVenda.cod_produto


--13
SELECT AVG(preco)
FROM Produto
WHERE quantidade > 0;


--14
--cliente----->venda------------>itensvenda------------>produto
--        cpf         cod_venda             cod_produto
SELECT Cliente.cpf, Cliente.nome, Venda.data, Produto.descricao
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
JOIN ItensVenda ON Venda.cod_venda = ItensVenda.cod_venda
JOIN Produto ON ItensVenda.cod_produto = Produto.codigo;


--15
SELECT Cliente.cpf, Cliente.nome
FROM Cliente
JOIN Venda ON Cliente.cpf = Venda.cpf_cliente
WHERE Cliente.cidade = 'Monte Carmelo' AND EXTRACT(YEAR FROM data) = 2019;


--16
SELECT MAX(qtde_vendida)
FROM ItensVenda;


--17
SELECT Venda.cod_venda, Venda.data
FROM Venda
JOIN Cliente ON Venda.cpf_cliente = Cliente.cpf
WHERE Cliente.cidade = 'Uberlandia';


--B)
--CRIACAO DO SCRIPT

CREATE TABLE Aluno(
    codigo SERIAL,
    nome VARCHAR(50),
    dataEntrada DATE,
    dataConclusao DATE DEFAULT NULL,
    PRIMARY KEY(codigo)
);

CREATE TABLE Disciplina(
    codigo SERIAL,
    nome VARCHAR(50),
    cargaHoraria INT,
    PRIMARY KEY(codigo)
);

CREATE TABLE Turma(
    codigo SERIAL,
    codDisciplina INT,
    semestre INT CHECK(semestre IN(1, 2)),
    ano INT,
    PRIMARY KEY(codigo),
    FOREIGN KEY(codDisciplina) REFERENCES Disciplina(codigo)
);

CREATE TABLE Inscricao(
    codAluno INT,
    codTurma INT,
    nota NUMERIC(4,2),
    faltas INT,
    PRIMARY KEY(codAluno, codTurma),
    FOREIGN KEY(codAluno) REFERENCES Aluno(codigo),
    FOREIGN KEY(codTurma) REFERENCES Turma(codigo)
);


--21
INSERT INTO Disciplina (nome, cargaHoraria) VALUES
('Banco de Dados I', 60),
('Estrutura de Dados I', 80),
('Cálculo I', 100),
('Programação Orientada a Objetos', 80),
('Matemática para Ciencia da Computação', 60),
('Redes de Computadores', 60),
('Engenharia de Software', 60);

INSERT INTO Aluno (nome, dataEntrada, dataConclusao) VALUES
('Ana Souza', '2018-03-01', NULL),
('Bruno Lima', '2018-03-01', NULL),
('Carla Mendes', '2019-03-01', NULL),
('Diego Alves', '2019-08-01', NULL),
('Elisa Rocha', '2020-03-01', NULL),
('Felipe Costa', '2020-08-01', NULL),
('Gabriela Dias', '2018-08-01', '2022-12-15');

INSERT INTO Turma (codDisciplina, semestre, ano) VALUES
(1, 1, 2019),
(1, 2, 2020),
(2, 1, 2019),
(2, 1, 2020),
(3, 2, 2018),
(4, 1, 2020),
(5, 2, 2020);

INSERT INTO Inscricao (codAluno, codTurma, nota, faltas) VALUES
(1, 1, 8.50, 2),
(1, 3, 7.00, 4),
(2, 1, 6.50, 6),
(3, 3, 9.00, 1),
(4, 4, 7.50, 3),
(5, 6, 8.00, 0),
(6, 7, 5.50, 8);


--22
UPDATE Disciplina
SET cargaHoraria = 90
WHERE nome = 'Banco de Dados I';

UPDATE Disciplina
SET cargaHoraria = 70
WHERE nome = 'Redes de Computadores';

UPDATE Aluno
SET dataConclusao = '2023-06-30'
WHERE nome = 'Ana Souza';

UPDATE Aluno
SET nome = 'Bruno Lima Silva'
WHERE nome = 'Bruno Lima';

UPDATE Turma
SET ano = 2021
WHERE codDisciplina = 6 AND semestre = 1 AND ano = 2020;

UPDATE Turma
SET semestre = 2
WHERE codDisciplina = 7 AND ano = 2020 AND semestre = 2;

UPDATE Inscricao
SET nota = 9.00
WHERE codAluno = 2 AND codTurma = 1;

UPDATE Inscricao
SET faltas = 5
WHERE codAluno = 4 AND codTurma = 4;


--23
DELETE FROM Inscricao
WHERE codAluno = 6 AND codTurma = 7;

DELETE FROM Turma
WHERE codDisciplina = 5 AND ano = 2020 AND semestre = 2;

DELETE FROM Aluno
WHERE nome = 'Gabriela Dias';

DELETE FROM Disciplina
WHERE nome = 'Redes de Computadores';


--24
SELECT Turma.codigo
FROM Turma
JOIN Inscricao ON Turma.codigo = Inscricao.codTurma
GROUP BY Turma.codigo
HAVING COUNT(Inscricao.codAluno) > 3;


--25
SELECT Turma.ano, Turma.semestre, AVG(Inscricao.faltas), AVG(Inscricao.nota)
FROM Inscricao
JOIN Turma ON Inscricao.codTurma = Turma.codigo
GROUP BY Turma.ano, Turma.semestre;


--26
SELECT AVG(Inscricao.faltas), AVG(Inscricao.nota)
FROM Inscricao
JOIN Turma ON Inscricao.codTurma = Turma.codigo
GROUP BY Inscricao.cod, Turma.semestre


--27
SELECT Disciplina.nome, COUNT(*)
FROM Disciplina
WHERE NOT EXISTS(
    SELECT 1
    FROM Turma
    JOIN Inscricao ON Turma.codigo = Inscricao.codTurma
    WHERE Turma.codDisciplina = Disciplina.codigo
      AND Turma.ano = 2020
      AND Turma.semestre = 2
);


--28
SELECT DISTINCT Aluno.nome, Aluno.dataEntrada
From Aluno
JOIN Inscricao ON Aluno.codigo = Inscricao.codAluno
JOIN Turma ON Inscricao.codTurma = Turma.codigo
WHERE Turma.ano = 2019 AND Turma.semestre = 1;


--29
 SELECT Aluno.nome, Aluno.dataEntrada
 FROM Aluno
 WHERE NOT EXISTS(
     SELECT 1
     FROM Inscricao
     JOIN Turma ON Inscricao.codTurma = Turma.codigo
     WHERE Turma.ano = 2018 AND Turma.semestre = 2
 );


 --30
 SELECT Aluno.nome, Aluno.codigo
 FROM Aluno
 WHERE EXISTS(
     SELECT 1
     FROM Inscricao
     JOIN Turma ON Inscricao.codTurma = Turma.codigo
     WHERE Turma.ano = 2018 AND Turma.semestre = 1
) AND EXISTS(
    SELECT 1
    FROM Inscricao
    JOIN Turma ON Inscricao.codTurma = Turma.codigo
    WHERE Turma.ano = 2018 AND Turma.semestre = 2
 );


--31
SELECT Aluno.nome
FROM Aluno
JOIN Inscricao ON Aluno.codigo = Inscricao.codAluno
JOIN Turma on Inscricao.codTurma = Turma.codigo
WHERE Turma.ano = 2020
GROUP BY Aluno.nome, Aluno.codigo
HAVING COUNT(Inscricao.codAluno) = 6;

--32
SELECT Aluno.nome, Aluno.codigo
FROM Aluno
WHERE EXISTS(
    SELECT 1
    FROM Inscricao
    JOIN Turma ON Inscricao.codTurma = Turma.codigo
    WHERE Inscricao.codAluno = Aluno.codigo
    AND Turma.ano = 2020
    AND Turma.semestre = 1
) AND NOT EXISTS(
    SELECT 1
    FROM Inscricao
    JOIN Turma ON Inscricao.codTurma = Turma.codigo
    WHERE Inscricao.codAluno = Aluno.codigo
    AND Turma.ano = 2019
    AND Turma.semestre = 2
);


--33
SELECT Aluno.codigo, Aluno.nome, COUNT(Inscricao.codAluno)
FROM Aluno
JOIN Inscricao ON Aluno.codigo = Inscricao.codAluno
GROUP BY Aluno.codigo, Aluno.nome;


--34
SELECT Disciplina.*, Turma.*
FROM Disciplina
LEFT JOIN Turma ON Disciplina.codTurma = Turma.codigo;


--C)
--CRIACAO DO SCRIPT
CREATE TABLE Peca (
    PNum INT PRIMARY KEY,
    PNome VARCHAR(100),
    Cor VARCHAR(30),
    Peso DECIMAL(6,2),
    Cidade VARCHAR(100)
);

CREATE TABLE Fornecedor (
    FNum INT PRIMARY KEY,
    FNome VARCHAR(100),
    Status INT,
    Cidade VARCHAR(100)
);

CREATE TABLE Fornece (
    FNum INT,
    PNum INT,
    Preco DECIMAL(10,2),
    PRIMARY KEY (FNum, PNum),
    FOREIGN KEY (FNum) REFERENCES Fornecedor(FNum),
    FOREIGN KEY (PNum) REFERENCES Peca(PNum)
);

CREATE TABLE Conta (
    NomeAgencia VARCHAR(100),
    NroConta INT PRIMARY KEY,
    Saldo DECIMAL(12,2)
);

CREATE TABLE Depositante (
    NomeCliente VARCHAR(100),
    NroConta INT,
    PRIMARY KEY (NomeCliente, NroConta),
    FOREIGN KEY (NroConta) REFERENCES Conta(NroConta)
);

CREATE TABLE Devedor (
    NomeCliente VARCHAR(100),
    NroEmprestimo INT,
    PRIMARY KEY (NomeCliente, NroEmprestimo)
);

CREATE TABLE Dep (
    DNum INT PRIMARY KEY,
    DNome VARCHAR(100),
    Orcam DECIMAL(12,2)
);

CREATE TABLE Emp (
    ENum INT PRIMARY KEY,
    ENome VARCHAR(100),
    End VARCHAR(200),
    Tel VARCHAR(20),
    Sal DECIMAL(10,2),
    DNum INT,
    FOREIGN KEY (DNum) REFERENCES Dep(DNum)
);


--35
SELECT Peca.cor, Peca.cidade
FROM Peca
WHERE Peca.cidade != 'Uberlandia';

--36
SELECT Pecas.*, Fornecedor.*
FROM Pecas
JOIN Fornece ON Pecas.PNum = Fornece.PNum
JOIN Fornecedor ON Fornece.FNum = Fornecedor.FNum
WHERE Fornecedor.cidade = Pecas.cidade


--37
SELECT Fornecedor.FNum, Fornecedor.FNum
FROM Fornecedor
JOIN Fornecedor ON Fornecedor.cidade = Fornecedor.cidade
WHERE Fornecedor.cidade < Fornecedor.cidade;


--38
SELECT DISTINCT Fornecedor.nome, COUNT(*)
FROM Fornecedor
JOIN Peca ON Fornecedor.FNum = Peca.PNum
JOIN Fornece ON Fornecedor.FNum = Fornece.FNum
WHERE Peca.COR = 'Vermelha'
GROUP BY Fornecedor.nome
HAVING COUNT(Peca.cor) >= 1;


--39
SELECT Fornecedor.nome
FROM Fornecedor
