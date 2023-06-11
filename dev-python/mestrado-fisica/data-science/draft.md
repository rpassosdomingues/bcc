## Relatório: Atividade Prática -- Fotometria de Galáxias


# Introdução

Escolhi as galáxias a partir dos dados do VizieR e das imagens do SLOAN SDSS, um dos maiores surveys existentes. O SDSS é do hemisfério norte, então restringimos a busca apenas a objetos com DEC > 0.

- M81 (Por ser a galáxia elíptica que melhor ajusta o perfil de De Vaucouleurs)

- NGC blablabla (por tal motivo)

Os dados principais colhidos no VizieR foram RA, DEC, name, T (classificação morfológica de Hubble [0 < T < 7], e redshift 0.0002 < z < 0.02).

# Metodologia

Foram ajustadas isofotas às imagens.fit das galáxias escolhidas, para isso, utilizamos a tarefa ellipse da biblioteca astropy. O output do programa foi os parâmetros da elipse, semieixos polar e equatorial, para enfim ajustar o perfil de brilho de De Vaucouleurs aos perfis obtidos.

A partir dos ajustes dos perfis obtidos, foi possível calcular a luminosidade total da galáxia, seu raio efetivo (tamanho físico real) e seu brilho superficial efetivo.

# Resultados

O gráfico mag ($\mu$) VS raio aparente ($R^{1/4}$) deu algo muito próximo a uma reta. A imagem do resíduo mostrou-se satisfatória, não havendo muitas estruturas presentes.

Foi feito o cálculo dos valores, vide tabela abaixo...

# Propagação de erros

Apresentar erros dos ajustes e detalhes estatísticos

# Comparação com os dados da literatura

Apresentar concordância

# Considerações Finais

Considero que os dados foram...

# Referências

[1] SDSS
[2] DS9
[3] IRAF
[4] Peter Scheneider
[5] outras