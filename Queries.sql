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
   receita_id INTEGER,
   ingrediente_id INTEGER
);