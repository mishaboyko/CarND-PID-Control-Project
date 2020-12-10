#ifndef PID_H
#define PID_H

#include <limits>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param Kp_ Proportional coefficient
   * @param Ki_ Integral coefficient
   * @param Kd_ Differential coefficient
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /*
   * Calculate steer angle based on the new CTE.
   */
  double CalculateSteerAngle(double cte_in);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error (integral).
   */
  void TotalError(double cte);

 private:
  double last_cte = std::numeric_limits<double>::max();
  double diff_cte = 0;
  double int_cte = 0;
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * PID Coefficients
   */
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H