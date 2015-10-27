/* Siconos-Kernel version 1.3.0, Copyright INRIA 2005-2011.
 * Siconos is a program dedicated to modeling, simulation and control
 * of non smooth dynamical systems.
 * Siconos is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * Siconos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Siconos; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Contact: Vincent ACARY vincent.acary@inrialpes.fr
 */

/*! \file DelayedSampledActuator.h
  An example on how to implement a user-defined actuator.
*/

#ifndef DelayedSampledActuator_H
#define DelayedSampledActuator_H

#include "Actuator.hpp"

class SiconosMatrix;

/** \class DelayedSampledActuator
 *  \brief Specific Actuator used as an example on how to implement a user-defined actuator.
 *  \author SICONOS Development Team - copyright INRIA
 *  \version 1.3.0.
 *  \date (Creation) february 09, 2007
 *
 *
 */
class DelayedSampledActuator : public Actuator
{
private:

  /** Default constructor
   */
  DelayedSampledActuator();

public:

  /** Constructor with a TimeDiscretisation.
   * \param a string, the type of the Actuator, which corresponds to the class type
   * \param a TimeDiscretisation*, (linked to a model).
   */
  DelayedSampledActuator(int, SP::TimeDiscretisation);

  /** Destructor
   */
  ~DelayedSampledActuator();

  /** initialize sensor data.
   */
  void initialize();

  /** capture data when the ActuatorEvent is processed ( for example set data[ActuatorEvent]=... )
   */
  void actuate();

  /** Encapsulates an operation of dynamic casting. Needed by Python interface.
   *  \param Actuator*
   * \return a pointer on the derived type
   */
  static DelayedSampledActuator* convert(Actuator* s);
};

#endif