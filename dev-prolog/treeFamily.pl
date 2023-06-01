bisavoPaterno(X,Y) :- avoPaterno(X,Z), pai(Z,Y).
bisavohPaterna(X,Y) :- avohPaterna(X,Z), pai(Z,Y).

avoPaterno(X,Y) :- pai(X,Z), pai(Z,Y).
avohPaterna(X,Y) :- mae(X,Z), mae(Z,Y).

pai(benedito, maria).
mae(iolanda, maria).
pai(benedito, helio).
mae(iolanda, helio).
pai(benedito, joseLuiz).
mae(iolanda, joseLuiz).
pai(benedito, teresa).
mae(iolanda, teresa).
pai(benedito, nila).
mae(iolanda, nila).
pai(benedito, sinesio).
mae(iolanda, sinesio).
pai(benedito, neuza).
mae(iolanda, neuza).
pai(benedito, joaoBatista).
mae(iolanda, joaoBatista).
pai(benedito, carminha).
mae(iolanda, carminha).
pai(benedito, carlos).
mae(iolanda, carlos).
pai(benedito, rae).
mae(iolanda, rae).

bisavoMaterno(X,Y) :- avoPaterno(X,Z), mae(Z,Y).
bisavohMaterna(X,Y) :- avohPaterna(X,Z), mae(Z,Y).

avoMaterno(X,Y) :- mae(X,Z), mae(Z,Y).
avohMaterna(X,Y) :- mae(X,Z), pai(Z,Y).

pai(joao, agna).
mae(Maria, agna).
pai(joao, arlete).
mae(Maria, arlete).
pai(joao, adair).
mae(Maria, adair).
pai(joao, joaoAilton).
mae(Maria, joaoAilton).
pai(joao, joseAdalton).
mae(Maria, joseAdalton).
pai(joao, anAlice).
mae(Maria, anAlice).
pai(joao, anaLucia).
mae(Maria, anaLucia).
pai(joao, adriana).
mae(Maria, adriana).

pai(carlos, rafael).
mae(adriana, rafael).
pai(carlos, nicolas).
mae(adriana, nicolas).

irmao(X,Y) :- pai(Z,X), pai(Z,Y), X\==Y.

tio(X,Y) :- irmao(Z,X), pai(Z,Y), X\==Y.
tia(X,Y) :- irmao(Z,X), mae(Z,Y), X\==Y.

ancestral(X,Y) :- pai(X,Y).
ancestral(X,Y) :- mae(X,Y).
ancestral(X,Y) :- pai(X,Z), ancestral(Z,Y).
ancestral(X,Y) :- mae(X,Z), ancestral(Z,Y).