-- SQLite
CREATE TABLE ingredientes (
	ingrediente_id INTEGER PRIMARY KEY,
	ingrediente_nome TEXT NOT NULL
);

CREATE TABLE receitas (
   receita_id INTEGER PRIMARY KEY,
   nome TEXT NOT NULL,
   modo_preparo TEXT,
   tempo_preparo INTEGER,
   rendimento INTEGER,
   tipo INTEGER,
   nota INTEGER
);

INSERT INTO receitas (receita_id, nome, modo_preparo, tempo_preparo, rendimento, tipo, nota)
VALUES (1, "Arroz", "Ponha agua na panela ate cozinhar", 20, 2, "almoco", 5);

SELECT * 
   FROM receitas AS rc
   JOIN receitas_ingredientes AS ri 
      ON (rc.receita_id = ri.receita_id)
   JOIN ingredientes AS ig
      ON (ig.ingrediente_id = ri.ingrediente_id)
   WHERE rc.nome = "Arroz";

SELECT a.receita_id, a.nome 
FROM receitas AS a 
LEFT JOIN ingredientes AS b 
   ON a.receita_id = b.ingrediente_id
WHERE a.nome = "Arroz";

SELECT rc.nome, rc.modo_preparo
   FROM receitas AS rc
   JOIN receitas_ingredientes AS ri 
      ON (rc.receita_id = ri.receita_id)
   JOIN ingredientes AS ig
      ON (ig.ingrediente_id = ri.ingrediente_id)
   WHERE rc.nome = "Arroz";

SELECT ingredientes.ingrediente_nome 
FROM receitas
JOIN receitas_ingredientes 
    ON (receitas_ingredientes.receita_id = receitas.receita_id)
JOIN ingredientes 
    ON (ingredientes.ingrediente_id = receitas_ingredientes.ingrediente_id)
WHERE receitas.nome = "Arroz";

SELECT * FROM receitas WHERE nome = "Arroz";