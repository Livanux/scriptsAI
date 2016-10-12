#!/usr/bin/python
# -*- coding: utf-8 -*-
                      					      
# A simple sorting program using Heap Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     

from time import time
start_time = time()


graph = [
        [1, 2, 4, 8],
        [2, 1, 3, 4],
        [3, 2, 6, 7],
        [4, 1, 2],
        [5, 6, 9],
        [6, 3, 5, 7],
        [7, 3, 6],
        [8, 1],
        [9, 5],
        [10]
		]

SIZE = len(graph)

def goTo(graph, start, end):

	visited = [0] * len(graph)
	startIndex = getIndex(graph, start)
	visited[startIndex] = 1

	dfs(graph, visited, start, end)

def  dfs(graph, visited, current, end):
	currentIndex = getIndex(graph, current)

	print  graph[currentIndex][0], '->', 

	if current == end:
		return 1

	visited[currentIndex] = 1

	for  i in range(len(graph[currentIndex])):
		visitedIndex = getIndex(graph, graph[currentIndex][i])

		if (not visited[visitedIndex]):

			if (dfs(graph, visited, graph[currentIndex][i], end)):
				return True
		i += 1
	return False


def getIndex(graph, number):
	i = 0
	while i < SIZE:
		if (graph[i][0] == number):
			return i
		i += 1
	return -1

#---------MAIN----------#

goTo(graph, 9, 8)


end_time = time() - start_time
print '\nExecution Time: ', end_time, '\n'