'''
Agente reativo simples em python3
compilar com python3 agentR.py
'''
import time 
from random import randint

agente = "@"
limpo = 0
numSujeira = 0

ambiente = [[1,4,0,0,2,0],
			[0,0,3,1,0,4],			#definicao do ambiente de tarefa
			[0,1,0,0,2,0],
			[0,0,2,1,0,1],
			[2,0,1,0,0,4]]

def printar(ambiente):		#printa o ambiente
	for secao in ambiente:
		print(secao)
	print("\n")

def sujaAmbiente(ambiente):		#gera um ambiente com novas sujeiras
	for secao in ambiente:
		atual = 0
		for local in secao:
			secao[atual] = randint(0,7)
			atual += 1

	return ambiente

def agentAspirador(ambiente):
	pontuacao = 0
	global numSujeira
	for secao in ambiente:
		atual = 0
		for local in secao:


			#se local for sujo, limpa
			if (local == 1) or (local == 2) or (local == 3) or (local == 4):		
				numSujeira += 1
				secao[atual] = agente

				printar(ambiente)
				time.sleep(0.5)

				secao[atual] = limpo
				#se limpa, ganha +1 ponto
				pontuacao += 1
				print ('Pontuacao do agente:', pontuacao)
				atual += 1

			elif (local == 5) or (local == 6) or (local == 7):
				numSujeira += 1
				salva = secao[atual]
				secao[atual] = agente
				printar(ambiente)
				secao[atual] = salva
				time.sleep(0.5)
				#se vai para lugar sem sujeira perde ponto
				pontuacao += -1
				print ('Pontuacao do agente:', pontuacao)
				atual += 1

			#se n for sujo salva o local atual, coloca o agente no local e depois restaura
			else:			
				salva = secao[atual]
				secao[atual] = agente
				printar(ambiente)
				secao[atual] = salva
				time.sleep(0.5)
				atual += 1

	return ambiente

#main
ambiente = sujaAmbiente(ambiente)	#novo ambiente sujo
printar(ambiente)
agentAspirador(ambiente)		
printar(ambiente)
print ('Numero de sujeiras:', numSujeira)
