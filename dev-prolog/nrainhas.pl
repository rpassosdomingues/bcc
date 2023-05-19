% Problema das N rainhas - Solução do ChatGPT para simples testes e estudo.

% Predicado principal para resolver o problema das N rainhas
n_queens(N) :-
    length(Board, N), % Cria uma lista de tamanho N para representar as colunas
    domain(Board, 1, N), % Restringe os valores das colunas para 1 a N
    all_distinct(Board), % Assegura que todas as colunas tenham valores distintos
    safe_queens(Board), % Verifica se as rainhas estão em posições seguras
    labeling([], Board), % Atribui valores às variáveis não instanciadas
    print_board(Board). % Imprime o tabuleiro

% Predicado para verificar se as rainhas estão em posições seguras
safe_queens([]).
safe_queens([Q|Queens]) :-
    safe_queens(Queens, Q, 1),
    safe_queens(Queens).

% Predicado auxiliar para verificar se uma rainha está em uma posição segura
safe_queens([], _, _).
safe_queens([Q|Queens], Q0, D0) :-
    Q0 #\= Q, % Assegura que as rainhas não estejam na mesma coluna
    Q0 - Q #\= D0, % Assegura que as rainhas não estejam na mesma diagonal principal
    Q - Q0 #\= D0, % Assegura que as rainhas não estejam na mesma diagonal secundária
    D1 is D0 + 1,
    safe_queens(Queens, Q0, D1).

% Predicado para imprimir o tabuleiro
print_board(Board) :-
    length(Board, N),
    print_top_row(N),
    print_rows(Board, N, 1).

% Predicado auxiliar para imprimir a linha superior do tabuleiro
print_top_row(N) :-
    write('+'),
    print_horizontal_line(N),
    write('+'),
    nl.

% Predicado auxiliar para imprimir uma linha horizontal do tabuleiro
print_horizontal_line(0) :-
    nl.
print_horizontal_line(N) :-
    write('---+'),
    N1 is N - 1,
    print_horizontal_line(N1).

% Predicado auxiliar para imprimir as linhas do tabuleiro
print_rows([], _, _).
print_rows([Q|Queens], N, Row) :-
    print_row(Q, N, Row),
    Row1 is Row + 1,
    print_rows(Queens, N, Row1).

% Predicado auxiliar para imprimir uma linha do tabuleiro com as rainhas
print_row(Q, N, Row) :-
    write('|'),
    print_cells(N, Row, Q),
    nl,
    print_horizontal_line(N).

% Predicado auxiliar para imprimir as células de uma linha do tabuleiro
print_cells(0, _, _) :- !.
print_cells(N, Row, Q) :-
    (Q =:= Row -> write(' Q |'); write('   |')),
    N1 is N - 1,
    print_cells(N1, Row, Q).

% Exemplo de uso:
?- n_queens(4).
