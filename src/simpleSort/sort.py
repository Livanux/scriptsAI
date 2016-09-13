#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      #
# A simple sorting program using square matrices  #
# and vectors in python 2.7.X 					  #
# Author: Jesús Iván Gastelum Romero              #
# Contributors: Luis Edmundo Espinoza Larios      #
#                       					      #
###################################################

from time import time
SIZE = 4
ARRAY_SIZE = SIZE * SIZE




def sort(array):
	savedIndex = 0
	for i in range(ARRAY_SIZE):
		lowestNumber = array[i]
		for j in range(ARRAY_SIZE):
			j = j + (i + 1)
			if j < 16:
				if array[j] < lowestNumber:
					lowestNumber = array[j]
					savedIndex = j
		swap = array[i]
		array[i] = lowestNumber
		array[savedIndex] = swap
	print '\nAascending order: ', array


def convertMatrixToArray(matrix, array):
	for i  in range(SIZE):
		for j in range(SIZE):
			k = matrix[i][j]
			array.append(k)
	print '\nArray is: ' , array

def convertArrayToMatrix(array, matrix):
	k = 0
	for i  in range(SIZE):
		for j in range(SIZE):
			matrix[i][j] =  array[k]
			k = k +1
	print '\nMatrix is: ' , matrix

def printSnakeMatrix(matrix):
	pass



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
print '\nTiempo de Ejecucion', end_time
