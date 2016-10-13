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

op_board = { 1:'1A', 2:'1B', 3:'1C', 4:'2A', 5:'2B', 6:'2C', 7:'3A', 8:'3B', 9:'3C' } 

players	 = { 1:'ALGORITHM', 2:'RIVAL', 3:'X', 4:'O', 5:True, 6:[1,3,5,7,9]}

EXIT =True

def printIntructions(op_board):
	global menu
	menu = ''
	print '\tInstructions: Choose the place that you want.\n\tPor example: Press 1 for 1A or 9 for 3C place.\n'

	for i, j in op_board.items():
		if j == '1C' or j == '2C' or j == '3C':
			print ' %s\n--------------------------\n' %(j),
		else:
			print ' %s \t|' %(j),

		menu = menu + str('%s = %s \n' %(i,j))

def printBoard(board):
	for i, j in board.items():
		if i == 3 or i == 6 or i == 9:
			print ' %s\n--------------------------\n' %(j),

		else:
			print '%s \t|' %(j),


def whosNext(players):
	global ficha

	if players[5]:
		print  '\nYour Turn ', players[1]
		players[5] = False
	else:
		print  '\nYour Turn ', players[2]
		players[5] = True

def printPlay(board):
	os.system("cls")
	print menu , '\n'
	printBoard(board)

def algTurn(board, players):

	index = random.randint(0, 4)

	op = players[6][index]

	print 'Choose: ', players[6][index]

	board[op] = players.get(3)
	winner[op] = players.get(3)
	time.sleep(1)


def rivalTurn(board, players):

	op = raw_input('Choose: ')

	if op.isdigit() and int(op) >= 1 and int(op) <= 9:
		board[int(op)] = players.get(4)
		winner[int(op)] = players.get(4)
	else:
		players[5] = False
		print 'Uups! Option Invalid'
		time.sleep(1)


#------------------
#	   MAIN 	  -
#------------------

printIntructions(op_board)
print 'Are you ready!? \n1. Yes!\n2. No.\n'
s = input('-> ')
if s == 2:
	EXIT = False

while (EXIT):
	if '' in winner.values():
		printPlay(board)

		if players[5]:
			whosNext(players)
			algTurn(board, players)
		else:
			whosNext(players)
			rivalTurn(board, players)

	else:
		EXIT = False
		print 'Stop'
		printPlay(board)

end_time = time.time() - start_time
print '\nExecution Time: ', end_time, '\n'