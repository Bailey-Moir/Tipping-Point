#pragma once
#include "devices.h"

/**
 * Contains all of the autonomous functions.
 * 
 * @author Bailey Moir
 */

namespace Syntech {
  const float width = 0;
  const float depth = 0;
  const float tileSize = 60.69;
  const float turnDiameter = 0;
  const float wheelDiameter = 0;

  /**
   * @brief  Turns the robot a specified amount.
   * @param  degrees: The amount of degress the robot will turn.
   * @param  efficiency: The multiplier that dictates the speed of the rotation.
   * @retval None
   */
  void turn(int degrees, float efficiency); 

  /**
   * @brief  Moves the robot for a specificed distance.
   * @param  distance: Centimeters. How far you want the robot to move and what direction (positive is forward, negative is backwards).
   * @param  efficiency: The multiplier that dictates the speed of the movement.
   * @retval None
   */
  void move(float distance, float efficiency); 

  /**
   * @brief  Moves the robot based an amount of time, no P, I, or D, based on an estimated distance.
   * @param  roughDistance: Centimeters. The estimated distance the robot should travel. 
   * @param  _dps: The amount of degrees per second you want the robot to move. MUST BE POSITIVE.
   * @retval None
   */
  void moveTimeDistance(float roughDistance, int _dps); 

  /**
   * @brief  Moves the robot for a specified amount of time at a specified speed.
   * @param  time: The miliseconds (amount of time) that you want the robot to move forward.  
   * @param  _dps: The amount of degrees per second you want the robot to move (positive is forward, negative is backwards).
   * @retval None
   */
  void moveTime(int time, int _dps); 

  /**
   * @brief  The proportional and intergral function. Everything is in the same unit.
   * @param  efficiency: The multiplier that dictates the speed.
   * @param  min: The minimum speed that the loop can send.
   * @param  max: The maximum speed that the loop can send.
   * @param  margin: The margin of error.
   * @param  desired: Where the independent variable should be when the proportional ends.
   * @param  independent: The variable that is changing over time.
   * @param  loop: What is looped every time that affects 'indepedent'
   * @param  stop: What to do at the end of the proportional.
   * @retval None
   */
  void P(const float efficiency, const int min, const int max, const float margin, const float desired, double(*independent)(), void(*loop)(double error), void(*stop)()); 
};