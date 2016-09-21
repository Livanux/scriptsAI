#!/usr/bin/python
# -*- coding: utf-8 -*-

###################################################
#                       					      #
# A simple sorting program using Insertion Sort   #
# and vectors in Python 					      #
# Author: Jesús Iván Gastelum Romero              #
# Contributors: Luis Edmundo Espinoza Larios      #
#                       					      #
###################################################

from time import time


def insertionSort(v):
	for i in range(1,len(v)):
		tmp = v[i]
		j=i
		while j > 0 and (tmp < v[j - 1]):
			v[j] = v[j-1]
			j = j - 1
		v[j] = tmp
	print '\nInsertion Sort:\n ', v

#*-----------------------------*#
#         MAIN PROGRAM          #
#*-----------------------------*#

start_time = time()
VECTOR = [7 , -5 , 0, 2 , 16, -9, 21, -874, 0, 8, 16, -210]
insertionSort(VECTOR)
end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'