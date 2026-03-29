import numpy as np
from numpy import tan
from numpy import pi as PI



# # P_B = B_A^-1*P_A
# # P_A = [2,1,1]
# B_A = np.array([[-2, 0, 0],
#                 [0, -1, 0], 
#                 [6, 6, 1]]).T

# P_A = np.array([2, 1, 1]).reshape(3, 1)

# P_B = np.linalg.inv(B_A) @ P_A

# print(np.linalg.inv(B_A))
# # print(P_A)
# # print(P_B)

#--------------------------------------------------

M = np.array([[1, tan(PI/4), 0],
              [0, 1, 0],
              [0, 0, 1]])

P = np.array([1, 1, 1])
Q = M @ P
print(Q)