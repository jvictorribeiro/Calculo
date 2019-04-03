#Agente reativo baseado em modelos
import time 

agente = '@'
caminho = 0
areiaMove = 1	#agente tem que pular
buraco = 2		#agente deve tomar distancia e pular
ouro = 3

ambiente = 		[[0,1,0,0,1,0],
			[0,2,0,0,2,0],		#definicao do ambiente de tarefa
			[0,1,0,0,1,0],
			[0,2,0,0,2,0],
			[0,1,0,0,1,3]]

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
				#se caminha ganha 1 ponto
				pontuacao += 1
				print ('Pontuacao do agente:', pontuacao)
				atual += 1

			#se local para onde ele está tentando ir for areia, ele pula
			elif local == areiaMove:	
				#se pula, perde 1 ponto
				pontuacao += -1
				#print ('Pontuacao do agente:', pontuacao)
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
				#se volta para pular, perde 2 pontos
				pontuacao += -2
				print ('\nPontuacao do agente:', pontuacao)
				atual += 1

			else:	#se pega o ouro ganha 5 pontos
				print ('Agente conseguiu pegar o ouro')
				pontuacao += 5
				print ('Pontuacao final:', pontuacao)
	return ambiente

#main
printar(ambiente)
agent(ambiente)		
printar(ambiente)
