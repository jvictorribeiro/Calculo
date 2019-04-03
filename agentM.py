#Agente reativo baseado em modelos
import time 

agente = '@'
caminho = 0
areiaMove = 1	#agente tem que pular
buraco = 2		#agente deve tomar distancia e pular
ouro = 3

ambiente = [[0,1,0,0,2,0],
			[0,0,0,1,0,1],			#definicao do ambiente de tarefa
			[0,1,0,0,2,0],
			[0,0,2,0,1,0],
			[1,0,0,2,0,3]]

def printar(ambiente):		#printa o ambiente
	for secao in ambiente:
		print(secao)
	print("\n")

def agent(ambiente):
	pontuacao = 0
	for secao in ambiente:
		atual = 0
		for local in secao:


			#se local for igual a caminho, ele caminha
			if local == caminho:			
				secao[atual] = agente
				printar(ambiente)
				secao[atual] = caminho
				time.sleep(1)
				atual += 1

			#se local para onde ele está tentando ir for areia, ele pula
			elif local == areiaMove:	
				#se pula, ganha +3 ponto
				pontuacao += 3
				print ('Pontuacao do agente:', pontuacao)
				atual += 1

			#se local for igual a buraco ele toma distancia e pula
			elif local == buraco:
				salva = secao[atual-2]
				secao[atual-2] = agente
				printar(ambiente)
				secao[atual-2] = salva
				time.sleep(1)
				salva = secao[atual-1]
				secao[atual-1] = agente
				printar(ambiente)
				secao[atual-1] = salva
				time.sleep(1)
				#se volta para pular, perde 2 pontos e ganha 1 pelo pulo
				pontuacao += 1
				pontuacao += -2
				print ('Pontuacao do agente:', pontuacao)
				atual += 1

			else:
				print ('Agente conseguiu pegar o ouro')
				print ('Pontuacao final:', pontuacao)

	return ambiente

#main
printar(ambiente)
agent(ambiente)		
printar(ambiente)
