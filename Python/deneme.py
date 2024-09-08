import numpy as np

def simulate_discrete_lds(A, B, C, D, x0, T, control_inputs):
    states = [x0] # store state vectors
    outputs = [] # store output vectors

    # loop over the time horizon (t = 0 to t = T-1)
    for t in range(T):
        x_t = states[-1] # most recent vector from states list
        u_t = control_inputs[t] # control input for current time step t

        x_next = A @ x_t + B @ u_t # compute next state vector using given equation
        states.append(x_next)

        y_t = C @ x_t + D @ u_t # compute output using given equation
        outputs.append(y_t)

    return states, outputs


## example from slide 18

v1 = np.array([[1], [0]])
v2 = np.array([[-0.5], [1]])
v3 = np.array([[1], [1]])
h = 1

A = np.array([
    [1, h, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, h],
    [0, 0, 0, 1]
])

B = np.block([
    [(0.5 * h**2) * v1, h * v1, np.zeros_like(v1)],
    [(0.5 * h**2) * v2, h * v2, np.zeros_like(v2)],
    [(0.5 * h**2) * v3, h * v3, np.zeros_like(v3)]
])


C = np.array([
    [1, 0, 0, 0],
    [0, 0, 1, 0]
])

D = np.zeros((2, 3)) # assume D is zero matrix (not mentioned)

x0 = np.zeros((4, 1))

T = 10

control_inputs = [np.random.randn(3, 1) for _ in range(T)] # generates column vector of random numbers

states, outputs = simulate_discrete_lds(A, B, C, D, x0, T, control_inputs)

for t in range(T):
    print(f"Time step {t}:")
    print(f"State: {states[t].flatten()}")
    print(f"Output: {outputs[t].flatten()}")