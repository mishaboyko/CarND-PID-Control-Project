#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0;
  i_error = 0;
  d_error = 0;
}

double PID::CalculateSteerAngle(double cte_in){
  // check, if this is first message. If so - create dummy prev_cte for plausibility.
  if(std::numeric_limits<double>::max() == last_cte){
    last_cte = cte_in * (9/10);
  }
  UpdateError(cte_in);
  return -Kp * cte_in - Ki * int_cte - Kd * diff_cte ;
}


void PID::UpdateError(double cte_in) {
  /**
   * Update PID errors based on cte.
   */
  diff_cte = cte_in - last_cte;
  TotalError(cte_in);
  last_cte = cte_in;
}

void PID::TotalError(double cte_in) {
  /**
   * Calculate the total error
   */
  int_cte += cte_in;
}