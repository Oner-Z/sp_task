#ifndef BALLISTIC_SOLVER_HPP
#define BALLISTIC_SOLVER_HPP

// Physical constants
constexpr double GRAVITY = 9.8;  // m/s^2
constexpr double BULLET_VELOCITY = 20.0;  // m/s

// TODO: Implement ballistic calculation functions
// Hint: For projectile motion with initial velocity v0 and angle theta:
// - Horizontal: x = v0 * cos(theta) * t
// - Vertical: z = v0 * sin(theta) * t - 0.5 * g * t^2
//
// You need to solve for pitch and yaw angles given:
// - Gimbal position (from TF)
// - Target position (from topic)
// - Initial velocity and gravity

#endif // BALLISTIC_SOLVER_HPP
