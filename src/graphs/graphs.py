#!/usr/bin/python
# -*- coding: utf-8 -*-
                      					      
# A simple sorting program using Heap Sort   
# and vectors in Python 					      
# Author: Jesús Iván Gastelum Romero              
# Contributors: Luis Edmundo Espinoza Larios     

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


	print visited


	dfs(graph, visited, start, end)

	print '\n'


def  dfs(graph, visited, current, end):

	currentIndex = getIndex(graph, current)

	print  '->', graph[currentIndex][0],

	if current == end:
		return 1

	visited[currentIndex] = 1

	i= 0
	print visited

	while i < SIZE and graph[currentIndex][i] != 0:

		print '\n', i, graph[currentIndex][i]

		visitedIndex = getIndex(graph, graph[currentIndex][i])

		if (not visited[visitedIndex]):
			if (dfs(graph, visited, graph[currentIndex][i], end)):
				return 1

		i += 1
	return 0



def getIndex(graph, number):

	i = 0

	while i < SIZE:
		if (graph[i][0] == number):
			return i
		i += 1

	return (i-1)

#---------MAIN----------#

goTo(graph, 9, 8)