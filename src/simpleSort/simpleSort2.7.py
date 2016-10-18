#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#
# A simple sorting program using square matrices
# and vectors in Python 2.7.x
# Author: Jesús Iván Gastelum Romero
# Contributors: Luis Edmundo Espinoza Larios
#
###################################################
from time import time
SIZE = 4
ARRAY_SIZE = SIZE * SIZE


#*-------------------------------*#
#            Fuctions             #
#*-------------------------------*#

def sort(array):
	'''
	  Sorts the given array in ascending order
	'''
	savedIndex = 0
	for i in range(ARRAY_SIZE):
		lowestNumber = array[i]
		for j in range(ARRAY_SIZE):
			j = j + (i + 1)
			if j < 16:
				#print (array[j],'----', lowestNumber)
				if array[j] < lowestNumber:
					lowestNumber = array[j]
					savedIndex = j
					flag = True
		if flag:
			swap = array[i]
			array[i] = lowestNumber
			array[savedIndex] = swap
		flag = False
	print '\nAascending order: ', array

def convertMatrixToArray(matrix, array):
	'''
	Convert a square matrix into an array
	'''
	for i  in range(SIZE):
		for j in range(SIZE):
			k = matrix[i][j]
			array.append(k)
	print '\nArray is: ' , array

def convertArrayToMatrix(array, matrix):
	'''
	Convert an array into a matrix
	'''
	k = 0
	for i  in range(SIZE):
		for j in range(SIZE):
			matrix[i][j] =  array[k]
			k = k + 1
	print '\nMatrix is: ' , matrix

def printSnakeMatrix(matrix):
	'''
	  Prints matrix in snake-style
	  e.g.
	  Given:
	        1, 2, 3
	        4, 5, 6
	  printing using the snake style:
	        1, 2, 3
	        6, 5, 4
	'''
	delta, startIndex = 0, 0
	print '\nMatrix Snake Style: \n'
	for i in range(SIZE):
		aux = (i % 2 != 0)
		delta =   -1  if aux else 1
		startIndex = (SIZE - 1) if  aux else 0
		for j in range(SIZE):
			print '\t|', matrix[i][startIndex],
			startIndex += delta
		print '\n'

#---------------End Functions---------------#

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

start_time = time()
matrix = [
			[5, 2, 12, 65],
    	    [404, 55, 291, -200],
       		[6, -23, -1, 79],
       		[1001, -9, 11, 98]
        ]
array = []

print '\nOriginal Matrix: ', matrix

convertMatrixToArray(matrix, array)
sort(array)
convertArrayToMatrix(array, matrix)
printSnakeMatrix(matrix)

end_time = time() - start_time
print '\nExecution Time: ', end_time