/* Siconos-Kernel version 2.0.0, Copyright INRIA 2005-2006.
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

/*! \file LagrangianLinearTIDS.h

*/
#ifndef LAGRANGIANTIDS_H
#define LAGRANGIANTIDS_H

#include "LagrangianDS.h"
#include "LagrangianLinearTIDSXML.h"

class LagrangianLinearTIDSXML;

//! Lagrangian Linear Systems with time invariant coefficients - Derived from LagrangianDS
/**  \author SICONOS Development Team - copyright INRIA
 *  \version 2.0.0.
 *  \date (Creation) Apr 29, 2004
 *
 *
 * The class LagrangianLinearTIDS  allows to define  and compute a generic ndof-dimensional
 * Lagrangian Linear Time Invariant Dynamical System of the form :
 * where
 * \f[
 * M \ddot q + C \dot q + K q =  F_{Ext}(t) + p,
 * \f]
 * where
 *    - \f$q \in R^{ndof} \f$ is the set of the generalized coordinates,
 *    - \f$ \dot q  \in R^{ndof} \f$  the velocity, i. e. the time derivative of the  generalized coordinates.
 *    - \f$ \ddot q  \in R^{ndof} \f$  the acceleration, i. e. the second time derivative of the  generalized coordinates.
 *    - \f$ p  \in R^{ndof} \f$  the forces due to the Non Smooth Interaction. In particular case of Non Smooth evolution,
 *       the variable p contains the impulse and not the force.
 *    -  \f$ M \in  R^{ndof \times ndof} \f$ is Mass matrix stored in the SiconosMatrix mass.
 *    -  \f$ K \in  R^{ndof \times ndof} \f$ is the stiffness matrix stored in the SiconosMatrix K.
 *    -  \f$ C \in  R^{ndof \times ndof} \f$ is the viscosity matrix stored in the SiconosMatrix C.
 *
 *
 *
 *
 *    -  \f$ F_{Int}(\dot q , q , t)\f$ the internal forces stored in the SimpleVector fExt.
 *    -  \f$ F_{Ext}(t) \f$ the external forces stored in the SimpleVector fInt.
 *
 *
 * One word on the initial condition.
 *
 * One word on the bilateral constraint
 *
 *
 * The master Class LagrangianDS is specified as follows :
 *
 *    -  \f$ NNL(\dot q, q) = 0 \f$
 *    -  \f$ F_{Int}(\dot q , q , t) = C \dot q + K q \f$
 *
 *
 *
 * Links with first order DynamicalSystem top-class are:
 *
 * \f$ n= 2 ndof \f$
 * \f$ x = \left[\begin{array}{c}q \\ \dot q\end{array}\right]\f$
 *
 * The rhs is given by:
 * \f[
 * f(x,t) = \left[\begin{array}{c}
 *  \dot q  \\
 * M^{-1}(q)\left[F_{Ext}( q , t) - C \dot q - K q   \right]\\
 * \end{array}\right]
 * \f]
 * Its jacobian is:
 * \f[
 * \nabla_{x}f(x,t) = \left[\begin{array}{cc}
 *  0  & I \\
 * -M^{-1}K  -M^{-1}C) \\
 * \end{array}\right]
 * \f]
 *  The input due to the non smooth law is:
 * \f[
 * r = \left[\begin{array}{c}0 \\ p \end{array}\right]
 * \f]
 */
class LagrangianLinearTIDS : public LagrangianDS
{
private:

  /** default constructor
  */
  LagrangianLinearTIDS();

  /** specific matrix for a LagrangianLinearTIDS */
  SiconosMatrix *K;

  /** specific matrix for a LagrangianLinearTIDS */
  SiconosMatrix *C;

  /** set links with DS members
  */
  void connectToDS();

  /** set all allocation flags (isAllocated map)
  *  \param bool: value for flags
  */
  void initAllocationFlags(const bool = true);

  /** set all plug-in flags (isPlugin map) to val
  *  \param a bool
  */
  void initPluginFlags(const bool);

public:

  /** constructor from an xml file
  *  \param DynamicalSystemXML * : the XML object for this DynamicalSystem
  *  \param NonSmoothDynamicalSystem* (optional): the NSDS that owns this ds
  *  \exception RuntimeException
  */
  LagrangianLinearTIDS(DynamicalSystemXML * dsXML, NonSmoothDynamicalSystem* = NULL);

  /** constructor from a set of data
   *  \param int : the number for this DynamicalSystem
   *  \param int : dimension of this DynamicalSystem
   *  \param SimpleVector: initial coordinates of this DynamicalSystem
   *  \param SimpleVector : initial velocity of this DynamicalSystem
   *  \param SiconosMatrix : mass of this DynamicalSystem
   *  \param SiconosMatrix : matrix K of this DynamicalSystem
   *  \param SiconosMatrix : matrix C of this DynamicalSystem
   *  \exception RuntimeException
   */
  LagrangianLinearTIDS(const int, const unsigned int ndof, const SimpleVector&, const SimpleVector&, const SiconosMatrix&, const SiconosMatrix&, const SiconosMatrix&);

  /** constructor from a set of data
   *  \param int : the number for this DynamicalSystem
   *  \param int : dimension of this DynamicalSystem
   *  \param SimpleVector: initial coordinates of this DynamicalSystem
   *  \param SimpleVector : initial velocity of this DynamicalSystem
   *  \param SiconosMatrix : mass of this DynamicalSystem
   *  \exception RuntimeException
   */
  LagrangianLinearTIDS(const int, const unsigned int ndof, const SimpleVector&, const SimpleVector&, const SiconosMatrix&);

  /** copy constructor
  *  \param a Dynamical system to copy
  */
  LagrangianLinearTIDS(const DynamicalSystem &);

  // destructor
  ~LagrangianLinearTIDS();

  /** check that the system is complete (ie all required data are well set)
  * \return a bool
  */
  bool checkDynamicalSystem();

  /** dynamical system initialization function: mainly set memory and compute value for initial state values.
  *  \param string: simulation type
  *  \param time of initialisation, default value = 0
  *  \param the size of the memory, default size = 1.
  */
  void initialize(const std::string&, double = 0, unsigned int = 1) ;

  /** dynamical system update: mainly call compute for all time or state depending functions (mass, FInt ...).
  *  \param current time
  */
  void update(const double);

  // --- GETTERS AND SETTERS ---

  // -- K --
  /** get the value of K
  *  \return SimpleMatrix
  */
  inline const SimpleMatrix getK() const
  {
    return *K;
  }

  /** get K
  *  \return pointer on a SiconosMatrix
  */
  inline SiconosMatrix* getKPtr() const
  {
    return K;
  }

  /** set the value of K to newValue
  *  \param SiconosMatrix newValue
  */
  void setK(const SiconosMatrix&);

  /** set K to pointer newPtr
  *  \param SiconosMatrix * newPtr
  */
  void setKPtr(SiconosMatrix *newPtr);

  // -- C --
  /** get the value of C
  *  \return SimpleMatrix
  */
  inline const SimpleMatrix getC() const
  {
    return *C;
  }

  /** get C
  *  \return pointer on a SiconosMatrix
  */
  inline SiconosMatrix* getCPtr() const
  {
    return C;
  }

  /** set the value of C to newValue
  *  \param SiconosMatrix newValue
  */
  void setC(const SiconosMatrix&);

  /** set C to pointer newPtr
  *  \param SiconosMatrix * newPtr
  */
  void setCPtr(SiconosMatrix *newPtr) ;

  /** Default function to the right-hand side term
  *  \param double time : current time
  *  \param bool isDSup : flag to avoid recomputation of operators
  *  \exception RuntimeException
  */
  void computeRhs(const double, const bool  = false);

  /** Default function to jacobian of the right-hand side term according to x
  *  \param double time : current time
  *  \param bool isDSup : flag to avoid recomputation of operators
  *  \exception RuntimeException
  */
  void computeJacobianXRhs(const double, const bool  = false);

  // --- Miscellaneous ---

  /** copy the data of the DS to the XML tree
  *  \exception RuntimeException
  */
  void saveDSToXML();

  /** print the data onto the screen
  */
  void display() const;

  static LagrangianLinearTIDS* convert(DynamicalSystem* ds);

  /** overload LagrangianDS corresponding function
  * \return a double, always zero.
  */
  double dsConvergenceIndicator()
  {
    return 0.0;
  }
};

#endif // LAGRANGIANTIDS_H
