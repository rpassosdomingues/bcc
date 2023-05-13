filho(A) ; filho(O)                        :- mae(A), pai(A).
filho(A) ; filho(B) ; filho(AB) ; filho(O) :- mae(A), pai(B).
filho(A) ; filho(B) ; filho(AB)            :- mae(A), pai(AB).
filho(A) ; filho(O)                        :- mae(A), pai(O).

filho(A) ; filho(B) ; filho(AB) ; filho(O) :- mae(B), pai(A).
filho(B) ; filho(O)                        :- mae(B), pai(B).
filho(A) ; filho(B) ; filho(AB)            :- mae(B), pai(AB).
filho(B) ; filho(O)                        :- mae(B), pai(O).

filho(A) ; filho(B) ; filho(AB)            :- mae(AB), pai(A).
filho(A) ; filho(B) ; filho(AB)            :- mae(AB), pai(B).
filho(A) ; filho(B) ; filho(AB)            :- mae(AB), pai(AB).
filho(A) ; filho(B)                        :- mae(AB), pai(O).

filho(A) ; filho(O)                        :- mae(O), pai(A).
filho(B) ; filho(O)                        :- mae(O), pai(B).
filho(A) ; filho(B)                        :- mae(O), pai(AB).
filho(O)                                   :- mae(O), pai(O).

filho(positivo)                            :- mae(positivo), pai(positivo).
filho(positivo) ; filho(negativo)          :- mae(positivo), pai(negativo).
filho(positivo) ; filho(negativo)          :- mae(negativo), pai(positivo).
filho(negativo)                            :- mae(negativo), pai(negativo).