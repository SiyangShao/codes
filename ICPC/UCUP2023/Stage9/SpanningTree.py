import numpy as np
from scipy.linalg import det

# Constructing the adjacency matrix for the graph
# The graph has 14 vertices, so we initialize a 14x14 matrix with zeros
for i in range(4):
    n, m = map(int, input().split())
    adj_matrix = np.zeros((n, n), dtype=int)

    edges = []
    for _ in range(m):
        u, v = map(int, input().split())
        edges.append((u, v))

    # The input is in the form (vertex1 vertex2), indicating an edge between these vertices
    # Adjusting for 0-indexing in Python

    # Populating the adjacency matrix
    for a, b in edges:
        adj_matrix[a, b] = 1
        adj_matrix[b, a] = 1

    # Constructing the Degree Matrix
    degree_matrix = np.diag(np.sum(adj_matrix, axis=1))

    # Constructing the Laplacian Matrix
    laplacian_matrix = degree_matrix - adj_matrix

    # Removing the first row and first column to create a cofactor
    cofactor_matrix = laplacian_matrix[1:, 1:]

    # Calculating the determinant of the cofactor matrix
    # The determinant gives the number of spanning trees
    num_spanning_trees = int(round(det(cofactor_matrix)))
    num_spanning_trees = num_spanning_trees % 998244353
    my_ans = int(input())
    if my_ans == num_spanning_trees:
        print("Correct!")
    else:
        print("Wrong!")
        print("Expected:", num_spanning_trees)
        print("Your answer:", my_ans)
