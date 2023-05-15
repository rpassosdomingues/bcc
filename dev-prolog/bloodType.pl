tipoSanguineo(filho, A) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, A), tipoSanguineo(pai, A).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB) ; tipoSanguineo(filho, O) 	:- tipoSanguineo(mae, A), tipoSanguineo(pai, B).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB)            			:- tipoSanguineo(mae, A), tipoSanguineo(pai, AB).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, A), tipoSanguineo(pai, O).

tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB) ; tipoSanguineo(filho, O) 	:- tipoSanguineo(mae, B), tipoSanguineo(pai, A).
tipoSanguineo(filho, B) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, B), tipoSanguineo(pai, B).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB)            			:- tipoSanguineo(mae, B), tipoSanguineo(pai, AB).
tipoSanguineo(filho, B) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, B), tipoSanguineo(pai, O).

tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB)            			:- tipoSanguineo(mae, AB), tipoSanguineo(pai, A).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB)            			:- tipoSanguineo(mae, AB), tipoSanguineo(pai, B).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B) ; tipoSanguineo(filho, AB)            			:- tipoSanguineo(mae, AB), tipoSanguineo(pai, AB).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B)                        					:- tipoSanguineo(mae, AB), tipoSanguineo(pai, O).

tipoSanguineo(filho, A) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, O), tipoSanguineo(pai, A).
tipoSanguineo(filho, B) ; tipoSanguineo(filho, O)                        					:- tipoSanguineo(mae, O), tipoSanguineo(pai, B).
tipoSanguineo(filho, A) ; tipoSanguineo(filho, B)                        					:- tipoSanguineo(mae, O), tipoSanguineo(pai, AB).
tipoSanguineo(filho, O)                                   							:- tipoSanguineo(mae, O), tipoSanguineo(pai, O).

tipoRh(filho, rhPositivo)                            							:- tipoRh(mae, rhPositivo), tipoRh(pai, rhPositivo).
tipoRh(filho, rhPositivo) ; tipoRh(filho, rhNegativo)          						:- tipoRh(mae, rhPositivo), tipoRh(pai, rhNegativo).
tipoRh(filho, rhPositivo) ; tipoRh(filho, rhNegativo)          						:- tipoRh(mae, rhNegativo), tipoRh(pai, rhPositivo).
tipoRh(filho, rhNegativo)                            							:- tipoRh(mae, rhNegativo), tipoRh(pai, rhNegativo).
