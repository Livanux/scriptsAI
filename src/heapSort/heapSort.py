#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      
# A simple sorting program using Heap Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     
#                       					      
###################################################

from time import time
start_time = time()

def sort(array, count):

	heapify(array, count)
	end = count - 1

	while (end > 0):
		temp = array[end]
		array[end] = array[0] 
		array[0] = temp
		end -=1
		v = siftDown(array, 0 , end)

	return v

def heapify(array, count):
	start = count - 1
	while start > 0:
		siftDown(array, start, count - 1)
		start -= 1

def siftDown(array, start, end):
	left  = 2 * start
	right = 2 * start + 1
	if (left <= end and array[left] > array[start]):
		largest = left
	else:
		largest = start
	if (right <= end and array[right] > array[largest]):
		largest = right
	print largest , start, array[start],array[largest]

	if (largest != start):
		temp = array[start]
		array[start] = array[largest] 
		array[largest] = temp
		siftDown(array, largest, end)
	
	return array


#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

VECTOR = [7, -5 , 0, 16, 2, -9, 21, -874, 0, 8, 16, -210]
v = sort(VECTOR, len(VECTOR))


print v

end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'