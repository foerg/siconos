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
#include "LinearTIEC.h"
using namespace std;

LinearTIEC::LinearTIEC(): LinearEC()
{
  this->type = LINEARTIEC;
}

LinearTIEC::LinearTIEC(EqualityConstraintXML *ecxml): LinearEC(ecxml)
{
  this->type = LINEARTIEC;
}

LinearTIEC::~LinearTIEC()
{}

void LinearTIEC::createEqualityConstraint(EqualityConstraintXML *ecXML ,
    int number,  SiconosMatrix *newG,
    std::vector<DSInputOutput*> *dsioVector)
{
  if (ecXML != NULL)
  {
    this->ecXML = ecXML;
    this->type = LINEARTIEC;
    this->fillEqualityConstraintWithEqualityConstraintXML();
  }
  else
  {
    this->ecXML = NULL;
    this->type = LINEARTIEC;
    this->number = number;
    G = new SimpleMatrix(*newG);
    this->dsioVector = *dsioVector;
  }
}

