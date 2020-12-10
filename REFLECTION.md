# Reflection

## The effect of each of the P, I, D components

Each of the PID Coefficients in combination with the corresponding Error value, has it's influence on the final steering angle of the vehicle.

**P**: The proportional factor $\tau_p$ in combination with the $CTE$ allows the algorithm to steer the vehicle towards the ideal trajectory, proportionally to the CrossTrackError from the prior measurement. Is set to 0.2 to avoid abrupt turns as much as possible.

**I**: The integral factor $\tau_i$ in combination with $\Sigma$ $CTE$ allows the algorithm to detect and smooth out the possible *bias*, introduced by the mechanics. Is almost neglactable, since empirical observations have shown no bias in the vehicle's mechanic concept.

**D**: The differential factor $\Tau_d$ in combination with $\Delta CTE$ enables the *gradual* approaching the target trajectory and *avoids/smoothes-out* the overshoothing problem, introduced by the proportional factor **P**. In my solution this parameter is quite high to make the vehicle "stick" to the given trajectory, once the CTE is minimized.

## Choosing final hyperparameters

By choosing the initial parameters, I went through 3 steps:

1. Tried out the parameters from the best_error from the lectures. Here the car was steering too strong in the direction of CTE reduction.
2. Tried out the initial parameters from the lectures. These values fit almost perfectly to the final solution.
3. Manually twiggled parameters on the problematic peaces of road to reach the final behavior of the vehicle.