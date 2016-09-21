#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      
# A simple sorting program using Insertion Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios      
#                       					      
###################################################

from time import time

def bubbleSort(v):
	swaps = True
	while swaps:
		swaps = False
		for i in range(len(v)-1):
			if v[i] > v[i+1]:
				swaps = True
				temp = v[i]
				v[i] = v[i+1]
				v[i+1] = temp
	print v

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

start_time = time()
VECTOR = [7 , -5 , 0, 2 , 16, -9, 21, -874, 0, 8, 16, -210]
bubbleSort(VECTOR)
end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'