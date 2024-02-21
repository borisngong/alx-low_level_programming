#!/usr/bin/python3
"""Function to calculate the perimeter of the island described in the grid"""


def island_perimeter(grid):
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    """Iterate through each cell in the grid"""
    for k in range(rows):
        for j in range(cols):
            """If the current cell is land"""
            if grid[k][j] == 1:
                """Check its neighbors to determine the perimeter"""
                perimeter += 4
                if k > 0 and grid[k - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[k][j - 1] == 1:
                    perimeter -= 2
    return perimeter
