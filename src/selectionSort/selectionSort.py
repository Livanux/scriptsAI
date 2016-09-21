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

def selectionSort( v ):
	j=0
	N = len(v)
	for i in range(0, N-1):
		pos_min = i
		j = i + 1

		while j  < N:
			if(v[j] < v[pos_min]):
				pos_min = j
			j = j + 1
		tmp = v[i]
		v[i] = v[pos_min]
		v[pos_min] = tmp
	print v

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

start_time = time()
VECTOR = [7 , -5 , 0, 2 , 16, -9, 21, -874, 0, 8, 16, -210]
selectionSort(VECTOR)
end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'