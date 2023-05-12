avoPaterno(X,Y) :- pai(X,Z), pai(Z,Y).
avohPaterna(X,Y) :- mae(X,Z), mae(Z,Y).

pai(bindito, maria).
mae(fiica, maria).
pai(bindito, helio).
mae(fiica, helio).
pai(bindito, joseLuiz).
mae(fiica, joseLuiz).
pai(bindito, teresa).
mae(fiica, teresa).
pai(bindito, nila).
mae(fiica, nila).
pai(bindito, sinesio).
mae(fiica, sinesio).
pai(bindito, neuza).
mae(fiica, neuza).
pai(bindito, joaoBatista).
mae(fiica, joaoBatista).
pai(bindito, carminha).
mae(fiica, carminha).
pai(bindito, carlos).
mae(fiica, carlos).
pai(bindito, rae).
mae(fiica, rae).

avoMaterno(X,Y) :- mae(X,Z), mae(Z,Y).
avohMaterna(X,Y) :- mae(X,Z), pai(Z,Y).

pai(didi, agna).
mae(cida, agna).
pai(didi, arlete).
mae(cida, arlete).
pai(didi, adair).
mae(cida, adair).
pai(didi, joaoAilton).
mae(cida, joaoAilton).
pai(didi, joseAdalton).
mae(cida, joseAdalton).
pai(didi, anAlice).
mae(cida, anAlice).
pai(didi, anaLucia).
mae(cida, anaLucia).
pai(didi, adriana).
mae(cida, adriana).

pai(carlos, rafael).
mae(adriana, rafael).
pai(carlos, nicolas).
mae(adriana, nicolas).

irmao(X,Y) :- pai(Z,X), pai(Z,Y), X\==Y.

ancestral(X,Y) :- pai(X,Y).
ancestral(X,Y) :- mae(X,Y).
ancestral(X,Y) :- pai(X,Z), ancestral(Z,Y).
ancestral(X,Y) :- mae(X,Z), ancestral(Z,Y).

