#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      
# A simple sorting program using Quick Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     
#                       					      
###################################################

from time import time
start_time = time()

def sort(array, left, right):

	if(left < right):
		pivot = partition(array, left, right)
		sort( array, left, pivot - 1 )
		sort( array, pivot + 1, right )
	return array

def partition(array, left, right): 

	pivot = array[left]
	izda = left + 1
	dcha = right

	while izda <= dcha:
		while ((izda <= dcha) and (array[izda]) <= pivot):
			izda += 1
		while ((izda <= dcha) and (array[dcha]) > pivot):
			dcha -= 1

		if izda < dcha:
			temp = array[izda]
			array[izda] = array[dcha] 
			array[dcha] = temp
			dcha -= 1
			izda += 1

	temp = array[left]
	array[left] = array[dcha] 
	array[dcha] = temp
	return dcha


#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

VECTOR = [7 , -5 , 0, 2 , 16, -9, 21, -874, 0, 8, 16, -210]

v = sort(VECTOR, 0, len(VECTOR) - 1 )
print v

end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'