/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file CDigitalSurfaceTracker.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5127), University of Savoie, France
 *
 * @date 2012/02/02
 *
 * Header file for concept CDigitalSurfaceTracker.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(CDigitalSurfaceTracker_RECURSES)
#error Recursive header files inclusion detected in CDigitalSurfaceTracker.h
#else // defined(CDigitalSurfaceTracker_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CDigitalSurfaceTracker_RECURSES

#if !defined CDigitalSurfaceTracker_h
/** Prevents repeated inclusion of headers. */
#define CDigitalSurfaceTracker_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class CDigitalSurfaceTracker
  /**
Description of \b concept '\b CDigitalSurfaceTracker' <p>
     @ingroup Concepts
     @brief Aim:
     
 ### Refinement of boost_concepts::CopyConstructible
    
 ### Associated types :
    
 ### Notation
     - \t X : A type that is a model of CDigitalSurfaceTracker
     - \t x, \t y : object of type X
    
 ### Definitions
    
 ### Valid expressions and 
     <table> 
      <tr> 
        <td class=CName> \b Name </td> 
        <td class=CExpression> \b Expression </td>
        <td class=CRequirements> \b Type requirements </td> 
        <td class=CReturnType> \b Return type </td>
        <td class=CPrecondition> \b Precondition </td> 
        <td class=CSemantics> \b Semantics </td> 
        <td class=CPostCondition> \b Postcondition </td> 
        <td class=CComplexity> \b Complexity </td>
      </tr>
      <tr> 
        <td class=CName>            </td> 
        <td class=CExpression>      </td>
        <td class=CRequirements>    </td> 
        <td class=CReturnType>      </td>
        <td class=CPrecondition>    </td> 
        <td class=CSemantics>       </td> 
        <td class=CPostCondition>   </td> 
        <td class=CComplexity>      </td>
      </tr>
    
     </table>
    
 ### Invariants###
    
 ### Models###

     A dummy model (for concept checking) is CCDigitalSurfaceTrackerArchetype.

 ### Notes###

@tparam T the type that should be a model of CDigitalSurfaceTracker.
   */
  template <typename T> 
  struct CDigitalSurfaceTracker : boost::CopyConstructible<T>
  {
    // ----------------------- Concept checks ------------------------------
  public:
    // 1. define first provided types (i.e. inner types), like
    typedef typename T::Self Self;
    typedef typename T::DigitalSurfaceContainer DigitalSurfaceContainer;
    typedef typename T::Surfel Surfel;
    // possibly check these types so as to satisfy a concept with
    // BOOST_CONCEPT_ASSERT
    // (( CDigitalSurfaceContainer< DigitalSurfaceContainer > ));
    // To test if two types A and Y are equals, use
    BOOST_STATIC_ASSERT
    ( (ConceptUtils::SameType< Surfel,
       typename DigitalSurfaceContainer::Surfel >::value) );    
    // 2. then check the presence of data members, operators and methods with
    BOOST_CONCEPT_USAGE( CDigitalSurfaceTracker )
    {
      // x.move( Surfel ) should exist.
      myX.move( mySurfel );
      // check const methods.
      checkConstConstraints();
    }
    void checkConstConstraints() const
    {
      // x.surface() const, returns a const DigitalSurfaceContainer &
      ConceptUtils::sameType( myDSC, myX.surface() );
      // x.current() const, returns a Surfel
      ConceptUtils::sameType( mySurfel, myX.current() );
      // x.orthDir() const, returns a Dimension
      ConceptUtils::sameType( myDim, myX.orthDir() );
      // x.adjacent( Surfel&, Dimension, bool ) const, returns a uint8_t
      Surfel modifiableSurfel;
      ConceptUtils::sameType( myInt, 
			      myX.adjacent( modifiableSurfel, myDim, myBool ) );
    }

    // ------------------------- Private Datas --------------------------------
  private:
    T myX; // only if T is default constructible.
    DigitalSurfaceContainer myDSC;
    Surfel mySurfel;
    Dimension myDim;
    bool myBool;
    uint8_t myInt;
    
    // ------------------------- Internals ------------------------------------
  private:
    
  }; // end of concept CDigitalSurfaceTracker
  
} // namespace DGtal

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CDigitalSurfaceTracker_h

#undef CDigitalSurfaceTracker_RECURSES
#endif // else defined(CDigitalSurfaceTracker_RECURSES)
