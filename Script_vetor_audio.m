[y fs] = audioread('Wooden-Train-Whistle.wav',[1,31000])              #Lê o arquivo de audio
[linhas colunas] = size(y)                                            #Lê o tamanho de y
audio = reshape(round(255*y+128), colunas, linhas)                    #transpõe y e salva en 'audio'



dlmwrite('Pontos.h', "const unsigned char pontos[] PROGMEM = {", "")   
dlmwrite('Pontos.h', audio, ',',"-append")                             #salva o arquivo como .h
dlmwrite('Pontos.h', "};", "","-append")
