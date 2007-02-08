/* Siconos-Kernel version 1.2.0, Copyright INRIA 2005-2006.
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

# include <iostream>
# include <cstdlib>
# include <string>
# include <cstdio>
# include "SensorFactory.h"

using namespace std;

namespace SensorFactory
{

Registry& Registry::get()
{
  static Registry instance;
  return instance;
}

void Registry::add(const string& name, object_creator creator)
{
  factory_map[name] = creator;
}

Sensor* Registry::instantiate(const std::string& name, TimeDiscretisation* t)
{
  MapFactoryIt it = factory_map.find(name) ;

  if (it == factory_map.end())
    RuntimeException::selfThrow("Registry::instantiate (SensorFactory) failed, no class named: " + name);

  // cout << endl << "Factory instance for class" << name << endl ; // for test purposes only
  return (it->second)(name, t) ; // run our factory
}

Registration::Registration(const string& name, object_creator creator)
{
  //  cout << endl << "Registration of " << name << endl << endl ;
  // Add creator into the factory of Sensors
  Registry::get().add(name, creator) ;
}

}








