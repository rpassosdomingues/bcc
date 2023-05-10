pai(bindito, carlos).
mae(fiica, carlos).

pai(didi, adriana).
mae(cida, adriana).

pai(carlos, rafael).
pai(carlos, nicolas).
mae(adriana, rafael).
mae(adriana, nicolas).

irmao(rafael,nicolas) :- pai(X,rafael), pai(X,nicolas), rafael\==nicolas.

esposa(X,Y) :- pai(Y,Z), mae(X,Z).

avo_paterno(X,Y) :- pai(X,Z), pai(Z,Y).
avo_materno(X,Y) :- mae(X,Z), mae(Z,Y).

avoh_paterna(X,Y) :- mae(X,Z), mae(Z,Y).
avoh_materna(X,Y) :- mae(X,Z), pai(Z,Y).
