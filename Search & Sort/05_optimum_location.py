from math import sqrt, inf

import numpy as np


def distance(x, y):
    return sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2)


def get_incident_point(point, line):
    # ax + by + c -> -bx + ay + c' -> -bx + ay + bx1 - ay1
    perpendicular = [-line[1], line[0],
                     (line[1]*point[0]) - (line[0]*point[1])]
    A = np.array([line[:2], perpendicular[:2]])
    B = np.array([line[-1:], perpendicular[-1:]])
    incident_point = np.matmul(np.linalg.inv(A), -1*B)
    return incident_point[0, 0], incident_point[1, 0]


def optimum_distance(points, line):
    min_sum_of_distances = inf
    for point in points:
        incident_point = get_incident_point(point, line)
        sum_of_distances = sum([distance(point, incident_point) for point in points])
        if sum_of_distances < min_sum_of_distances:
            min_sum_of_distances = sum_of_distances
    return min_sum_of_distances


points = [
    [-3, -2],
    [-1, 0],
    [-1, 2],
    [1, 2],
    [3, 4]
]

line = [1, -1, -3]

print(optimum_distance(points, line))
