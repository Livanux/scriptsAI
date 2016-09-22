#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      
# A simple sorting program using Merge Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     
#                       					      
###################################################

from time import time
start_time = time()

def sort(array, workArray, end):
	v = merge(array, 0, end, workArray)
	return v

def merge(array, start, end, workArray):

	if(end - start < 2):
		return

	middle = (end + start) / 2
	merge(array, start, middle, workArray)
	merge(array, middle, end, workArray)
	topDownMerge(array, start, middle, end, workArray)
	new_array = copyArray(array, start, end, workArray)
	return new_array

def topDownMerge(array, start, middle, end, workArray):
	i = start 
	j = middle
	k = start

	while k < end:
		if (i < middle and (j >= end or array[i] <= array[j])):
			workArray[k] = array[i]
			i += 1

		else:
			workArray[k] = array[j]
			j += 1
		k += 1
		
def copyArray(dst, start, end, src):
	i = start
	while i < end:
		dst[i] = src[i]
		i += 1
	return dst

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

VECTOR = [7, -5 , 0, 2, 16, -9, 21, -874, 0, 8, 16, -210]
workArray = [None] * len(VECTOR)

v = sort(VECTOR, workArray, len(VECTOR))


print v

end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'