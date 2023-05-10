pai(tare, abraao).
pai(tare, nacor).
pai(tare, aran).
pai(aran, lot).
pai(aran, melca).
pai(aran, jesca).
mae(sara, isaac).

fem(X):-mae(X,Y).
irmao(X,Y):-pai(P,X),pai(P,Y), X\==Y.
tio(T,X):-pai(P,X),irmao(P,T).
