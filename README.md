# Embedded-Linux-Drivers
Códigos produzidos durante o estudo em linux embarcado.

## Hello World

Primeiro módulo desenvolvido que imprime "Hello World" quando é inserido e "Good bye, World" quando removido.

## Major e Minor

Módulo que aloca de forma manual e dinâmica os numeros de major e minor de um módulo.

## Device Filers

Módulo para criar um arquivo de forma dinâmica e deixar acessivel no diretorio /dev/

## File Operations

Módulo trabalhando com arquivos de operação, para as seguintes operações de arquivos foi criada uma função de callback

| File Operation  | Function Describe  |
|-----------------|--------------------|
| Open            | Imprime a string "File Open Function"|
| Release         | Imprime a string "File Release Function"|
| Write           | Imprime a string "File Write Function" |
| Read            | Imprime a string "File Read Function"   |
