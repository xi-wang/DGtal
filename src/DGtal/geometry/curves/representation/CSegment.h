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
 * @file CSegment.h
 * @author Tristan Roussillon (\c tristan.roussillon@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/08/31
 *
 * Header file for concept CSegment.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(CSegment_RECURSES)
#error Recursive header files inclusion detected in CSegment.h
#else // defined(CSegment_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CSegment_RECURSES

#if !defined CSegment_h
/** Prevents repeated inclusion of headers. */
#define CSegment_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "boost/concept_check.hpp"
#include "DGtal/base/ConceptUtils.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class CSegment
  /**
Description of \b concept '\b CSegment' <p>
     @ingroup Concepts
     @brief Aim: Defines the concept describing a segment,
    ie. a valid and not empty range.

 ### Refinement of boost::DefaultConstructible<T>, boost::CopyConstructible<T>, boost::Assignable<T>, boost::EqualityComparable<T>

 ### Associated types :
    - ConstIterator, the type used to iterate over the
    elements of the segment, a model of bidirectional iterator

 ### Notation
     - \t X : A type that is a model of CSegment
     - \t x, \t y : object of type X

 ### Valid expressions and semantics
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
        <td class=CName> begin method  </td>
        <td class=CExpression> x.begin()     </td>
        <td class=CRequirements>    </td>
        <td class=CReturnType> ConstIterator     </td>
        <td class=CPrecondition>    </td>
        <td class=CSemantics> provides an iterator on the first element of the segment      </td>
        <td class=CPostCondition>       </td>
        <td class=CComplexity> O(1)     </td>
      </tr>
      <tr>
        <td class=CName> end method  </td>
        <td class=CExpression> x.end()     </td>
        <td class=CRequirements>    </td>
        <td class=CReturnType> ConstIterator     </td>
        <td class=CPrecondition>    </td>
        <td class=CSemantics> past-the-end value      </td>
        <td class=CPostCondition>       </td>
        <td class=CComplexity> O(1)     </td>
      </tr>

     </table>

 ### Invariants###
     The range [x.begin(),x.end()) is valid (x.end() is reachable from x.begin())
     and not empty (x.begin() != x.end()).

 ### Models###

 ### Notes###

A class of segments @f$ \Sigma_P @f$ is a set of segments 
such that for each segment of the set, 
a given predicate @f$ P @f$ is true: 
@f$ \forall s \in \Sigma_P,  P(s) = \text{true} @f$.

Segment computers, which refines CSegment, are segment
that can control their own extension so that a given 
predicate remains true. 


@tparam T the type that should be a model of CSegment.
   */
  template <typename T>
  struct CSegment : boost::DefaultConstructible<T>, boost::CopyConstructible<T>, boost::Assignable<T>, boost::EqualityComparable<T>
  {
    // ----------------------- Concept checks ------------------------------
  public:
    // Inner types
    typedef typename T::ConstIterator ConstIterator;
    //Uncomment if all iterators have been cleaned
    //BOOST_CONCEPT_ASSERT(( boost::BidirectionalIterator<T> ));

    // Methods
    BOOST_CONCEPT_USAGE( CSegment )
    {
      ConceptUtils::sameType( it, myX.begin() );
      ConceptUtils::sameType( it, myX.end() );      
    }
    // ------------------------- Private Datas --------------------------------
  private:
    T myX; // only if T is default constructible.
    ConstIterator it;

    // ------------------------- Internals ------------------------------------
  private:

  }; // end of concept CSegment

} // namespace DGtal

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CSegment_h

#undef CSegment_RECURSES
#endif // else defined(CSegment_RECURSES)
