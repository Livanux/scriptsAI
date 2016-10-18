#!/usr/bin/python
# -*- coding: utf-8 -*-
#                       					      
# 	A simple sorting program using Heap Sort   
# 	and vectors in Python 					      
# 	Author: Jesús Iván Gastelum Romero              
# 	Contributors: Luis Edmundo Espinoza Larios     

def goTo(matrix, From, To):
	current = From
	k = 0
	array = [None] * (len(matrix))
	while current != To:
		print current,'->',
		k += 1
		array[k] = current
		current = next(matrix, array, current)
	print current,

def next(matrix, array, node):
	SIZE , i = len(matrix), 0
	
	while (i < SIZE):
		if (matrix[node - 1 ][i] != node):
			if(wasVisited(array, matrix[node - 1][i])) != 1:
				return matrix[node - 1][i]
		i += 1
	return 0

def wasVisited(array, number):
	SIZE , i = len(matrix), 1
	
	while (i < SIZE):
		if array[i] == number:
			return 1
		i += 1
	return 0

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

matrix = [ 	
	[1, 2, 4], 
	[2, 1, 3], 
	[3, 2, 4, 5], 
	[4, 1, 3, 5],
	[5, 3, 4, 6], 
	[6, 5]
]
# print "Matrix Inicial: ", matrix

goTo(matrix, 4, 6)