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

CREATE TABLE receitas_ingredientes (
	id INTEGER PRIMARY KEY,
	receita_id INTEGER NOT NULL,
	ingrediente_id INTEGER NOT NULL
);

INSERT INTO receitas (receita_id, nome, modo_preparo, tempo_preparo, rendimento, tipo, nota)
VALUES (1, "Arroz", "Ponha agua na panela ate cozinhar", 20, 2, "almoco", 5);