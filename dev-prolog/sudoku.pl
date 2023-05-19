% Sudoku N por N - Solução do ChatGPT para simples testes e estudo.

% Predicado principal para resolver o Sudoku
sudoku(N) :-
    Size is N * N,
    empty_board(Size, Board), % Cria um tabuleiro vazio NxN
    sudoku_solver(Board, N), % Resolve o Sudoku
    print_board(Board, N). % Imprime o tabuleiro

% Predicado para resolver o Sudoku recursivamente
sudoku_solver(Board, N) :-
    fd_domain(Board, 1, N), % Restringe os valores do tabuleiro de 1 a N
    valid_rows(Board, N), % Verifica a validade das linhas
    valid_columns(Board, N), % Verifica a validade das colunas
    valid_blocks(Board, N), % Verifica a validade dos blocos
    fd_labeling(Board). % Atribui valores às variáveis não instanciadas

% Predicado para verificar a validade das linhas
valid_rows([], _).
valid_rows(Board, N) :-
    take(N, Board, Row), % Seleciona N elementos do início do tabuleiro
    fd_all_different(Row), % Verifica se os elementos são distintos
    drop(N, Board, Rest), % Descarta os primeiros N elementos do tabuleiro
    valid_rows(Rest, N). % Verifica a validade das linhas restantes

% Predicado para verificar a validade das colunas
valid_columns(Board, N) :-
    transpose(Board, Transposed), % Transpõe o tabuleiro
    valid_rows(Transposed, N). % Verifica a validade das linhas (que agora são colunas)

% Predicado para verificar a validade dos blocos
valid_blocks(Board, N) :-
    findall(Block, get_block(Board, N, Block), Blocks), % Obtém todos os blocos do tabuleiro
    valid_rows(Blocks, N). % Verifica a validade das linhas (que agora são blocos)

% Predicado para obter um bloco do tabuleiro
get_block(Board, N, Block) :-
    get_block(Board, N, N, Block). % Chama o predicado auxiliar

get_block(_, _, 0, []). % Caso base: todas as linhas foram processadas
get_block(Board, N, RowsLeft, Block) :-
    take(N, Board, Row), % Seleciona N elementos do início do tabuleiro
    drop(N, Board, Rest), % Descarta os primeiros N elementos do tabuleiro
    RowsLeft1 is RowsLeft - 1, % Atualiza o contador de linhas restantes
    get_block(Rest, N, RowsLeft1, RestBlock), % Chama recursivamente para as linhas restantes
    append(Row, RestBlock, Block). % Combina a linha atual com o restante do bloco

% Predicado auxiliar para selecionar os primeiros N elementos de uma lista
take(0, _, []).
take(N, [X|Xs], [X|Ys]) :-
    N > 0,
    N1 is N - 1,
    take(N1, Xs, Ys).

% Predicado auxiliar para descartar os primeiros N elementos de uma lista
drop(0, Xs, Xs).
drop(N, [_|Xs], Ys) :- N > 0, N1 is N - 1, drop(N1, Xs, Ys).

% Predicado para criar um tabuleiro vazio NxN
empty_board(N, Board) :- length(Board, N), maplist(length_list(N), Board).

% Predicado auxiliar para criar uma lista de tamanho N preenchida com variáveis não instanciadas
length_list(N, List) :-
length(List, N),
maplist(var, List).

% Predicado para imprimir o tabuleiro
print_board([], _).
print_board([Row|Rows], N) :- print_row(Row), print_board(Rows, N).

% Predicado auxiliar para imprimir uma linha do tabuleiro
print_row([]) :- nl.
print_row([Cell|Cells]) :- write(Cell), write(' '), print_row(Cells).

% Predicado para transpor uma matriz
transpose([], []).
transpose([F|Fs], Ts) :- transpose(F, [F|Fs], Ts).

transpose([], , []).
transpose([|Rs], Ms, [Ts|Tss]) :- lists_firsts_rests(Ms, Ts, Ms1), transpose(Rs, Ms1, Tss).

lists_firsts_rests([], [], []).
lists_firsts_rests([[F|Os]|Rest], [F|Fs], [Os|Oss]) :- lists_firsts_rests(Rest, Fs, Oss).
