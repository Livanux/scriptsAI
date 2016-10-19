#!/usr/bin/python
# -*- coding: utf-8 -*-
                      					      
# A simple sorting program using Heap Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     

import os, random, time
start_time = time.time()

'''
x	|	x	|	x
-------------------
x	|	x	|	x
-------------------
x	|	x	|	x

'''

board 	 = { 1:'1A', 2:'1B', 3:'1C', 4:'2A', 5:'2B', 6:'2C', 7:'3A', 8:'3B', 9:'3C' }

winner 	 = { 1:'', 2:'', 3:'', 4:'', 5:'', 6:'', 7:'', 8:'', 9:'' }

players	 = { 1:'ALGORITHM', 2:'RIVAL', 3:'X', 4:'O', 5:True, 6:[1,2,3,2,1,3], 'exit':True}

E = True

def printIntructions(op_board):
	global menu
	menu = ''
	print 'Instructions: Choose the place that you want.\nPor example: Press 1 for 1A or 9 for 3C place.\n\n'

	for i, j in op_board.items():
		if j == '1C' or j == '2C':
			print ' %s\n--------------------------\n' %(j),
			menu = menu + str(' %s\n-----------\n' %(i),)
		elif j != '3C':
			print ' %s \t|' %(j),
			menu = menu + str(' %s |' %(i),)
		elif j == '3C':
			print ' %s' %(j),
			menu = menu + str(' %s' %(i),)

def printBoard(board):
	for i, j in board.items():
		if i == 3 or i == 6:
			print '\t%s\n    -------------------------------------------\n' %(j),
		elif i != 9:
			print '\t%s \t|' %(j),
		elif i == 9:
			print '\t%s' %(j),

def whosNext(players):
	if players[5]:
		print  '\n\n\n\nYour Turn ', players[1]
		players[5] = False
	else:
		print  '\n\n\n\nYour Turn ', players[2]
		players[5] = True

def printPlay(board):
	os.system("clear")
	print 'Position on the Board: \n\n', menu , '\n\n\n'
	printBoard(board)


def algTurn(board, players):
	index = random.randint(0, 4)
	op = players[6][index]
	print 'Choose: ', players[6][index]
	validatePosition(board, 1, winner, op, 3)
	isw = isWinner(winner, 1, 4)
	time.sleep(1)

	return isw

def rivalTurn(board, players):
	op = raw_input('Choose: ')
	if op.isdigit() and int(op) >= 1 and int(op) <= 9:
		validatePosition(board, 2, winner, op, 4)
		isw = isWinner(winner, 2, 3)
	else:
		players[5], isw = False, True
		print 'Uups! Option Invalid'
		time.sleep(1)

	return isw
	
def validatePosition(board, pl, winner, op, f):

	if winner[int(op)]  == '':
		board[int(op)]  = players.get(f)
		winner[int(op)] = players.get(f)
	elif pl == 1 :
		players[5] = True
		print 'Error! Position not empty.'
		time.sleep(1)

	elif pl == 2:
		players[5] = False
		print 'Error! Position not empty.'
		time.sleep(1)

def isWinner(winner, pl, f):
	win = winner.values()
	if '' not in win[0:3] and players.get(f) not in win[0:3]:
		printPlay(board)
		print '\n\n', winner.values(), '\n', players[pl], 'WINNER'
		players['exit'] = False
		return False
		time.sleep(1)
	else:
		print 'NO...'
		return True
		time.sleep(1)



def validateStart(s):
	if s.isdigit():
		if int(s) == 1:
			return False, True
		elif int(s) == 2:
			return False, False
		else:
			print 'Uups! Number Invalid'
			time.sleep(1)
			return True, False
	else:
		print 'Only digits!'
		time.sleep(1)
	return True, False

#------------------
#	   MAIN 	  -
#------------------

printIntructions(board)

while E:
	print '\n\nDo you want start? \n1. Si\n2. No\n'
	s = raw_input('-> ')
	E, e = validateStart(s)

	while players.get('exit') and e:
		if '' in winner.values():
			printPlay(board)

			if players[5]:
				whosNext(players)
				algTurn(board, players)
			else:
				whosNext(players)
				e  = rivalTurn(board, players)

		else:
			print 'Stop'
			printPlay(board)

end_time = time.time() - start_time
print '\nExecution Time: ', end_time, '\n'