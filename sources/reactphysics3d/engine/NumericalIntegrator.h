/****************************************************************************
* Copyright (C) 2009      Daniel Chappuis                                  *
****************************************************************************
* This file is part of ReactPhysics3D.                                     *
*                                                                          *
* ReactPhysics3D is free software: you can redistribute it and/or modify   *
* it under the terms of the GNU General Public License as published by     *
* the Free Software Foundation, either version 3 of the License, or        *
* (at your option) any later version.                                      *
*                                                                          *
* ReactPhysics3D is distributed in the hope that it will be useful,        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
* GNU General Public License for more details.                             *
*                                                                          *
* You should have received a copy of the GNU General Public License        *
* along with ReactPhysics3D. If not, see <http://www.gnu.org/licenses/>.   *
***************************************************************************/

#ifndef NUMERICALINTEGRATOR_H
#define NUMERICALINTEGRATOR_H

// Libraries
#include "../body/BodyState.h"
#include "../body/DerivativeBodyState.h"

// Namespace ReactPhysics3D
namespace reactphysics3d {

/*  -------------------------------------------------------------------
    Class NumericalIntegrator :
        This class will be used to solve the differential equation of
        movement by integrating a body state. This integrator implements
        the RK4 integrator.
    -------------------------------------------------------------------
*/
class NumericalIntegrator {
    private :
        DerivativeBodyState evaluate(BodyState& bodyState, const Time& time, const Time& timeStep);     // Compute a derivative body state
        DerivativeBodyState evaluate(BodyState& bodyState, const Time& time,
                                     const Time& timeStep, const BodyState& lastDerivativeBodyState);   // Compute a derivative body state

    public :
        NumericalIntegrator();                                          // Constructor
        NumericalIntegrator(const NumericalIntegrator& integrator);     // Copy-constructor
        virtual ~NumericalIntegrator();                                 // Destructor

        void integrate(BodyState& bodyState, const Time& t, const Time& dt);    // Integrate a body state over time
}

}

#endif